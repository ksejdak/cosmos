////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       21.07.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#include "allocator.h"

#include <os/assert.h>

// Replace global operator new and delete to use kernel allocator.
void* operator new(unsigned int size)
{
    assert(Memory::dynamicAllocator != nullptr);
    return Memory::dynamicAllocator->allocate(size);
}

void operator delete(void* memoryChunk)
{
    assert(Memory::dynamicAllocator != nullptr);
    Memory::dynamicAllocator->release(memoryChunk);
}

namespace Memory {

IAllocator* staticAllocator = nullptr;
IAllocator* dynamicAllocator = nullptr;

IAllocator::IAllocator(IPagePool* pagePool)
    : m_pagePool(pagePool)
{
}

} // namespace Memory
