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

#include <dev/device_manager.h>
#include <dev/uart.h>

namespace Device {
namespace UART {

typedef enum {
    UART_0,
    UART_1,
    UART_2,
    UART_3,
    UART_4,
    UART_5
} UARTId_t;

typedef enum {
    CONFIG_MODE_A           = 0x80,
    CONFIG_MODE_B           = 0xbf,
    CONFIG_MODE_OPERATIONAL = 0x7f
} ConfigMode_t;

typedef enum {
    TRIG_GRANULARITY_4 = 0x0,
    TRIG_GRANULARITY_1 = 0x1
} TrigGranularity_t;

typedef enum {
    FIFO_TRIG_LEVEL_8  = 0x0,
    FIFO_TRIG_LEVEL_16 = 0x1,
    FIFO_TRIG_LEVEL_56 = 0x2,
    FIFO_TRIG_LEVEL_60 = 0x3
} FIFOTrigLevel_t;

typedef enum {
    MODE_UART_16x,
    MODE_SIR,
    MODE_UART_16x_AUTOBAUD,
    MODE_UART_13x,
    MODE_MIR,
    MODE_FIR,
    MODE_CIR,
    MODE_DISABLE
} OperatingMode_t;

class AM335x_UART : public IUART {
public:
    AM335x_UART(UARTId_t uartNo);

    // Initialization.
    virtual void init() override;
    virtual void reset();
    virtual void enable() {}
    virtual void disable() {}

    // Configuration.
    virtual void setBaudRate(unsigned int baudRate);
    virtual bool setDataBits(DataBits_t dataBits);
    virtual bool setStopBits(StopBits_t stopBits);
    virtual bool setPartity(Partity_t partity);
    virtual bool setFlowControl(FlowControl_t flowControl);
    virtual bool setDirection(Direction_t direction);
    virtual bool setTransmissionMode(TransmissionMode_t transmissionMode);
    void enableDMA(bool enabled);
    void enableFIFO(bool enabled);
    void clearRxFIFO();
    void clearTxFIFO();

    // I/O operations.
    virtual size_t read(void* buff, size_t size) override;
    virtual size_t write(const void* buff, size_t size) override;
    virtual uint8_t readChar();
    virtual bool writeChar(uint8_t value);

public:
    static constexpr int PORT_COUNT     = 6;
    static constexpr int INPUT_CLOCK_HZ = 48 * 1000 * 1000;

private:
    static int getBaseAddress(int portNo);

    uint16_t setConfigMode(ConfigMode_t mode);
    OperatingMode_t setOperatingMode(OperatingMode_t mode);
    void restoreLCR(uint16_t value);
    bool enableEnhancements(bool enable);
    bool enableTCRTLRAccess(bool enable);
    void setTriggerGranularity(TrigGranularity_t rxGranulatiry, TrigGranularity_t txGranulatiry);
    void setTriggerLevels(FIFOTrigLevel_t rxLevel, FIFOTrigLevel_t txLevel);
    void initFIFO();

private:
    UARTId_t m_uartNo;
    int m_base;
};

} // namespace UART

template<>
constexpr int DeviceManager<UART::IUART>::getDeviceCount()
{
    return UART::AM335x_UART::PORT_COUNT;
}

} // namespace Device

#endif
