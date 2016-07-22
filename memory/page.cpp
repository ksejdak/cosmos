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

using namespace Memory;

void* PhysicalPage::operator new(unsigned int size)
{
    return nullptr;
}

PhysicalPage::PhysicalPage(uint32_t physicalAddress)
    : m_physicalAddress(physicalAddress)
    , m_occupied(false)
{
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
