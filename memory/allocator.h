////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       21.07.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include "pagepool.h"

#include <os/stdint.h>

namespace Memory {

class IAllocator {
public:
    IAllocator(IPagePool* pagePool);

    virtual void* allocate(uint32_t size) = 0;
    virtual void release(void *memoryChunk) = 0;

protected:
    IPagePool* m_pagePool;
};

} // namespace Memory

#endif
