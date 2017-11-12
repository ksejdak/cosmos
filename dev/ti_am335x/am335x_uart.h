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

#ifndef AM335X_UART_H
#define AM335X_UART_H

#include <dev/device_manager.h>
#include <dev/uart.h>

namespace Device::UART {

enum class UARTId {
    _0,
    _1,
    _2,
    _3,
    _4,
    _5
};

enum class ConfigMode {
    A           = 0x80,
    B           = 0xbf,
    Operational = 0x7f
};

enum class TrigGranularity {
    _1 = 0x1
};

enum class FIFOTrigLevel {
    _8  = 0x0
};

enum class OperatingMode {
    Uart16x = 0x0,
    Disable = 0x7
};

class AM335x_UART : public IUART<6> {
public:
    using id_type = UARTId;
    friend class DeviceManager<AM335x_UART>;

public:
    // Initialization.
    virtual void init() override;
    virtual void reset();
    virtual void enable() {}
    virtual void disable() {}

    // Configuration.
    virtual void setBaudRate(unsigned int baudRate);
    virtual bool setDataBits(DataBits dataBits);
    virtual bool setStopBits(StopBits stopBits);
    virtual bool setPartity(Partity partity);
    virtual bool setFlowControl(FlowControl flowControl);
    virtual bool setDirection(Direction direction);
    virtual bool setTransmissionMode(TransmissionMode mode);
    void enableDMA(bool enabled);
    void enableFIFO(bool enabled);
    void clearRxFIFO();
    void clearTxFIFO();
    bool isTxFIFOEmpty();

    // I/O operations.
    virtual std::size_t read(void* buff, std::size_t size) override;
    virtual std::size_t write(const void* buff, std::size_t size) override;
    virtual std::uint8_t readChar();
    virtual bool writeChar(std::uint8_t value);

private:
    AM335x_UART();

    std::uint16_t setConfigMode(ConfigMode mode);
    OperatingMode setOperatingMode(OperatingMode mode);
    void restoreLCR(std::uint16_t value);
    bool enableEnhancements(bool enable);
    void setTriggerGranularity(TrigGranularity rxGranulatiry, TrigGranularity txGranulatiry);
    void setTriggerLevels(FIFOTrigLevel rxLevel, FIFOTrigLevel txLevel);
    void initFIFO();

private:
    UARTId m_id;
    int m_base;
    bool m_fifoEnabled;

    static constexpr int INPUT_CLOCK_HZ = 48 * 1000 * 1000;
    static int m_nextId;
};

} // namespace Device::UART

#endif
