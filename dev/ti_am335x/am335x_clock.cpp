////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       21.08.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#include "am335x_clock.h"
#include "am335x_clock_regs_per.h"
#include "am335x_clock_regs_wkup.h"

namespace Device {

bool AM335x_Clock::m_initialized = false;

AM335x_Clock::AM335x_Clock()
{
    if (m_initialized)
        return;

    // Configure L3 interface clocks.
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

    // Wait for necessary register values.
    while (CM_PER_L3_CLKCTRL->IDLEST != CM_PER_IDLEST_FUNCTIONAL);
    while (CM_PER_L3_INSTR_CLKCTRL->IDLEST != CM_PER_IDLEST_FUNCTIONAL);
    while (CM_PER_L3_CLKSTCTRL->CLKACTIVITY_L3_GCLK != CM_PER_CLK_ACTIVE);
    while (CM_PER_OCPWP_L3_CLKSTCTRL->CLKACTIVITY_OCPWP_L3_GCLK != CM_PER_CLK_ACTIVE);
    while (CM_PER_L3S_CLKSTCTRL->CLKACTIVITY_L3S_GCLK != CM_PER_CLK_ACTIVE);

    // Configure registers related to wake-up region.
    CM_WKUP_CONTROL_CLKCTRL->MODULEMODE = CM_WKUP_MODULEMODE_ENABLE;
    while (CM_WKUP_CONTROL_CLKCTRL->MODULEMODE != CM_WKUP_MODULEMODE_ENABLE);

    CM_WKUP_CLKSTCTRL->CLKTRCTRL = CM_WKUP_CLKTRCTRL_SW_WKUP;
    while (CM_WKUP_CLKSTCTRL->CLKTRCTRL != CM_WKUP_CLKTRCTRL_SW_WKUP);

    CM_L3_AON_CLKSTCTRL->CLKTRCTRL = CM_WKUP_CLKTRCTRL_SW_WKUP;
    while (CM_L3_AON_CLKSTCTRL->CLKTRCTRL != CM_WKUP_CLKTRCTRL_SW_WKUP);

    // Wait for necessary register values.
    while (CM_WKUP_CONTROL_CLKCTRL->IDLEST != CM_WKUP_IDLEST_FUNCTIONAL);
    while (CM_L3_AON_CLKSTCTRL->CLKACTIVITY_L3_AON_GCLK != CM_WKUP_CLK_ACTIVE);
    while (CM_WKUP_L4WKUP_CLKCTRL->IDLEST != CM_WKUP_IDLEST_FUNCTIONAL);
    while (CM_WKUP_CLKSTCTRL->CLKACTIVITY_L4_WKUP_GCLK != CM_WKUP_CLK_ACTIVE);
    while (CM_L4_WKUP_AON_CLKSTCTRL->CLKACTIVITY_L4_WKUP_AON_GCLK != CM_WKUP_CLK_ACTIVE);

    m_initialized = true;
}

bool AM335x_Clock::initUart(AM335x_UARTId_t id)
{
    // Configure UARTx interface clock.
    switch (id) {
        case AM335x_UART0:
            CM_WKUP_UART0_CLKCTRL->MODULEMODE = CM_WKUP_MODULEMODE_ENABLE;
            while (CM_WKUP_UART0_CLKCTRL->MODULEMODE != CM_WKUP_MODULEMODE_ENABLE);
            break;
        default:
            break;
    }

    // Wait for necessary register values.
    while (CM_WKUP_CLKSTCTRL->CLKACTIVITY_UART0_GFCLK != CM_WKUP_CLK_ACTIVE);
    while (CM_WKUP_UART0_CLKCTRL->IDLEST != CM_WKUP_IDLEST_FUNCTIONAL);

    return true;
}

} // namespace Device
