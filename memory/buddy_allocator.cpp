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

using namespace HAL;

namespace Memory {

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
    return nullptr;
}

void BuddyAllocator::release(void *memoryChunk)
{
}

} // namespace Memory
