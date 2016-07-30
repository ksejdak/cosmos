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
#include "pagepool_dynamic.h"
#include "pagepool_static.h"

#include <hal/mmu.h>
#include <os/assert.h>

using namespace HAL;

namespace Memory {

static const uint32_t MEMORY_CHUNK_MAGIC = 0x08081990;

MemoryChunk::MemoryChunk(uint32_t virtualAddress, uint16_t size)
    : m_magic(MEMORY_CHUNK_MAGIC)
    , m_virtualAddress(virtualAddress)
    , m_size(size)
{
}

MemoryChunk::MemoryChunk(void* pointer)
{
    MemoryChunk* chunk = reinterpret_cast<MemoryChunk*>(pointer);

    m_magic = chunk->getMagic();
    m_virtualAddress = chunk->getVirtualAddress();
    m_size = chunk->getSize();
}

uint32_t MemoryChunk::getMagic()
{
    return m_magic;
}

uint32_t MemoryChunk::getVirtualAddress()
{
    return m_virtualAddress;
}

uint16_t MemoryChunk::getSize()
{
    return m_size;
}

void IAllocator::init()
{
    static StaticPagePool staticPool;
    static BuddyAllocator staticBuddy(&staticPool);
    staticAllocator = &staticBuddy;

    static DynamicPagePool dynamicPool;
    static BuddyAllocator dynamicBuddy(&dynamicPool);
    dynamicAllocator = &dynamicBuddy;
}

BuddyAllocator::BuddyAllocator(IPagePool* pagePool)
    : IAllocator(pagePool)
{
}

void* BuddyAllocator::allocate(uint32_t size)
{
    if (size == 0)
        return nullptr;

    // Find chunk size, that will suit best for this allocation.
    uint32_t remainingSize = size;
    do {
        // Each chunk will need its descriptor, so add it to allocation size.
        remainingSize += sizeof(MemoryChunk);
        if (remainingSize > IMMU::getPageSize()) {
            m_allocatedPages.insert(m_pagePool->allocatePages(1));

        }


        for (int i = 0; i < MEMORY_CHUNK_FACTOR; ++i) {
            int chunkSize = 1 << i;
            if (chunkSize <= remainingSize) {

                return cos;
            }
        }
    }
    while (remainingSize > 0);

    return nullptr;
}

void BuddyAllocator::release(void *memoryChunk)
{
    if (memoryChunk == nullptr)
        return;

    MemoryChunk* chunk = reinterpret_cast<MemoryChunk*>((char*) memoryChunk - sizeof(MemoryChunk));
    assert(chunk->getMagic() == MEMORY_CHUNK_MAGIC);
}

} // namespace Memory
