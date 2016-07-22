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

namespace Memory {

IAllocator* staticAllocator = nullptr;
IAllocator* dynamicAllocator = nullptr;

IAllocator::IAllocator(IPagePool* pagePool)
    : m_pagePool(pagePool)
{
}

} // namespace Memory
