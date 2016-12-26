////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       21.08.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#include "beaglebone_black.h"

#include <core/console.h>

namespace Board {

IBoard* IBoard::create()
{
    return new BeagleBoneBlack();
}

BeagleBoneBlack::BeagleBoneBlack()
{
    m_name = "BeagleBone Black";
    m_vendor = "Texas Instruments";
    m_version = "1.0";
}

bool BeagleBoneBlack::initDevice()
{
    // Initialize console on UART0.
    // - init GPIO1 (// tx=1.11  rx=1.10)
    // GPIO::init(GPIO_1)

    return true;
}

} // namespace Board
