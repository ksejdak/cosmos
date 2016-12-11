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

#include <dev/uart.h>

namespace Device {

typedef enum {
    UART0,
    UART1,
    UART2,
    UART3,
    UART4,
    UART5
} AM335x_UARTId_t;

class AM335x_UART : public IUART {
public:
    AM335x_UART(AM335x_UARTId_t id);

private:
    void init();

private:
    AM335x_UARTId_t m_id;
};

} // namespace Device

#endif
