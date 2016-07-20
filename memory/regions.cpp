////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       20.07.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#include "regions.h"

#include <os/assert.h>

using namespace Memory;

extern int _memoryRegions_pa;

MemoryRegions::MemoryRegions()
    : regions(nullptr)
    , m_count(0)
{
    regions = (struct MemoryRegionEntry *) &_memoryRegions_pa;

    for (struct MemoryRegionEntry *it = regions; it->totalSize != 0; ++it)
        ++m_count;
}

int MemoryRegions::getCount()
{
    return m_count;
}

uint32_t MemoryRegions::getPhysicalAddress(int index)
{
    os_assert(index < m_count);
    return regions[index].physicalAddress;
}

uint32_t MemoryRegions::getTotalSize(int index)
{
    os_assert(index < m_count);
    return regions[index].totalSize;
}

uint32_t MemoryRegions::getUsedSize(int index)
{
    os_assert(index < m_count);
    return regions[index].usedSize;
}
