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
#include "am335x_clock_peripheral.h"

namespace Device {

static bool AM335x_Clock::m_initialized = false;

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
    //CM_WKUP_CONTROL_CLKCTRL->MODULEMODE = CM_WKUP_MODULEMODE_ENABLE;
    //while (CM_WKUP_CONTROL_CLKCTRL->MODULEMODE != CM_WKUP_MODULEMODE_ENABLE);

    m_initialized = true;
}

bool AM335x_Clock::initUart(AM335x_UARTId_t id)
{
#if 0
    /* Writing to CLKTRCTRL field of CM_PER_L3S_CLKSTCTRL register. */
    HWREG(SOC_CM_WKUP_REGS + CM_WKUP_CLKSTCTRL) |=
          CM_WKUP_CLKSTCTRL_CLKTRCTRL_SW_WKUP;

    /*Waiting for CLKTRCTRL field to reflect the written value. */
    while(CM_WKUP_CLKSTCTRL_CLKTRCTRL_SW_WKUP !=
          (HWREG(SOC_CM_WKUP_REGS + CM_WKUP_CLKSTCTRL) &
           CM_WKUP_CLKSTCTRL_CLKTRCTRL));

    /* Writing to CLKTRCTRL field of CM_L3_AON_CLKSTCTRL register. */
    HWREG(SOC_CM_WKUP_REGS + CM_WKUP_CM_L3_AON_CLKSTCTRL) |=
          CM_WKUP_CM_L3_AON_CLKSTCTRL_CLKTRCTRL_SW_WKUP;

    /*Waiting for CLKTRCTRL field to reflect the written value. */
    while(CM_WKUP_CM_L3_AON_CLKSTCTRL_CLKTRCTRL_SW_WKUP !=
          (HWREG(SOC_CM_WKUP_REGS + CM_WKUP_CM_L3_AON_CLKSTCTRL) &
           CM_WKUP_CM_L3_AON_CLKSTCTRL_CLKTRCTRL));

    /* Writing to MODULEMODE field of CM_WKUP_UART0_CLKCTRL register. */
    HWREG(SOC_CM_WKUP_REGS + CM_WKUP_UART0_CLKCTRL) |=
          CM_WKUP_UART0_CLKCTRL_MODULEMODE_ENABLE;

    /* Waiting for MODULEMODE field to reflect the written value. */
    while(CM_WKUP_UART0_CLKCTRL_MODULEMODE_ENABLE !=
          (HWREG(SOC_CM_WKUP_REGS + CM_WKUP_UART0_CLKCTRL) &
           CM_WKUP_UART0_CLKCTRL_MODULEMODE));

    /* Verifying if the other bits are set to required settings. */

    /*
    ** Waiting for IDLEST field in CM_WKUP_CONTROL_CLKCTRL register to attain
    ** desired value.
    */
    while((CM_WKUP_CONTROL_CLKCTRL_IDLEST_FUNC <<
           CM_WKUP_CONTROL_CLKCTRL_IDLEST_SHIFT) !=
          (HWREG(SOC_CM_WKUP_REGS + CM_WKUP_CONTROL_CLKCTRL) &
           CM_WKUP_CONTROL_CLKCTRL_IDLEST));

    /*
    ** Waiting for CLKACTIVITY_L3_AON_GCLK field in CM_L3_AON_CLKSTCTRL
    ** register to attain desired value.
    */
    while(CM_WKUP_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_L3_AON_GCLK !=
          (HWREG(SOC_CM_WKUP_REGS + CM_WKUP_CM_L3_AON_CLKSTCTRL) &
           CM_WKUP_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_L3_AON_GCLK));

    /*
    ** Waiting for IDLEST field in CM_WKUP_L4WKUP_CLKCTRL register to attain
    ** desired value.
    */
    while((CM_WKUP_L4WKUP_CLKCTRL_IDLEST_FUNC <<
           CM_WKUP_L4WKUP_CLKCTRL_IDLEST_SHIFT) !=
          (HWREG(SOC_CM_WKUP_REGS + CM_WKUP_L4WKUP_CLKCTRL) &
           CM_WKUP_L4WKUP_CLKCTRL_IDLEST));

    /*
    ** Waiting for CLKACTIVITY_L4_WKUP_GCLK field in CM_WKUP_CLKSTCTRL register
    ** to attain desired value.
    */
    while(CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_WKUP_GCLK !=
          (HWREG(SOC_CM_WKUP_REGS + CM_WKUP_CLKSTCTRL) &
           CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_WKUP_GCLK));

    /*
    ** Waiting for CLKACTIVITY_L4_WKUP_AON_GCLK field in CM_L4_WKUP_AON_CLKSTCTRL
    ** register to attain desired value.
    */
    while(CM_WKUP_CM_L4_WKUP_AON_CLKSTCTRL_CLKACTIVITY_L4_WKUP_AON_GCLK !=
          (HWREG(SOC_CM_WKUP_REGS + CM_WKUP_CM_L4_WKUP_AON_CLKSTCTRL) &
           CM_WKUP_CM_L4_WKUP_AON_CLKSTCTRL_CLKACTIVITY_L4_WKUP_AON_GCLK));

    /*
    ** Waiting for CLKACTIVITY_UART0_GFCLK field in CM_WKUP_CLKSTCTRL
    ** register to attain desired value.
    */
    while(CM_WKUP_CLKSTCTRL_CLKACTIVITY_UART0_GFCLK !=
          (HWREG(SOC_CM_WKUP_REGS + CM_WKUP_CLKSTCTRL) &
           CM_WKUP_CLKSTCTRL_CLKACTIVITY_UART0_GFCLK));

    /*
    ** Waiting for IDLEST field in CM_WKUP_UART0_CLKCTRL register to attain
    ** desired value.
    */
    while((CM_WKUP_UART0_CLKCTRL_IDLEST_FUNC <<
           CM_WKUP_UART0_CLKCTRL_IDLEST_SHIFT) !=
          (HWREG(SOC_CM_WKUP_REGS + CM_WKUP_UART0_CLKCTRL) &
           CM_WKUP_UART0_CLKCTRL_IDLEST));
#endif
}

} // namespace Device
