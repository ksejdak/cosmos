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
    assert(Memory::kernelAllocator != nullptr);
    return Memory::kernelAllocator->allocate(size);
}

void operator delete(void* memoryChunk)
{
    assert(Memory::kernelAllocator != nullptr);
    Memory::kernelAllocator->release(memoryChunk);
}

void operator delete(void*, unsigned int)
{
    // TODO: Implement.
}

namespace Memory {

IAllocator* kernelAllocator = nullptr;

IAllocator::IAllocator(PagePool& pagePool)
    : m_pagePool(pagePool)
{
}

} // namespace Memory
