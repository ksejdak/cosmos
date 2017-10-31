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

#include <cassert>

extern int _memoryRegions_pa;

namespace Memory {

MemoryRegions::MemoryRegions()
    : m_regions(reinterpret_cast<MemoryRegionEntry *>(&_memoryRegions_pa))
    , m_count(0)
{
    for (auto it = m_regions; it->totalSize != 0; ++it)
        ++m_count;
}

int MemoryRegions::count()
{
    return m_count;
}

std::uint32_t MemoryRegions::physicalAddress(int index)
{
    assert(index < m_count);
    return m_regions[index].physicalAddress;
}

std::uint32_t MemoryRegions::totalSize(int index)
{
    assert(index < m_count);
    return m_regions[index].totalSize;
}

std::uint32_t MemoryRegions::usedSize(int index)
{
    assert(index < m_count);
    return m_regions[index].usedSize;
}

} // namespace Memory
