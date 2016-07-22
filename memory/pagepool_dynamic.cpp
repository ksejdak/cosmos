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

using namespace Memory;

bool DynamicPagePool::init()
{
    return false;
}

PhysicalPage* DynamicPagePool::allocatePage()
{
    return nullptr;
}

void DynamicPagePool::releasePage(PhysicalPage* page)
{
}
