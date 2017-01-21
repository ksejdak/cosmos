////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       15.08.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef UART_H
#define UART_H

#include <fs/device.h>

namespace Device {

typedef enum {
    UART_DATA_BITS_7,
    UART_DATA_BITS_8,
    UART_DATA_BITS_9
} UARTDataBits_t;

typedef enum {
    UART_STOP_BITS_0_5,
    UART_STOP_BITS_1,
    UART_STOP_BITS_1_5,
    UART_STOP_BITS_2
} UARTStopBits_t;

typedef enum {
    UART_PARTITY_NONE,
    UART_PARTITY_EVEN,
    UART_PARTITY_ODD
} UARTPartity_t;

typedef enum {
    UART_FLOW_CONTROL_NONE,
    UART_FLOW_CONTROL_RTS_CTS,
    UART_FLOW_CONTROL_XON_XOFF
} UARTFlowControl_t;

typedef enum {
    UART_DIRECTION_READ,
    UART_DIRECTION_WRITE,
    UART_DIRECTION_BIDIRECTIONAL
} UARTDirection_t;

typedef enum {
    UART_MODE_SYNCHRONOUS,
    UART_MODE_ASYNCHRONOUS
} UARTMode_t;

class IUART : public Filesystem::Device {
public:
    IUART(int uartNo);

    virtual void reset() = 0;
    virtual void enable() = 0;
    virtual void disable() = 0;

protected:
    int m_uartNo;
};

} // namespace Device

#endif
