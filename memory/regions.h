////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       20.07.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef REGIONS_H
#define REGIONS_H

#include <cstdint>

namespace Memory {

class MemoryRegions {
public:
    static MemoryRegions& instance() {
        static MemoryRegions object;
        return object;
    }

    int count();
    std::uint32_t physicalAddress(int index);
    std::uint32_t totalSize(int index);
    std::uint32_t usedSize(int index);

private:
    MemoryRegions();

private:
    typedef struct {
        std::uint32_t physicalAddress;
        std::uint32_t totalSize;
        std::uint32_t usedSize;
    } __attribute__((packed)) MemoryRegionEntry;

    MemoryRegionEntry *m_regions;
    int m_count;
};

} // namespace Memory

#endif
