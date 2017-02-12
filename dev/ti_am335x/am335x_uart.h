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

#include <dev/device_manager.h>
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

typedef enum {
    UART_CONFIG_MODE_A           = 0x80,
    UART_CONFIG_MODE_B           = 0xbf,
    UART_CONFIG_MODE_OPERATIONAL = 0x7f
} AM335x_UARTConfigMode_t;

typedef enum {
    UART_TRIG_GRANULARITY_4 = 0x0,
    UART_TRIG_GRANULARITY_1 = 0x1
} AM335x_UARTTrigGranularity_t;

typedef enum {
    UART_FIFO_TRIG_LEVEL_8  = 0x0,
    UART_FIFO_TRIG_LEVEL_16 = 0x1,
    UART_FIFO_TRIG_LEVEL_56 = 0x2,
    UART_FIFO_TRIG_LEVEL_60 = 0x3
} AM335x_UARTFIFOTrigLevel_t;

typedef enum {
    UART_DMA_DISABLED = 0x0,
    UART_DMA_MODE_1   = 0x1
} AM335x_UARTDMAMode_t;

class AM335x_UART : public IUART {
public:
    AM335x_UART(AM335x_UARTId_t uartNo);

    virtual void init() override;
    virtual void reset();
    virtual void enable() {}
    virtual void disable() {}

    void setBaudRate(unsigned int baudRate);
    void setTriggerGranularity(AM335x_UARTTrigGranularity_t rxGranulatiry, AM335x_UARTTrigGranularity_t txGranulatiry);
    void setTriggerLevels(AM335x_UARTFIFOTrigLevel_t rxLevel, AM335x_UARTFIFOTrigLevel_t txLevel);
    void enableDMA(bool enabled);
    void enableFIFO(bool enabled);

public:
    static constexpr int AM335x_UART_COUNT = 6;

private:
    static int getBaseAddress(int portNo);

    bool enableEnhancements(bool enable);
    bool enableTCRTLRAccess(bool enable);
    uint32_t setConfigMode(AM335x_UARTConfigMode_t mode);

    void initFIFO();

private:
    AM335x_UARTId_t m_uartNo;
    int m_base;
};

template<>
constexpr int DeviceManager<IUART>::getDeviceCount()
{
    return AM335x_UART::AM335x_UART_COUNT;
}

} // namespace Device

#endif
