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
    static AM335x_UART uarts[AM335x_UART::AM335x_UART_COUNT] {
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
    UART_SYSC(m_base)->SOFTRESET = 1;
    while (!UART_SYSS(m_base)->RESETDONE);
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

} // namespace Device
