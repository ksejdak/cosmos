////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       17.07.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#include <memory/allocator.h>
#include <memory/regions.h>

#include <memory/page.h>

using namespace Memory;

int main()
{
    IAllocator::init();

    MemoryRegions& regions = MemoryRegions::instance();
    regions.count();

    Page* page = new Page();
    delete page;

    return 0;
}
