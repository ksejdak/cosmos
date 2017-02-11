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
IUART& DeviceManager<IUART>::getDevice(int id)
{
    static AM335x_UART uarts[getDeviceCount()] {
        AM335x_UART_0,
        AM335x_UART_1,
        AM335x_UART_2,
        AM335x_UART_3,
        AM335x_UART_4,
        AM335x_UART_5
    };

    assert(id >= 0 && id < getDeviceCount());
    return uarts[id];
}

AM335x_UART::AM335x_UART(AM335x_UARTId_t uartNo)
    : m_uartNo(uartNo)
    , m_base(getBaseAddress(uartNo))
{
    // TODO:
    // - register IRQ handler for given UART
    // - register /dev/uartX device.
}

void AM335x_UART::init()
{
    if (m_initialized)
        return;
    
    // Enable interface and functional clocks.
    switch (m_uartNo) {
        case AM335x_UART_0:
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
        case AM335x_UART_1:
            CM_PER_UART1_CLKCTRL->MODULEMODE = CM_PER_MODULEMODE_ENABLE;
            while (CM_PER_UART1_CLKCTRL->MODULEMODE != CM_PER_MODULEMODE_ENABLE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_L4LS_GCLK != CM_PER_CLK_ACTIVE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_UART_GFCLK != CM_PER_CLK_ACTIVE);
            break;
        case AM335x_UART_2:
            CM_PER_UART2_CLKCTRL->MODULEMODE = CM_PER_MODULEMODE_ENABLE;
            while (CM_PER_UART2_CLKCTRL->MODULEMODE != CM_PER_MODULEMODE_ENABLE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_L4LS_GCLK != CM_PER_CLK_ACTIVE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_UART_GFCLK != CM_PER_CLK_ACTIVE);
            break;
        case AM335x_UART_3:
            CM_PER_UART3_CLKCTRL->MODULEMODE = CM_PER_MODULEMODE_ENABLE;
            while (CM_PER_UART3_CLKCTRL->MODULEMODE != CM_PER_MODULEMODE_ENABLE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_L4LS_GCLK != CM_PER_CLK_ACTIVE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_UART_GFCLK != CM_PER_CLK_ACTIVE);
            break;
        case AM335x_UART_4:
            CM_PER_UART4_CLKCTRL->MODULEMODE = CM_PER_MODULEMODE_ENABLE;
            while (CM_PER_UART4_CLKCTRL->MODULEMODE != CM_PER_MODULEMODE_ENABLE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_L4LS_GCLK != CM_PER_CLK_ACTIVE);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_UART_GFCLK != CM_PER_CLK_ACTIVE);
            break;
        case AM335x_UART_5:
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
    if (baudRate == 0) {
        UART_DLL(m_base)->CLOCK_LSB = 0;
        UART_DLH(m_base)->CLOCK_MSB = 0;
        return;
    }
}

int AM335x_UART::getBaseAddress(int uartNo)
{
    switch (uartNo) {
        case AM335x_UART_0:     return UART_0_BASE;
        case AM335x_UART_1:     return UART_1_BASE;
        case AM335x_UART_2:     return UART_2_BASE;
        case AM335x_UART_3:     return UART_3_BASE;
        case AM335x_UART_4:     return UART_4_BASE;
        case AM335x_UART_5:     return UART_5_BASE;
    }

    return -1;
}

bool AM335x_UART::setEnhancements(bool value)
{
    // Enable access to EFR register.
    uint32_t savedLCR = setConfigMode(UART_CONFIG_MODE_B);

    volatile bool savedEnhancements = UART_EFR(m_base)->ENHANCEDEN;
    UART_EFR(m_base)->ENHANCEDEN = value;

    // Restore LCR register.
    UART_LCR(m_base)->value = savedLCR;
    
    return savedEnhancements;
}

bool AM335x_UART::setTCRTLRAccess(bool value)
{
    // Enable access to MCR register.
    uint32_t savedLCR = setConfigMode(UART_CONFIG_MODE_A);

    volatile bool savedTCRTLC = UART_MCR(m_base)->TCRTLR;
    UART_MCR(m_base)->TCRTLR = value;

    // Restore LCR register.
    UART_LCR(m_base)->value = savedLCR;

    return savedTCRTLC;
}

uint32_t AM335x_UART::setConfigMode(AM335x_UARTConfigMode_t mode)
{
    uint32_t result = UART_LCR(m_base)->value;

    switch (mode) {
        case UART_CONFIG_MODE_A:
        case UART_CONFIG_MODE_B:
            UART_LCR(m_base)->value = mode;
            break;

        case UART_CONFIG_MODE_OPERATIONAL:
            UART_LCR(m_base)->value &= mode;
            break;
    }

    return result;
}

void AM335x_UART::initFIFO()
{
    bool savedEnhancements = setEnhancements(true);
    bool savedTCRTLC = setTCRTLRAccess(true);

    //UART_FCR(m_base)->RX_FIFO_TRIG = xxx;
    //UART_FCR(m_base)->TX_FIFO_TRIG = xxx;
    //UART_FCR(m_base)->DMA_MODE = xxx;

    // Disable baud clock before enabling FIFO.
    setBaudRate(0);
    UART_FCR(m_base)->FIFO_EN = true;

    //UART_TLR(m_base)->RX_FIFO_TRIG_DMA = xxx;
    //UART_TLR(m_base)->TX_FIFO_TRIG_DMA = xxx;

    //UART_SCR(m_base)->RXTRIGGRANU1 = xxx;
    //UART_SCR(m_base)->TXTRIGGRANU1 = xxx;
    //UART_SCR(m_base)->DMAMODE2 = xxx;
    //UART_SCR(m_base)->DMAMODECTL = xxx;

    setTCRTLRAccess(savedTCRTLC);
    setEnhancements(savedEnhancements);
}

} // namespace Device
