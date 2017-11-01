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

enum class DataBits {
    _5,
    _6,
    _7,
    _8,
};

enum class StopBits{
    _0_5,
    _1,
    _1_5,
    _2
};

enum class Partity {
    None,
    Even,
    Odd
};

enum class FlowControl {
    None,
    RtsCts,
    XonXoff
};

enum class Direction {
    Read,
    Write,
    Bidirectional
};

 enum class TransmissionMode {
    Synchronous,
    Asynchronous
};

class IUART : public Filesystem::Device {
public:
    // Initialization.
    virtual void reset() = 0;
    virtual void enable() = 0;
    virtual void disable() = 0;

    // Configuration
    virtual void setBaudRate(unsigned int baudRate) = 0;
    virtual bool setDataBits(DataBits dataBits) = 0;
    virtual bool setStopBits(StopBits stopBits) = 0;
    virtual bool setPartity(Partity partity) = 0;
    virtual bool setFlowControl(FlowControl flowControl) = 0;
    virtual bool setDirection(Direction direction) = 0;
    virtual bool setTransmissionMode(TransmissionMode mode) = 0;

    // I/O operations.
    virtual std::uint8_t readChar() = 0;
    virtual bool writeChar(std::uint8_t value) = 0;
};

} // namespace UART
} // namespace Device

#endif
