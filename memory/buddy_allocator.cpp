////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       21.07.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#include "buddy_allocator.h"

#include <hal/mmu.h>

#include <cassert>

using namespace HAL;

namespace Memory {

static const std::uint32_t MEMORY_CHUNK_MAGIC = 0x08081990;

MemoryChunk::MemoryChunk()
    : m_magic(0)
    , m_virtualAddress(0)
    , m_size(0)
    , m_parentPage(nullptr)
{
}

bool MemoryChunk::checkMagic()
{
    return (m_magic == MEMORY_CHUNK_MAGIC);
}

std::uint32_t MemoryChunk::virtualAddress()
{
    return m_virtualAddress;
}

void* MemoryChunk::data()
{
    return reinterpret_cast<void*>(m_virtualAddress + sizeof(MemoryChunk));
}

std::uint16_t MemoryChunk::size()
{
    return m_size;
}

Page* MemoryChunk::parentPage()
{
    return m_parentPage;
}

void MemoryChunk::init(Page* parentPage)
{
    m_magic = MEMORY_CHUNK_MAGIC;
    m_parentPage = parentPage;
}

void MemoryChunk::setVirtualAddress(std::uint32_t virtualAddress)
{
    m_virtualAddress = virtualAddress;
}

void MemoryChunk::setSize(std::uint32_t size)
{
    m_size = size;
}

os::pair<MemoryChunk, MemoryChunk> MemoryChunk::split()
{
    std::uint32_t newSize = m_size / 2;

    MemoryChunk* first = reinterpret_cast<MemoryChunk*>(m_virtualAddress);
    first->init(m_parentPage);
    first->setVirtualAddress(m_virtualAddress);
    first->setSize(newSize);

    MemoryChunk* second = reinterpret_cast<MemoryChunk*>(m_virtualAddress + newSize);
    second->init(m_parentPage);
    second->setVirtualAddress(m_virtualAddress + newSize);
    second->setSize(newSize);

    return os::pair<MemoryChunk, MemoryChunk>(first, second);
}

void IAllocator::init()
{
    static BuddyAllocator buddyAllocator;
    kernelAllocator = &buddyAllocator;
    PagePool::instance().init();
}

BuddyAllocator::BuddyAllocator()
    : IAllocator(PagePool::instance())
{
}

void* BuddyAllocator::allocate(std::uint32_t size)
{
    if (size == 0)
        return nullptr;

    std::uint32_t requiredSize = size + sizeof(MemoryChunk);
    int factor = sizeToFactor(requiredSize);

    while (true) {
        // Find proper chunk from the free chunks list.
        bool chunkAvailable = false;

        for (int i = factor; i < MEMORY_CHUNK_FACTOR; ++i) {
            if (m_freeChunks[i].size() == 0) {
                // There is no chunk with given factor.
                continue;
            }

            if (factorToSize(i) / 2 >= requiredSize) {
                // Smallest suitable chunk can be splitted to avoid fragmentation.
                splitChunk(m_freeChunks[i].front());
                chunkAvailable = true;
                break;
            }

            // Proper chunk found.
            return m_freeChunks[i].pop_front()->data();
        }

        if (chunkAvailable)
            continue;

        // No suitable chunk was found. Allocate new page.
        if (!allocatePage())
            return nullptr;
    }

    return nullptr;
}

void BuddyAllocator::release(void *memoryChunk)
{
    if (memoryChunk == nullptr)
        return;

    MemoryChunk* chunk = reinterpret_cast<MemoryChunk*>((char*) memoryChunk - sizeof(MemoryChunk));
    assert(chunk->checkMagic());
}

bool BuddyAllocator::allocatePage()
{
    auto page = m_pagePool.allocatePages(1);
    if (page.size() == 0)
        return false;

    /// @todo Map this page into kernel address space.
    // void* pageVirtualAddress = IMMU::map(page.front());
    void* pageVirtualAddress = reinterpret_cast<void*>(page.front()->physicalAddress());

    MemoryChunk* newChunk = reinterpret_cast<MemoryChunk*>(pageVirtualAddress);
    newChunk->init(page.front());
    newChunk->setVirtualAddress((std::uint32_t) pageVirtualAddress);
    newChunk->setSize(IMMU::pageSize());

    // Insert this chunk to the list of free chunks.
    m_freeChunks[sizeToFactor(newChunk->size())].push_back(newChunk);

    return true;
}

int BuddyAllocator::sizeToFactor(std::uint32_t size)
{
    for (int i = 0; i < MEMORY_CHUNK_FACTOR; ++i) {
        if (factorToSize(i) >= size)
            return i;
    }

    return -1;
}

std::uint32_t BuddyAllocator::factorToSize(int factor)
{
    return (1 << factor);
}

void BuddyAllocator::splitChunk(MemoryChunk* chunk)
{
    int factor = sizeToFactor(chunk->size());
    int index = m_freeChunks[factor].indexOf(chunk);
    assert(index != -1);

    auto chunkHalfs = chunk->split();
    m_freeChunks[factor].remove(index);
    m_freeChunks[factor - 1].push_back(chunkHalfs.first());
    m_freeChunks[factor - 1].push_back(chunkHalfs.second());
}

} // namespace Memory
