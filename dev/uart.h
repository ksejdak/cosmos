////////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2017, Kuba Sejdak <kuba.sejdak@gmail.com>
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
////////////////////////////////////////////////////////////////////////////////////

#ifndef UART_H
#define UART_H

#include <fs/device.h>

namespace Device::UART {

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

template <int N>
class IUART : public Filesystem::Device<N> {
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

} // namespace Device::UART

#endif
