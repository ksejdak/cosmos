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

static const uint32_t MEMORY_CHUNK_DESC_MAGIC = 0x08081990;

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

    uint32_t totalSize = size + sizeof(MemoryChunkDesc);
    unsigned int wholePages = totalSize / IMemoryManagementUnit::getPageSize();
    uint32_t remainingSize = totalSize - (wholePages * IMemoryManagementUnit::getPageSize());

    return nullptr;
}

void BuddyAllocator::release(void *memoryChunk)
{
    if (memoryChunk == nullptr)
        return;

    MemoryChunkDesc* desc = reinterpret_cast<MemoryChunkDesc*>((char*) memoryChunk - sizeof(MemoryChunkDesc));
    assert(desc->magic == MEMORY_CHUNK_DESC_MAGIC);
}

} // namespace Memory
