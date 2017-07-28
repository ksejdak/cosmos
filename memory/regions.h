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
    uint32_t physicalAddress(int index);
    uint32_t totalSize(int index);
    uint32_t usedSize(int index);

private:
    MemoryRegions();

private:
    struct __attribute__((packed)) MemoryRegionEntry {
        uint32_t physicalAddress;
        uint32_t totalSize;
        uint32_t usedSize;
    };

    struct MemoryRegionEntry *regions;
    int m_count;
};

} // namespace Memory

#endif
