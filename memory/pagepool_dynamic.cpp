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

os::chain<Page> DynamicPagePool::allocatePages(unsigned int count)
{
    return os::chain<Page>();
}

void DynamicPagePool::releasePages(os::chain<Page>& pages)
{
}

} // namespace Memory
