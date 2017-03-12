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
namespace UART {

typedef enum {
    DATA_BITS_5,
    DATA_BITS_6,
    DATA_BITS_7,
    DATA_BITS_8,
} DataBits_t;

typedef enum {
    STOP_BITS_0_5,
    STOP_BITS_1,
    STOP_BITS_1_5,
    STOP_BITS_2
} StopBits_t;

typedef enum {
    PARTITY_NONE,
    PARTITY_EVEN,
    PARTITY_ODD
} Partity_t;

typedef enum {
    FLOW_CONTROL_NONE,
    FLOW_CONTROL_RTS_CTS,
    FLOW_CONTROL_XON_XOFF
} FlowControl_t;

typedef enum {
    DIRECTION_READ,
    DIRECTION_WRITE,
    DIRECTION_BIDIRECTIONAL
} Direction_t;

typedef enum {
    MODE_SYNCHRONOUS,
    MODE_ASYNCHRONOUS
} TransmissionMode_t;

class IUART : public Filesystem::Device {
public:
    virtual void reset() = 0;
    virtual void enable() = 0;
    virtual void disable() = 0;

    virtual bool setDataBits(DataBits_t dataBits) = 0;
    virtual bool setStopBits(StopBits_t stopBits) = 0;
    virtual bool setPartity(Partity_t partity) = 0;
    virtual bool setFlowControl(FlowControl_t flowControl) = 0;
    virtual bool setDirection(Direction_t direction) = 0;
    virtual bool setTransmissionMode(TransmissionMode_t transmissionMode) = 0;

    virtual uint8_t read() = 0;
    virtual bool write(uint8_t value) = 0;
};

} // namespace UART
} // namespace Device

#endif
