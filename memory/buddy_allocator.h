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
#include <os/stdint.h>

namespace Memory {

class MemoryChunk :  public os::IChainable<MemoryChunk>  {
public:
    MemoryChunk(uint32_t virtualAddress, uint16_t size);
    MemoryChunk(void* pointer);

    uint32_t getMagic();
    uint32_t getVirtualAddress();
    uint16_t getSize();

private:
    uint32_t m_magic;
    uint32_t m_virtualAddress;
    uint16_t m_size;
} __attribute__ ((packed));

class BuddyAllocator : public IAllocator {
public:
    BuddyAllocator(IPagePool* pagePool);

    virtual void* allocate(uint32_t size);
    virtual void release(void *memoryChunk);

private:
    static const int MEMORY_CHUNK_FACTOR = 13;

    os::chain<Page> m_allocatedPages;
    os::chain<MemoryChunk> m_freeChunks[MEMORY_CHUNK_FACTOR];
};

} // namespace Memory

#endif
