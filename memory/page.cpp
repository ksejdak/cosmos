////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       20.07.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#include "page.h"

namespace Memory {

Page::Page()
    : Page(0)
{
}

Page::Page(uint32_t physicalAddress)
    : m_physicalAddress(physicalAddress)
    , m_occupied(false)
{
}

uint32_t Page::physicalAddress()
{
    return m_physicalAddress;
}

void Page::setPhysicalAddress(uint32_t physicalAddress)
{
    m_physicalAddress = physicalAddress;
}

bool Page::isOccupied()
{
    return m_occupied;
}

void Page::setOccupied()
{
    m_occupied = true;
}

void Page::setFree()
{
    m_occupied = false;
}

} // namespace Memory
