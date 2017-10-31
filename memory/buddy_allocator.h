////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       21.07.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef BUDDY_ALLOCATOR_H
#define BUDDY_ALLOCATOR_H

#include "allocator.h"
#include "page.h"
#include "pagepool.h"

#include <os/chain.h>
#include <os/pair.h>

#include <cstdint>

namespace Memory {

class MemoryChunk : public os::IChainable<MemoryChunk> {
public:
    MemoryChunk();

    bool checkMagic();
    std::uint32_t virtualAddress();
    void* data();
    std::uint16_t size();
    Page* parentPage();

    void init(Page* parentPage);
    void setVirtualAddress(std::uint32_t virtualAddress);
    void setSize(std::uint32_t size);

    os::pair<MemoryChunk, MemoryChunk> split();

private:
    std::uint32_t m_magic;
    std::uint32_t m_virtualAddress;
    std::uint32_t m_size;
    Page* m_parentPage;
} __attribute__ ((packed));

class BuddyAllocator : public IAllocator {
public:
    BuddyAllocator();

    virtual void* allocate(std::uint32_t size);
    virtual void release(void *memoryChunk);

private:
    bool allocatePage();
    int sizeToFactor(std::uint32_t size);
    std::uint32_t factorToSize(int factor);
    void splitChunk(MemoryChunk* chunk);

private:
    static const int MEMORY_CHUNK_FACTOR = 13;

    os::chain<MemoryChunk> m_freeChunks[MEMORY_CHUNK_FACTOR];
};

} // namespace Memory

#endif
