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

using namespace Memory;

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
