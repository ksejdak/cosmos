////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       21.08.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#include "am335x_uart.h"

namespace Device {

IUART* IUART::create()
{
    return new AM335x_UART();
}

AM335x_UART::AM335x_UART()
{
    init();
}

void AM335x_UART::init()
{

}

} // namespace Device
