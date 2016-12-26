////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       21.08.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AM335X_CLOCK_H
#define AM335X_CLOCK_H

#include "am335x_uart.h"

namespace Device {

class AM335x_Clock {
public:
    AM335x_Clock();

    bool initUart(AM335x_UARTId_t id);

private:
    static bool m_initialized;
};

} // namespace Device

#endif
