////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       20.07.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef PAGE_H
#define PAGE_H

#include <os/stdint.h>

namespace Memory {

class PhysicalPage {
public:
    PhysicalPage(uint32_t physicalAddress);

private:
    uint32_t m_physicalAddress;
};

} // namespace Memory

#endif
