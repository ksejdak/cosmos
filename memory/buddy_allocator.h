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
    uint32_t virtualAddress();
    void* data();
    uint16_t size();
    Page* parentPage();

    void init(Page* parentPage);
    void setVirtualAddress(uint32_t virtualAddress);
    void setSize(uint32_t size);

    os::pair<MemoryChunk, MemoryChunk> split();

private:
    uint32_t m_magic;
    uint32_t m_virtualAddress;
    uint32_t m_size;
    Page* m_parentPage;
} __attribute__ ((packed));

class BuddyAllocator : public IAllocator {
public:
    BuddyAllocator();

    virtual void* allocate(uint32_t size);
    virtual void release(void *memoryChunk);

private:
    bool allocatePage();
    int sizeToFactor(uint32_t size);
    uint32_t factorToSize(int factor);
    void splitChunk(MemoryChunk* chunk);

private:
    static const int MEMORY_CHUNK_FACTOR = 13;

    os::chain<MemoryChunk> m_freeChunks[MEMORY_CHUNK_FACTOR];
};

} // namespace Memory

#endif
