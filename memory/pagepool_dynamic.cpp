////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       21.07.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#include "pagepool_dynamic.h"

namespace Memory {

bool DynamicPagePool::init()
{
    return false;
}

os::chain<PhysicalPage> DynamicPagePool::allocatePages(unsigned int count)
{
    return os::chain<PhysicalPage>();
}

void DynamicPagePool::releasePages(os::chain<PhysicalPage>& pages)
{
}

} // namespace Memory
