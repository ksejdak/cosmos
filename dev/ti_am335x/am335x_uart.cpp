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

#include <os/assert.h>

namespace Device {

template<>
UART::IUART& DeviceManager<UART::IUART>::getDevice(int id)
{
    using namespace UART::AM335x;

    static AM335x_UART uarts[getDeviceCount()] {
        UART_0,
        UART_1,
        UART_2,
        UART_3,
        UART_4,
        UART_5
    };

    assert(id >= 0 && id < getDeviceCount());
    return uarts[id];
}

namespace UART {
namespace AM335x {

typedef enum {
    DMA_DISABLED,
    DMA_MODE_1
} DMAMode_t;

int AM335x_UART::getBaseAddress(int uartNo)
{
    switch (uartNo) {
        case UART_0:     return UART_0_BASE;
        case UART_1:     return UART_1_BASE;
        case UART_2:     return UART_2_BASE;
        case UART_3:     return UART_3_BASE;
        case UART_4:     return UART_4_BASE;
        case UART_5:     return UART_5_BASE;
    }

    return -1;
}

AM335x_UART::AM335x_UART(UARTId_t uartNo)
    : m_uartNo(uartNo)
    , m_base(getBaseAddress(uartNo))
{
    // TODO:
    // - register IRQ handler for given UART
    // - register /dev/uartX device.
}

void AM335x_UART::init()
{
    using namespace Clock::AM335x;

    if (m_initialized)
        return;
    
    // Enable interface and functional clocks.
    switch (m_uartNo) {
        case UART_0:
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
        case UART_1:
            CM_PER_UART1_CLKCTRL->MODULEMODE = CM_PER_MODULEMODE_ENABLE;
            while (CM_PER_UART1_CLKCTRL->MODULEMODE != CM_PER_MODULEMODE_ENABLE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_L4LS_GCLK != CM_PER_CLK_ACTIVE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_UART_GFCLK != CM_PER_CLK_ACTIVE);
            break;
        case UART_2:
            CM_PER_UART2_CLKCTRL->MODULEMODE = CM_PER_MODULEMODE_ENABLE;
            while (CM_PER_UART2_CLKCTRL->MODULEMODE != CM_PER_MODULEMODE_ENABLE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_L4LS_GCLK != CM_PER_CLK_ACTIVE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_UART_GFCLK != CM_PER_CLK_ACTIVE);
            break;
        case UART_3:
            CM_PER_UART3_CLKCTRL->MODULEMODE = CM_PER_MODULEMODE_ENABLE;
            while (CM_PER_UART3_CLKCTRL->MODULEMODE != CM_PER_MODULEMODE_ENABLE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_L4LS_GCLK != CM_PER_CLK_ACTIVE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_UART_GFCLK != CM_PER_CLK_ACTIVE);
            break;
        case UART_4:
            CM_PER_UART4_CLKCTRL->MODULEMODE = CM_PER_MODULEMODE_ENABLE;
            while (CM_PER_UART4_CLKCTRL->MODULEMODE != CM_PER_MODULEMODE_ENABLE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_L4LS_GCLK != CM_PER_CLK_ACTIVE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_UART_GFCLK != CM_PER_CLK_ACTIVE);
            break;
        case UART_5:
            CM_PER_UART5_CLKCTRL->MODULEMODE = CM_PER_MODULEMODE_ENABLE;
            while (CM_PER_UART5_CLKCTRL->MODULEMODE != CM_PER_MODULEMODE_ENABLE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_L4LS_GCLK != CM_PER_CLK_ACTIVE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_UART_GFCLK != CM_PER_CLK_ACTIVE);
            break;
    }

    reset();

    m_initialized = true;
}

void AM335x_UART::reset()
{
    UART_SYSC(m_base)->SOFTRESET = true;
    while (!UART_SYSS(m_base)->RESETDONE);
}

void AM335x_UART::setBaudRate(unsigned int baudRate)
{
    // Enable access to IER[4] (SLEEPMODE).
    bool savedEnhancements = enableEnhancements(true);
    uint32_t savedLCR = setConfigMode(CONFIG_MODE_OPERATIONAL);

    // Disable sleep mode.
    volatile bool savedSleepmode = UART_IER(m_base)->SLEEPMODE;
    UART_IER(m_base)->SLEEPMODE = 0;

    // Enable access to DLL and DLH.
    setConfigMode(CONFIG_MODE_B);
    OperatingMode_t savedMode = setOperatingMode(MODE_DISABLE);

    // Write to divisor latch.
    if (baudRate == 0) {
        UART_DLL(m_base)->CLOCK_LSB = 0;
        UART_DLH(m_base)->CLOCK_MSB = 0;
    }
    else {
        uint32_t divisorValue = INPUT_CLOCK_HZ / (16 * baudRate);
        UART_DLL(m_base)->CLOCK_LSB = (divisorValue & 0xff);
        UART_DLH(m_base)->CLOCK_MSB = ((divisorValue >> 8) & 0xff);
    }

    // Restore operating mode. 
    setOperatingMode(savedMode);

    // Restore sleep mode.
    setConfigMode(CONFIG_MODE_OPERATIONAL);
    UART_IER(m_base)->SLEEPMODE = savedSleepmode;


    // Restore LCR register and enhancements.
    UART_LCR(m_base)->value = savedLCR;
    enableEnhancements(savedEnhancements);
}

void AM335x_UART::setTriggerGranularity(TrigGranularity_t rxGranulatiry, TrigGranularity_t txGranulatiry)
{
    UART_SCR(m_base)->RXTRIGGRANU1 = rxGranulatiry;
    UART_SCR(m_base)->TXTRIGGRANU1 = txGranulatiry;
}

void AM335x_UART::setTriggerLevels(FIFOTrigLevel_t rxLevel, FIFOTrigLevel_t txLevel)
{
    // Enable access to FCR[5:4] (TX_FIFO_TRIG).
    bool savedEnhancements = enableEnhancements(true);

    UART_FCR(m_base)->RX_FIFO_TRIG = rxLevel;
    UART_FCR(m_base)->TX_FIFO_TRIG = txLevel;

    enableEnhancements(savedEnhancements);
}

void AM335x_UART::enableDMA(bool enabled)
{
    // Set SCR as DMA mode control register.
    UART_SCR(m_base)->DMAMODECTL = 0x1;
    UART_SCR(m_base)->DMAMODE2 = (enabled ? DMA_MODE_1 : DMA_DISABLED);
}

void AM335x_UART::enableFIFO(bool enabled)
{
    // Disable baud clock before enabling/disabling FIFO.
    setBaudRate(0);

    UART_FCR(m_base)->FIFO_EN = enabled;
}

bool AM335x_UART::enableEnhancements(bool enable)
{
    // Enable access to EFR register.
    uint32_t savedLCR = setConfigMode(CONFIG_MODE_B);

    volatile bool savedEnhancements = UART_EFR(m_base)->ENHANCEDEN;
    UART_EFR(m_base)->ENHANCEDEN = enable;

    // Restore LCR register.
    UART_LCR(m_base)->value = savedLCR;

    return savedEnhancements;
}

bool AM335x_UART::enableTCRTLRAccess(bool enable)
{
    // Enable access to MCR[6] (TCRTLR).
    bool savedEnhancements = enableEnhancements(true);
    uint32_t savedLCR = setConfigMode(CONFIG_MODE_A);

    volatile bool savedTCRTLC = UART_MCR(m_base)->TCRTLR;
    UART_MCR(m_base)->TCRTLR = enable;

    // Restore LCR register and enhancements.
    UART_LCR(m_base)->value = savedLCR;
    enableEnhancements(savedEnhancements);

    return savedTCRTLC;
}

uint32_t AM335x_UART::setConfigMode(ConfigMode_t mode)
{
    volatile uint32_t result = UART_LCR(m_base)->value;

    switch (mode) {
        case CONFIG_MODE_A:
        case CONFIG_MODE_B:
            UART_LCR(m_base)->value = mode;
            break;

        case CONFIG_MODE_OPERATIONAL:
            UART_LCR(m_base)->value &= mode;
            break;
    }

    return result;
}

OperatingMode_t AM335x_UART::setOperatingMode(OperatingMode_t mode)
{
    volatile OperatingMode_t result = (OperatingMode_t) UART_MDR1(m_base)->MODESELECT;
    UART_MDR1(m_base)->MODESELECT = mode;

    return result;
}

void AM335x_UART::initFIFO()
{
    setTriggerGranularity(TRIG_GRANULARITY_1, TRIG_GRANULARITY_1);
    setTriggerLevels(FIFO_TRIG_LEVEL_8, FIFO_TRIG_LEVEL_8);

    enableDMA(false);
    enableFIFO(true);

    //bool savedTCRTLC = enableTCRTLRAccess(true);
    //UART_TLR(m_base)->RX_FIFO_TRIG_DMA = xxx;
    //UART_TLR(m_base)->TX_FIFO_TRIG_DMA = xxx;
    //enableTCRTLRAccess(savedTCRTLC);
}

} // namespace AM335x
} // namespace UART
} // namespace Device
