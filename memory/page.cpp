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
#include "buddy_allocator.h"
#include "pagepool_static.h"

namespace Memory {

void* PhysicalPage::operator new(unsigned int size)
{
    return nullptr;
}

void PhysicalPage::operator delete(void* pointer)
{
}

PhysicalPage::PhysicalPage()
    : PhysicalPage(0)
{
}

PhysicalPage::PhysicalPage(uint32_t physicalAddress)
    : m_physicalAddress(physicalAddress)
    , m_occupied(false)
{
}

uint32_t PhysicalPage::getPhysicalAddress()
{
    return m_physicalAddress;
}

bool PhysicalPage::isOccupied()
{
    return m_occupied;
}

void PhysicalPage::setOccupied()
{
    m_occupied = true;
}

void PhysicalPage::setFree()
{
    m_occupied = false;
}

} // namespace Memory
