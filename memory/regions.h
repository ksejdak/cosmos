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

#include <os/stdint.h>

namespace Memory {

class MemoryRegions {
public:
    static MemoryRegions& instance() {
        static MemoryRegions object;
        return object;
    }

    int getCount();
    uint32_t getPhysicalAddress(int index);
    uint32_t getTotalSize(int index);
    uint32_t getUsedSize(int index);

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
