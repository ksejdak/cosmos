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
    static void init();

    virtual void* allocate(uint32_t size) = 0;
    virtual void release(void *memoryChunk) = 0;

protected:
    IAllocator(IPagePool* pagePool);

protected:
    IPagePool* m_pagePool;
};

extern IAllocator* staticAllocator;
extern IAllocator* dynamicAllocator;

} // namespace Memory

#endif
