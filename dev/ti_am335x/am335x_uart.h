////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       21.08.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AM335X_UART_H
#define AM335X_UART_H

#include "am335x_uart_regs.h"

#include <dev/uart.h>

namespace Device {

typedef enum {
    AM335x_UART_0,
    AM335x_UART_1,
    AM335x_UART_2,
    AM335x_UART_3,
    AM335x_UART_4,
    AM335x_UART_5
} AM335x_UARTId_t;

class AM335x_UART : public IUART {
public:
    AM335x_UART(AM335x_UARTId_t uartNo);

    virtual void init();
    virtual void reset();
    virtual void enable();
    virtual void disable();

private:
    int m_base;
};

class AM335x_UARTManager : public IUARTManager {
public:
    AM335x_UARTManager();

    virtual IUART& getUART(int uartNo);

private:
    static const int AM335x_UART_COUNT = 6;

    AM335x_UART m_uarts[AM335x_UART_COUNT];
};

} // namespace Device

#endif
