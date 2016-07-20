////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       17.07.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#include <memory/regions.h>

using namespace Memory;

int main()
{
    MemoryRegions& regions = MemoryRegions::instance();
    int n = regions.getCount();

    return 0;
}
