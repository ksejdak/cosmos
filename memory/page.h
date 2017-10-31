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

#include <os/chain.h>

#include <cstdint>

namespace Memory {

class Page : public os::IChainable<Page> {
public:
    Page();
    Page(std::uint32_t physicalAddress);

    std::uint32_t physicalAddress();
    void setPhysicalAddress(std::uint32_t physicalAddress);

    bool isOccupied();
    void setOccupied();
    void setFree();

private:
    std::uint32_t m_physicalAddress;
    bool m_occupied;
};

} // namespace Memory

#endif
