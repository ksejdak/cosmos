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
#include "am335x_uart_regs.h"

#include <cassert>

namespace Device {

template <>
UART::IUART& DeviceManager<UART::IUART>::getDevice(int id)
{
    using namespace UART;

    static AM335x_UART uarts[getDeviceCount()] {
        UARTId::_0,
        UARTId::_1,
        UARTId::_2,
        UARTId::_3,
        UARTId::_4,
        UARTId::_5
    };

    assert(id >= 0 && id < getDeviceCount());
    return uarts[id];
}

namespace UART {


int AM335x_UART::getBaseAddress(UARTId portNo)
{
    switch (portNo) {
        case UARTId::_0:    return UART_0_BASE;
        case UARTId::_1:    return UART_1_BASE;
        case UARTId::_2:    return UART_2_BASE;
        case UARTId::_3:    return UART_3_BASE;
        case UARTId::_4:    return UART_4_BASE;
        case UARTId::_5:    return UART_5_BASE;
    }

    return -1;
}

AM335x_UART::AM335x_UART(UARTId uartNo)
    : m_uartNo(uartNo)
    , m_base(getBaseAddress(uartNo))
    , m_fifoEnabled(false)
{
    // TODO:
    // - register IRQ handler for given UART
    // - register /dev/uartX device.
}

void AM335x_UART::init()
{
    using namespace Clock;

    if (m_initialized)
        return;

    // Enable interface and functional clocks.
    switch (m_uartNo) {
        case UARTId::_0:
            CM_PER_L3_CLKCTRL->MODULEMODE = CM_PER_MODULEMODE_ENABLE;
            while (CM_PER_L3_CLKCTRL->MODULEMODE != CM_PER_MODULEMODE_ENABLE);
            CM_PER_L3_INSTR_CLKCTRL->MODULEMODE = CM_PER_MODULEMODE_ENABLE;
            while (CM_PER_L3_INSTR_CLKCTRL->MODULEMODE != CM_PER_MODULEMODE_ENABLE);
            CM_PER_L3_CLKSTCTRL->CLKTRCTRL = CM_PER_CLKTRCTRL_SW_WKUP;
            while (CM_PER_L3_CLKSTCTRL->CLKTRCTRL != CM_PER_CLKTRCTRL_SW_WKUP);
            CM_PER_OCPWP_L3_CLKSTCTRL->CLKTRCTRL = CM_PER_CLKTRCTRL_SW_WKUP;
            while (CM_PER_OCPWP_L3_CLKSTCTRL->CLKTRCTRL != CM_PER_CLKTRCTRL_SW_WKUP);
            CM_PER_L3S_CLKSTCTRL->CLKTRCTRL = CM_PER_CLKTRCTRL_SW_WKUP;
            while (CM_PER_L3S_CLKSTCTRL->CLKTRCTRL != CM_PER_CLKTRCTRL_SW_WKUP);
            while (CM_PER_L3_CLKCTRL->IDLEST != CM_PER_IDLEST_FUNCTIONAL);
            while (CM_PER_L3_INSTR_CLKCTRL->IDLEST != CM_PER_IDLEST_FUNCTIONAL);
            while (CM_PER_L3_CLKSTCTRL->CLKACTIVITY_L3_GCLK != CM_PER_CLK_ACTIVE);
            while (CM_PER_OCPWP_L3_CLKSTCTRL->CLKACTIVITY_OCPWP_L3_GCLK != CM_PER_CLK_ACTIVE);
            while (CM_PER_L3S_CLKSTCTRL->CLKACTIVITY_L3S_GCLK != CM_PER_CLK_ACTIVE);
            CM_WKUP_CONTROL_CLKCTRL->MODULEMODE = CM_WKUP_MODULEMODE_ENABLE;
            while (CM_WKUP_CONTROL_CLKCTRL->MODULEMODE != CM_WKUP_MODULEMODE_ENABLE);
            CM_WKUP_CLKSTCTRL->CLKTRCTRL = CM_WKUP_CLKTRCTRL_SW_WKUP;
            while (CM_WKUP_CLKSTCTRL->CLKTRCTRL != CM_WKUP_CLKTRCTRL_SW_WKUP);
            CM_L3_AON_CLKSTCTRL->CLKTRCTRL = CM_WKUP_CLKTRCTRL_SW_WKUP;
            while (CM_L3_AON_CLKSTCTRL->CLKTRCTRL != CM_WKUP_CLKTRCTRL_SW_WKUP);
            CM_WKUP_UART0_CLKCTRL->MODULEMODE = CM_WKUP_MODULEMODE_ENABLE;
            while (CM_WKUP_UART0_CLKCTRL->MODULEMODE != CM_WKUP_MODULEMODE_ENABLE);
            while (CM_WKUP_CONTROL_CLKCTRL->IDLEST != CM_WKUP_IDLEST_FUNCTIONAL);
            while (CM_L3_AON_CLKSTCTRL->CLKACTIVITY_L3_AON_GCLK != CM_WKUP_CLK_ACTIVE);
            while (CM_WKUP_L4WKUP_CLKCTRL->IDLEST != CM_WKUP_IDLEST_FUNCTIONAL);
            while (CM_WKUP_CLKSTCTRL->CLKACTIVITY_L4_WKUP_GCLK != CM_WKUP_CLK_ACTIVE);
            while (CM_L4_WKUP_AON_CLKSTCTRL->CLKACTIVITY_L4_WKUP_AON_GCLK != CM_WKUP_CLK_ACTIVE);
            while (CM_WKUP_CLKSTCTRL->CLKACTIVITY_UART0_GFCLK != CM_WKUP_CLK_ACTIVE);
            while (CM_WKUP_UART0_CLKCTRL->IDLEST != CM_WKUP_IDLEST_FUNCTIONAL);
            break;
        case UARTId::_1:
            CM_PER_UART1_CLKCTRL->MODULEMODE = CM_PER_MODULEMODE_ENABLE;
            while (CM_PER_UART1_CLKCTRL->MODULEMODE != CM_PER_MODULEMODE_ENABLE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_L4LS_GCLK != CM_PER_CLK_ACTIVE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_UART_GFCLK != CM_PER_CLK_ACTIVE);
            break;
        case UARTId::_2:
            CM_PER_UART2_CLKCTRL->MODULEMODE = CM_PER_MODULEMODE_ENABLE;
            while (CM_PER_UART2_CLKCTRL->MODULEMODE != CM_PER_MODULEMODE_ENABLE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_L4LS_GCLK != CM_PER_CLK_ACTIVE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_UART_GFCLK != CM_PER_CLK_ACTIVE);
            break;
        case UARTId::_3:
            CM_PER_UART3_CLKCTRL->MODULEMODE = CM_PER_MODULEMODE_ENABLE;
            while (CM_PER_UART3_CLKCTRL->MODULEMODE != CM_PER_MODULEMODE_ENABLE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_L4LS_GCLK != CM_PER_CLK_ACTIVE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_UART_GFCLK != CM_PER_CLK_ACTIVE);
            break;
        case UARTId::_4:
            CM_PER_UART4_CLKCTRL->MODULEMODE = CM_PER_MODULEMODE_ENABLE;
            while (CM_PER_UART4_CLKCTRL->MODULEMODE != CM_PER_MODULEMODE_ENABLE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_L4LS_GCLK != CM_PER_CLK_ACTIVE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_UART_GFCLK != CM_PER_CLK_ACTIVE);
            break;
        case UARTId::_5:
            CM_PER_UART5_CLKCTRL->MODULEMODE = CM_PER_MODULEMODE_ENABLE;
            while (CM_PER_UART5_CLKCTRL->MODULEMODE != CM_PER_MODULEMODE_ENABLE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_L4LS_GCLK != CM_PER_CLK_ACTIVE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_UART_GFCLK != CM_PER_CLK_ACTIVE);
            break;
    }

    reset();
    initFIFO();
    setOperatingMode(OperatingMode::Uart16x);
    enableFIFO(false);
    enableDMA(false);

    m_initialized = true;
}

void AM335x_UART::reset()
{
    UART_SYSC(m_base)->SOFTRESET = static_cast<std::uint16_t>(true);
    while (!UART_SYSS(m_base)->RESETDONE);
}

void AM335x_UART::setBaudRate(unsigned int baudRate)
{
    // Enable access to IER[4] (SLEEPMODE).
    bool savedEnhancements = enableEnhancements(true);
    std::uint16_t savedLCR = setConfigMode(ConfigMode::Operational);

    // Disable sleep mode.
    volatile bool savedSleepmode = static_cast<bool>(UART_IER(m_base)->SLEEPMODE);
    UART_IER(m_base)->SLEEPMODE = 0;

    // Enable access to DLL and DLH.
    setConfigMode(ConfigMode::B);
    OperatingMode savedMode = setOperatingMode(OperatingMode::Disable);

    // Write to divisor latch.
    if (baudRate == 0) {
        UART_DLL(m_base)->CLOCK_LSB = 0;
        UART_DLH(m_base)->CLOCK_MSB = 0;
    }
    else {
        std::uint32_t divisorValue = INPUT_CLOCK_HZ / (16 * baudRate);
        UART_DLL(m_base)->CLOCK_LSB = static_cast<std::uint16_t>(divisorValue & 0xff);
        UART_DLH(m_base)->CLOCK_MSB = static_cast<std::uint16_t>((divisorValue >> 8) & 0xff);
    }

    // Restore operating mode.
    setOperatingMode(savedMode);

    // Restore sleep mode.
    setConfigMode(ConfigMode::Operational);
    UART_IER(m_base)->SLEEPMODE = static_cast<std::uint16_t>(savedSleepmode);

    restoreLCR(savedLCR);
    enableEnhancements(savedEnhancements);
}

bool AM335x_UART::setDataBits(DataBits dataBits)
{
    switch (dataBits) {
        case DataBits::_5:
            UART_LCR(m_base)->CHAR_LENGTH = 0x0;
            break;
        case DataBits::_6:
            UART_LCR(m_base)->CHAR_LENGTH = 0x1;
            break;
        case DataBits::_7:
            UART_LCR(m_base)->CHAR_LENGTH = 0x2;
            break;
        case DataBits::_8:
            UART_LCR(m_base)->CHAR_LENGTH = 0x3;
            break;
    }

    return true;
}

bool AM335x_UART::setStopBits(StopBits stopBits)
{
    switch (stopBits) {
        case StopBits::_1:
            UART_LCR(m_base)->NB_STOP = 0x0;
            break;
        case StopBits::_1_5:
        case StopBits::_2:
            UART_LCR(m_base)->NB_STOP = 0x1;
            break;
        default:
            return false;
    }

    return true;
}

bool AM335x_UART::setPartity(Partity partity)
{
    switch (partity) {
        case Partity::None:
            UART_LCR(m_base)->PARITY_EN = 0x0;
            break;
        case Partity::Even:
            UART_LCR(m_base)->PARITY_EN = 0x1;
            UART_LCR(m_base)->PARITY_TYPE1 = 0x1;
            break;
        case Partity::Odd:
            UART_LCR(m_base)->PARITY_EN = 0x1;
            UART_LCR(m_base)->PARITY_TYPE1 = 0x0;
            break;
    }

    return true;
}

bool AM335x_UART::setFlowControl(FlowControl flowControl)
{
    std::uint16_t savedLCR = setConfigMode(ConfigMode::B);
    bool result = true;

    switch (flowControl) {
        case FlowControl::None:
            UART_EFR(m_base)->AUTORTSEN = 0x0;
            UART_EFR(m_base)->AUTOCTSEN = 0x0;
            break;
        case FlowControl::RtsCts:
            UART_EFR(m_base)->AUTORTSEN = 0x1;
            UART_EFR(m_base)->AUTOCTSEN = 0x1;
            break;
        default:
            result =  false;
            break;
    }

    restoreLCR(savedLCR);
    return result;
}

bool AM335x_UART::setDirection(Direction)
{
    // AM335x doesn't support setting direction.
    return true;
}

bool AM335x_UART::setTransmissionMode(TransmissionMode mode)
{
    // AM335x supports only asynchonous transmission mode.
    return (mode == TransmissionMode::Asynchronous);
}

void AM335x_UART::enableDMA(bool enabled)
{
    // Set SCR as DMA mode control register.
    UART_SCR(m_base)->DMAMODECTL = 0x1;
    UART_SCR(m_base)->DMAMODE2 = static_cast<std::uint16_t>(enabled ? 0x1 : 0x0);
}

void AM335x_UART::enableFIFO(bool enabled)
{
    // Disable baud clock before enabling/disabling FIFO.
    setBaudRate(0);

    std::uint16_t savedLCR = setConfigMode(ConfigMode::A);
    UART_FCR(m_base)->FIFO_EN = static_cast<std::uint16_t>(enabled);
    restoreLCR(savedLCR);

    m_fifoEnabled = enabled;
}

void AM335x_UART::clearRxFIFO()
{
    std::uint16_t savedLCR = setConfigMode(ConfigMode::A);
    UART_FCR(m_base)->RX_FIFO_CLEAR = 0x1;
    restoreLCR(savedLCR);
}

void AM335x_UART::clearTxFIFO()
{
    std::uint16_t savedLCR = setConfigMode(ConfigMode::A);
    UART_FCR(m_base)->TX_FIFO_CLEAR = 0x1;
    restoreLCR(savedLCR);
}

bool AM335x_UART::isTxFIFOEmpty()
{
    return (UART_LSR(m_base)->TXSRE && UART_LSR(m_base)->TXFIFOE);
}

std::size_t AM335x_UART::read(void* buff __attribute__((unused)), std::size_t size __attribute__((unused)))
{
    // TODO: Implement.
    return 0;
}

std::size_t AM335x_UART::write(const void* buff, std::size_t size)
{
    std::size_t i;

    for (i = 0; i < size; ++i) {
        if (!writeChar(((std::uint8_t *) buff)[i]))
            break;
    }

    return i;
}

std::uint8_t AM335x_UART::readChar()
{
    // TODO: Implement.
    return 0;
}

bool AM335x_UART::writeChar(std::uint8_t value)
{
    while (!isTxFIFOEmpty());

    UART_THR(m_base)->THR = value;
    return true;
}

std::uint16_t AM335x_UART::setConfigMode(ConfigMode mode)
{
    volatile std::uint16_t result = UART_LCR(m_base)->value;

    switch (mode) {
        case ConfigMode::A:
        case ConfigMode::B:
            UART_LCR(m_base)->value = static_cast<std::uint16_t>(mode);
            break;

        case ConfigMode::Operational:
            UART_LCR(m_base)->value &= static_cast<std::uint16_t>(mode);
            break;
    }

    return result;
}

OperatingMode AM335x_UART::setOperatingMode(OperatingMode mode)
{
    volatile OperatingMode result = static_cast<OperatingMode>(UART_MDR1(m_base)->MODESELECT);
    UART_MDR1(m_base)->MODESELECT = static_cast<std::uint16_t>(mode);

    return static_cast<OperatingMode>(result);
}

void AM335x_UART::restoreLCR(std::uint16_t value)
{
    UART_LCR(m_base)->value = value;
}

bool AM335x_UART::enableEnhancements(bool enable)
{
    // Enable access to EFR register.
    std::uint16_t savedLCR = setConfigMode(ConfigMode::B);

    volatile bool savedEnhancements = static_cast<bool>(UART_EFR(m_base)->ENHANCEDEN);
    UART_EFR(m_base)->ENHANCEDEN = static_cast<std::uint16_t>(enable);

    restoreLCR(savedLCR);

    return savedEnhancements;
}

void AM335x_UART::setTriggerGranularity(TrigGranularity rxGranulatiry, TrigGranularity txGranulatiry)
{
    UART_SCR(m_base)->RXTRIGGRANU1 = static_cast<std::uint16_t>(rxGranulatiry);
    UART_SCR(m_base)->TXTRIGGRANU1 = static_cast<std::uint16_t>(txGranulatiry);
}

void AM335x_UART::setTriggerLevels(FIFOTrigLevel rxLevel, FIFOTrigLevel txLevel)
{
    // Enable access to FCR[5:4] (TX_FIFO_TRIG).
    bool savedEnhancements = enableEnhancements(true);

    UART_FCR(m_base)->RX_FIFO_TRIG = static_cast<std::uint16_t>(rxLevel);
    UART_FCR(m_base)->TX_FIFO_TRIG = static_cast<std::uint16_t>(txLevel);

    enableEnhancements(savedEnhancements);
}

void AM335x_UART::initFIFO()
{
    setTriggerGranularity(TrigGranularity::_1, TrigGranularity::_1);
    setTriggerLevels(FIFOTrigLevel::_8, FIFOTrigLevel::_8);

    clearRxFIFO();
    clearTxFIFO();
}

} // namespace UART
} // namespace Device
