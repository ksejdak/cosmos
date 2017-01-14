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
#include "am335x_clock_regs_per.h"
#include "am335x_clock_regs_wkup.h"

#include <os/assert.h>

namespace Device {

IUARTManager* IUARTManager::create()
{
    return new AM335x_UARTManager();
}

int IUARTManager::getBaseAddress(int uartNo)
{
    switch (uartNo) {
        case AM335x_UART_0:     return UART_0_BASE;
        case AM335x_UART_1:     return UART_1_BASE;
        case AM335x_UART_2:     return UART_2_BASE;
        case AM335x_UART_3:     return UART_3_BASE;
        case AM335x_UART_4:     return UART_4_BASE;
        case AM335x_UART_5:     return UART_5_BASE;
    }

    return -1;
}

AM335x_UART::AM335x_UART(AM335x_UARTId_t uartNo)
    : IUART(uartNo)
    , m_base(IUARTManager::getBaseAddress(uartNo))
{
    // TODO:
    // - register IRQ handler for given UART
    // - register /dev/uartX device.
}

void AM335x_UART::init()
{
    if (m_initialized)
        return;
}

void AM335x_UART::reset()
{
}

void AM335x_UART::enable()
{
}

void AM335x_UART::disable()
{
}

AM335x_UARTManager::AM335x_UARTManager()
    : m_uarts{ AM335x_UART_0,
               AM335x_UART_1,
               AM335x_UART_2,
               AM335x_UART_3,
               AM335x_UART_4,
               AM335x_UART_5 }
{
    // TODO:
    // - check MVR register.
    // - register /dev/uart-control device.
}

IUART& AM335x_UARTManager::getUART(int uartNo)
{
    assert(uartNo >= AM335x_UART_0 && uartNo <= AM335x_UART_5);
    return m_uarts[uartNo];
}

} // namespace Device
