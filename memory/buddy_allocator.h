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
#include "pagepool.h"

namespace Memory {

class BuddyAllocator : public IAllocator {
public:
    BuddyAllocator(IPagePool* pagePool);

    virtual void* allocate(uint32_t size);
    virtual void release(void *memoryChunk);
};

} // namespace Memory

#endif
