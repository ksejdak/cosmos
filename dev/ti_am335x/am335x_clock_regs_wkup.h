////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       26.12.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AM335X_CLOCK_REGS_WKUP_H
#define AM335X_CLOCK_REGS_WKUP_H

#include <os/stdint.h>
#include <os/utils.h>

namespace Device {

typedef union {
    struct {
        uint32_t CLKTRCTRL : 2;
        uint32_t CLKACTIVITY_L4_WKUP_GCLK : 1;
        uint32_t CLKACTIVITY_SR_SYSCLK : 1;
        uint32_t CLKACTIVITY_WDT1_CLK : 1;
        uint32_t : 3;
        uint32_t CLKACTIVITY_GPIO0_GDBCLK : 1;
        uint32_t : 1;
        uint32_t CLKACTIVITY_TIMER0_GCLK : 1;
        uint32_t CLKACTIVITY_I2C0_GFCLK : 1;
        uint32_t CLKACTIVITY_UART0_GFCLK : 1;
        uint32_t CLKACTIVITY_TIMER1_GCLK : 1;
        uint32_t CLKACTIVITY_ADC_FCLK : 1;
        uint32_t : 17;
    };

    uint32_t value;
} CM_WKUP_CLKSTCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_WKUP_CONTROL_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t OPTFCLKEN_GPIO0_GDBCLK : 1;
        uint32_t : 13;
    };

    uint32_t value;
} CM_WKUP_GPIO0_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_WKUP_L4WKUP_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_WKUP_TIMER0_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t STBYST : 1;
        uint32_t OPTFCLKEN_DBGSYSCLK : 1;
        uint32_t TRC_PMD_CLKSEL : 2;
        uint32_t STM_PMD_CLKSEL : 2;
        uint32_t TRC_PMD_CLKDIVSEL : 3;
        uint32_t STM_PMD_CLKDIVSEL : 3;
        uint32_t OPTCLK_DEBUG_CLKA : 1;
        uint32_t : 1;
    };

    uint32_t value;
} CM_WKUP_DEBUGSS_CLKCTRL_t;

typedef union {
    struct {
        uint32_t CLKTRCTRL : 2;
        uint32_t CLKACTIVITY_DBGSYSCLK : 1;
        uint32_t CLKACTIVITY_L3_AON_GCLK : 1;
        uint32_t CLKACTIVITY_DEBUG_CLKA : 1;
        uint32_t : 27;
    };

    uint32_t value;
} CM_L3_AON_CLKSTCTRL_t;

typedef union {
    struct {
        uint32_t AUTO_DPLL_MODE : 3;
        uint32_t : 29;
    };

    uint32_t value;
} CM_AUTOIDLE_DPLL_MPU_t;

typedef union {
    struct {
        uint32_t ST_DPLL_CLK : 1;
        uint32_t : 7;
        uint32_t ST_MN_BYPASS : 1;
        uint32_t : 23;
    };

    uint32_t value;
} CM_IDLEST_DPLL_MPU_t;

typedef union {
    struct {
        uint32_t DELTAMSTEP_FRACTION : 18;
        uint32_t DELTAMSTEP_INTEGER : 2;
        uint32_t : 12;
    };

    uint32_t value;
} CM_SSC_DELTAMSTEP_DPLL_MPU_t;

typedef union {
    struct {
        uint32_t MODFREQDIV_MANTISSA : 7;
        uint32_t : 1;
        uint32_t MODFREQDIV_EXPONENT : 3;
        uint32_t : 21;
    };

    uint32_t value;
} CM_SSC_MODFREQDIV_DPLL_MPU_t;

typedef union {
    struct {
        uint32_t DPLL_DIV : 7;
        uint32_t : 1;
        uint32_t DPLL_MULT : 11;
        uint32_t : 4;
        uint32_t DPLL_BYP_CLKSEL : 1;
        uint32_t : 8;
    };

    uint32_t value;
} CM_CLKSEL_DPLL_MPU_t;

typedef union {
    struct {
        uint32_t AUTO_DPLL_MODE : 3;
        uint32_t : 29;
    };

    uint32_t value;
} CM_AUTOIDLE_DPLL_DDR_t;

typedef union {
    struct {
        uint32_t ST_DPLL_CLK : 1;
        uint32_t : 7;
        uint32_t ST_MN_BYPASS : 1;
        uint32_t : 23;
    };

    uint32_t value;
} CM_IDLEST_DPLL_DDR_t;

typedef union {
    struct {
        uint32_t DELTAMSTEP_FRACTION : 18;
        uint32_t DELTAMSTEP_INTEGER : 2;
        uint32_t : 12;
    };

    uint32_t value;
} CM_SSC_DELTAMSTEP_DPLL_DDR_t;

typedef union {
    struct {
        uint32_t MODFREQDIV_MANTISSA : 7;
        uint32_t : 1;
        uint32_t MODFREQDIV_EXPONENT : 3;
        uint32_t : 21;
    };

    uint32_t value;
} CM_SSC_MODFREQDIV_DPLL_DDR_t;

typedef union {
    struct {
        uint32_t DPLL_DIV : 7;
        uint32_t : 1;
        uint32_t DPLL_MULT : 11;
        uint32_t : 4;
        uint32_t DPLL_BYP_CLKSEL : 1;
        uint32_t : 8;
    };

    uint32_t value;
} CM_CLKSEL_DPLL_DDR_t;


typedef union {
    struct {
        uint32_t AUTO_DPLL_MODE : 3;
        uint32_t : 29;
    };

    uint32_t value;
} CM_AUTOIDLE_DPLL_DISP_t;

typedef union {
    struct {
        uint32_t ST_DPLL_CLK : 1;
        uint32_t : 7;
        uint32_t ST_MN_BYPASS : 1;
        uint32_t : 23;
    };

    uint32_t value;
} CM_IDLEST_DPLL_DISP_t;

typedef union {
    struct {
        uint32_t DELTAMSTEP_FRACTION : 18;
        uint32_t DELTAMSTEP_INTEGER : 2;
        uint32_t : 12;
    };

    uint32_t value;
} CM_SSC_DELTAMSTEP_DPLL_DISP_t;

typedef union {
    struct {
        uint32_t MODFREQDIV_MANTISSA : 7;
        uint32_t : 1;
        uint32_t MODFREQDIV_EXPONENT : 3;
        uint32_t : 21;
    };

    uint32_t value;
} CM_SSC_MODFREQDIV_DPLL_DISP_t;

typedef union {
    struct {
        uint32_t DPLL_DIV : 7;
        uint32_t : 1;
        uint32_t DPLL_MULT : 11;
        uint32_t : 4;
        uint32_t DPLL_BYP_CLKSEL : 1;
        uint32_t : 8;
    };

    uint32_t value;
} CM_CLKSEL_DPLL_DISP_t;

typedef union {
    struct {
        uint32_t AUTO_DPLL_MODE : 3;
        uint32_t : 29;
    };

    uint32_t value;
} CM_AUTOIDLE_DPLL_CORE_t;

typedef union {
    struct {
        uint32_t ST_DPLL_CLK : 1;
        uint32_t : 7;
        uint32_t ST_MN_BYPASS : 1;
        uint32_t : 23;
    };

    uint32_t value;
} CM_IDLEST_DPLL_CORE_t;

typedef union {
    struct {
        uint32_t DELTAMSTEP_FRACTION : 18;
        uint32_t DELTAMSTEP_INTEGER : 2;
        uint32_t : 12;
    };

    uint32_t value;
} CM_SSC_DELTAMSTEP_DPLL_CORE_t;

typedef union {
    struct {
        uint32_t MODFREQDIV_MANTISSA : 7;
        uint32_t : 1;
        uint32_t MODFREQDIV_EXPONENT : 3;
        uint32_t : 21;
    };

    uint32_t value;
} CM_SSC_MODFREQDIV_DPLL_CORE_t;

typedef union {
    struct {
        uint32_t DPLL_DIV : 7;
        uint32_t : 1;
        uint32_t DPLL_MULT : 11;
        uint32_t : 13;
    };

    uint32_t value;
} CM_CLKSEL_DPLL_CORE_t;

typedef union {
    struct {
        uint32_t AUTO_DPLL_MODE : 3;
        uint32_t : 29;
    };

    uint32_t value;
} CM_AUTOIDLE_DPLL_PER_t;

typedef union {
    struct {
        uint32_t ST_DPLL_CLK : 1;
        uint32_t : 7;
        uint32_t ST_MN_BYPASS : 1;
        uint32_t : 23;
    };

    uint32_t value;
} CM_IDLEST_DPLL_PER_t;

typedef union {
    struct {
        uint32_t DELTAMSTEP_FRACTION : 18;
        uint32_t DELTAMSTEP_INTEGER : 2;
        uint32_t : 12;
    };

    uint32_t value;
} CM_SSC_DELTAMSTEP_DPLL_PER_t;

typedef union {
    struct {
        uint32_t MODFREQDIV_MANTISSA : 7;
        uint32_t : 1;
        uint32_t MODFREQDIV_EXPONENT : 3;
        uint32_t : 21;
    };

    uint32_t value;
} CM_SSC_MODFREQDIV_DPLL_PER_t;

typedef union {
    struct {
        uint32_t : 8;
        uint32_t DPLL_CLKDCOLDO_GATE_CTRL : 1;
        uint32_t ST_DPLL_CLKDCOLDO : 1;
        uint32_t : 2;
        uint32_t DPLL_CLKDCOLDO_PWDN : 1;
        uint32_t : 19;
    };

    uint32_t value;
} CM_CLKDCOLDO_DPLL_PER_t;

typedef union {
    struct {
        uint32_t HSDIVIDER_CLKOUT1_DIV : 5;
        uint32_t HSDIVIDER_CLKOUT1_DIVCHACK : 1;
        uint32_t : 2;
        uint32_t HSDIVIDER_CLKOUT1_GATE_CTRL : 1;
        uint32_t ST_HSDIVIDER_CLKOUT1 : 1;
        uint32_t : 2;
        uint32_t HSDIVIDER_CLKOUT1_PWDN : 1;
        uint32_t : 19;
    };

    uint32_t value;
} CM_DIV_M4_DPLL_CORE_t;

typedef union {
    struct {
        uint32_t HSDIVIDER_CLKOUT2_DIV : 5;
        uint32_t HSDIVIDER_CLKOUT2_DIVCHACK : 1;
        uint32_t : 2;
        uint32_t HSDIVIDER_CLKOUT2_GATE_CTRL : 1;
        uint32_t ST_HSDIVIDER_CLKOUT2 : 1;
        uint32_t : 2;
        uint32_t HSDIVIDER_CLKOUT2_PWDN : 1;
        uint32_t : 19;
    };

    uint32_t value;
} CM_DIV_M5_DPLL_CORE_t;

typedef union {
    struct {
        uint32_t DPLL_EN : 3;
        uint32_t DPLL_RAMP_LEVEL : 2;
        uint32_t DPLL_RAMP_RATE : 3;
        uint32_t DPLL_DRIFTGUARD_EN : 1;
        uint32_t DPLL_RELOCK_RAMP_EN : 1;
        uint32_t DPLL_LPMODE_EN : 1;
        uint32_t DPLL_REGM4XEN : 1;
        uint32_t DPLL_SSC_EN : 1;
        uint32_t DPLL_SSC_ACK : 1;
        uint32_t DPLL_SSC_DOWNSPREAD : 1;
        uint32_t DPLL_SSC_TYPE : 1;
        uint32_t : 16;
    };

    uint32_t value;
} CM_CLKMODE_DPLL_MPU_t;

typedef union {
    struct {
        uint32_t DPLL_EN : 3;
        uint32_t : 9;
        uint32_t DPLL_SSC_EN : 1;
        uint32_t DPLL_SSC_ACK : 1;
        uint32_t DPLL_SSC_DOWNSPREAD : 1;
        uint32_t DPLL_SSC_TYPE : 1;
        uint32_t : 16;
    };

    uint32_t value;
} CM_CLKMODE_DPLL_PER_t;

typedef union {
    struct {
        uint32_t DPLL_EN : 3;
        uint32_t DPLL_RAMP_LEVEL : 2;
        uint32_t DPLL_RAMP_RATE : 3;
        uint32_t DPLL_DRIFTGUARD_EN : 1;
        uint32_t DPLL_RELOCK_RAMP_EN : 1;
        uint32_t DPLL_LPMODE_EN : 1;
        uint32_t DPLL_REGM4XEN : 1;
        uint32_t DPLL_SSC_EN : 1;
        uint32_t DPLL_SSC_ACK : 1;
        uint32_t DPLL_SSC_DOWNSPREAD : 1;
        uint32_t DPLL_SSC_TYPE : 1;
        uint32_t : 16;
    };

    uint32_t value;
} CM_CLKMODE_DPLL_CORE_t;

typedef union {
    struct {
        uint32_t DPLL_EN : 3;
        uint32_t DPLL_RAMP_LEVEL : 2;
        uint32_t DPLL_RAMP_RATE : 3;
        uint32_t DPLL_DRIFTGUARD_EN : 1;
        uint32_t DPLL_RELOCK_RAMP_EN : 1;
        uint32_t DPLL_LPMODE_EN : 1;
        uint32_t DPLL_REGM4XEN : 1;
        uint32_t DPLL_SSC_EN : 1;
        uint32_t DPLL_SSC_ACK : 1;
        uint32_t DPLL_SSC_DOWNSPREAD : 1;
        uint32_t DPLL_SSC_TYPE : 1;
        uint32_t : 16;
    };

    uint32_t value;
} CM_CLKMODE_DPLL_DDR_t;

typedef union {
    struct {
        uint32_t DPLL_EN : 3;
        uint32_t DPLL_RAMP_LEVEL : 2;
        uint32_t DPLL_RAMP_RATE : 3;
        uint32_t DPLL_DRIFTGUARD_EN : 1;
        uint32_t DPLL_RELOCK_RAMP_EN : 1;
        uint32_t DPLL_LPMODE_EN : 1;
        uint32_t DPLL_REGM4XEN : 1;
        uint32_t DPLL_SSC_EN : 1;
        uint32_t DPLL_SSC_ACK : 1;
        uint32_t DPLL_SSC_DOWNSPREAD : 1;
        uint32_t DPLL_SSC_TYPE : 1;
        uint32_t : 16;
    };

    uint32_t value;
} CM_CLKMODE_DPLL_DISP_t;

typedef union {
    struct {
        uint32_t DPLL_DIV : 8;
        uint32_t DPLL_MULT : 12;
        uint32_t : 4;
        uint32_t DPLL_SD_DIV : 8;
    };

    uint32_t value;
} CM_CLKSEL_DPLL_PERIPH_t;

typedef union {
    struct {
        uint32_t DPLL_CLKOUT_DIV : 5;
        uint32_t DPLL_CLKOUT_DIVCHACK : 1;
        uint32_t : 2;
        uint32_t DPLL_CLKOUT_GATE_CTRL : 1;
        uint32_t : 22;
    };

    uint32_t value;
} CM_DIV_M2_DPLL_DDR_t;

typedef union {
    struct {
        uint32_t DPLL_CLKOUT_DIV : 5;
        uint32_t DPLL_CLKOUT_DIVCHACK : 1;
        uint32_t : 2;
        uint32_t DPLL_CLKOUT_GATE_CTRL : 2;
        uint32_t ST_DPLL_CLKOUT : 1;
        uint32_t : 22;
    };

    uint32_t value;
} CM_DIV_M2_DPLL_DISP_t;

typedef union {
    struct {
        uint32_t DPLL_CLKOUT_DIV : 5;
        uint32_t DPLL_CLKOUT_DIVCHACK : 1;
        uint32_t : 2;
        uint32_t DPLL_CLKOUT_GATE_CTRL : 2;
        uint32_t ST_DPLL_CLKOUT : 1;
        uint32_t : 22;
    };

    uint32_t value;
} CM_DIV_M2_DPLL_MPU_t;

typedef union {
    struct {
        uint32_t DPLL_CLKOUT_DIV : 5;
        uint32_t DPLL_CLKOUT_DIVCHACK : 1;
        uint32_t : 2;
        uint32_t DPLL_CLKOUT_GATE_CTRL : 2;
        uint32_t ST_DPLL_CLKOUT : 1;
        uint32_t : 22;
    };

    uint32_t value;
} CM_DIV_M2_DPLL_PER_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 16;
        uint32_t STBYST : 1;
        uint32_t : 13;
    };

    uint32_t value;
} CM_WKUP_WKUP_M3_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_WKUP_UART0_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_WKUP_I2C0_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_WKUP_ADC_TSC_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_WKUP_SMARTREFLEX0_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_WKUP_TIMER1_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_WKUP_SMARTREFLEX1_CLKCTRL_t;

typedef union {
    struct {
        uint32_t CLKTRCTRL : 2;
        uint32_t CLKACTIVITY_L4_WKUP_AON_GCLK : 1;
        uint32_t : 29;
    };

    uint32_t value;
} CM_L4_WKUP_AON_CLKSTCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_WKUP_WDT1_CLKCTRL_t;

typedef union {
    struct {
        uint32_t HSDIVIDER_CLKOUT3_DIV : 5;
        uint32_t HSDIVIDER_CLKOUT3_DIVCHACK : 1;
        uint32_t : 2;
        uint32_t HSDIVIDER_CLKOUT3_GATE_CTRL : 1;
        uint32_t ST_HSDIVIDER_CLKOUT3 : 1;
        uint32_t : 2;
        uint32_t HSDIVIDER_CLKOUT3_PWDN : 1;
        uint32_t : 19;
    };

    uint32_t value;
} CM_DIV_M6_DPLL_CORE_t;

// Define common field values.
#define CM_WKUP_MODULEMODE_DISABLE      0x0
#define CM_WKUP_MODULEMODE_ENABLE       0x2

#define CM_WKUP_CLKTRCTRL_NO_SLEEP      0x0
#define CM_WKUP_CLKTRCTRL_SW_SLEEP      0x1
#define CM_WKUP_CLKTRCTRL_SW_WKUP       0x2

#define CM_WKUP_CLK_INACTIVE            0x0
#define CM_WKUP_CLK_ACTIVE              0x1

#define CM_WKUP_IDLEST_FUNCTIONAL       0x0
#define CM_WKUP_IDLEST_TRANSITION       0x1
#define CM_WKUP_IDLEST_IDLE             0x2
#define CM_WKUP_IDLEST_DISABLED         0x3

#define CM_WKUP_STBYST_FUNCTIONAL       0x0
#define CM_WKUP_STBYST_STANDBY          0x1

// Define wakeup clock module registers.
#define CM_WKUP_REGISTERS_BASE          0x44e00400
#define CM_WKUP_CLKSTCTRL               REGISTER(CM_WKUP_CLKSTCTRL_t, (CM_WKUP_REGISTERS_BASE + 0x0))
#define CM_WKUP_CONTROL_CLKCTRL         REGISTER(CM_WKUP_CONTROL_CLKCTRL_t, (CM_WKUP_REGISTERS_BASE + 0x4))
#define CM_WKUP_GPIO0_CLKCTRL           REGISTER(CM_WKUP_GPIO0_CLKCTRL_t, (CM_WKUP_REGISTERS_BASE + 0x8))
#define CM_WKUP_L4WKUP_CLKCTRL          REGISTER(CM_WKUP_L4WKUP_CLKCTRL_t, (CM_WKUP_REGISTERS_BASE + 0xc))
#define CM_WKUP_TIMER0_CLKCTRL          REGISTER(CM_WKUP_TIMER0_CLKCTRL_t, (CM_WKUP_REGISTERS_BASE + 0x10))
#define CM_WKUP_DEBUGSS_CLKCTRL         REGISTER(CM_WKUP_DEBUGSS_CLKCTRL_t, (CM_WKUP_REGISTERS_BASE + 0x14))
#define CM_L3_AON_CLKSTCTRL             REGISTER(CM_L3_AON_CLKSTCTRL_t, (CM_WKUP_REGISTERS_BASE + 0x18))
#define CM_AUTOIDLE_DPLL_MPU            REGISTER(CM_AUTOIDLE_DPLL_MPU_t, (CM_WKUP_REGISTERS_BASE + 0x1c))
#define CM_IDLEST_DPLL_MPU              REGISTER(CM_IDLEST_DPLL_MPU_t, (CM_WKUP_REGISTERS_BASE + 0x20))
#define CM_SSC_DELTAMSTEP_DPLL_MPU      REGISTER(CM_SSC_DELTAMSTEP_DPLL_MPU_t, (CM_WKUP_REGISTERS_BASE + 0x24))
#define CM_SSC_MODFREQDIV_DPLL_MPU      REGISTER(CM_SSC_MODFREQDIV_DPLL_MPU_t, (CM_WKUP_REGISTERS_BASE + 0x28))
#define CM_CLKSEL_DPLL_MPU              REGISTER(CM_CLKSEL_DPLL_MPU_t, (CM_WKUP_REGISTERS_BASE + 0x2c))
#define CM_AUTOIDLE_DPLL_DDR            REGISTER(CM_AUTOIDLE_DPLL_DDR_t, (CM_WKUP_REGISTERS_BASE + 0x30))
#define CM_IDLEST_DPLL_DDR              REGISTER(CM_IDLEST_DPLL_DDR_t, (CM_WKUP_REGISTERS_BASE + 0x34))
#define CM_SSC_DELTAMSTEP_DPLL_DDR      REGISTER(CM_SSC_DELTAMSTEP_DPLL_DDR_t, (CM_WKUP_REGISTERS_BASE + 0x38))
#define CM_SSC_MODFREQDIV_DPLL_DDR      REGISTER(CM_SSC_MODFREQDIV_DPLL_DDR_t, (CM_WKUP_REGISTERS_BASE + 0x3c))
#define CM_CLKSEL_DPLL_DDR              REGISTER(CM_CLKSEL_DPLL_DDR_t, (CM_WKUP_REGISTERS_BASE + 0x40))
#define CM_AUTOIDLE_DPLL_DISP           REGISTER(CM_AUTOIDLE_DPLL_DISP_t, (CM_WKUP_REGISTERS_BASE + 0x44))
#define CM_IDLEST_DPLL_DISP             REGISTER(CM_IDLEST_DPLL_DISP_t, (CM_WKUP_REGISTERS_BASE + 0x48))
#define CM_SSC_DELTAMSTEP_DPLL_DISP     REGISTER(CM_SSC_DELTAMSTEP_DPLL_DISP_t, (CM_WKUP_REGISTERS_BASE + 0x4c))
#define CM_SSC_MODFREQDIV_DPLL_DISP     REGISTER(CM_SSC_MODFREQDIV_DPLL_DISP_t, (CM_WKUP_REGISTERS_BASE + 0x50))
#define CM_CLKSEL_DPLL_DISP             REGISTER(CM_CLKSEL_DPLL_DISP_t, (CM_WKUP_REGISTERS_BASE + 0x54))
#define CM_AUTOIDLE_DPLL_CORE           REGISTER(CM_AUTOIDLE_DPLL_CORE_t, (CM_WKUP_REGISTERS_BASE + 0x58))
#define CM_IDLEST_DPLL_CORE             REGISTER(CM_IDLEST_DPLL_CORE_t, (CM_WKUP_REGISTERS_BASE + 0x5c))
#define CM_SSC_DELTAMSTEP_DPLL_CORE     REGISTER(CM_SSC_DELTAMSTEP_DPLL_CORE_t, (CM_WKUP_REGISTERS_BASE + 0x60))
#define CM_SSC_MODFREQDIV_DPLL_CORE     REGISTER(CM_SSC_MODFREQDIV_DPLL_CORE_t, (CM_WKUP_REGISTERS_BASE + 0x64))
#define CM_CLKSEL_DPLL_CORE             REGISTER(CM_CLKSEL_DPLL_CORE_t, (CM_WKUP_REGISTERS_BASE + 0x68))
#define CM_AUTOIDLE_DPLL_PER            REGISTER(CM_AUTOIDLE_DPLL_PER_t, (CM_WKUP_REGISTERS_BASE + 0x6c))
#define CM_IDLEST_DPLL_PER              REGISTER(CM_IDLEST_DPLL_PER_t, (CM_WKUP_REGISTERS_BASE + 0x70))
#define CM_SSC_DELTAMSTEP_DPLL_PER      REGISTER(CM_SSC_DELTAMSTEP_DPLL_PER_t, (CM_WKUP_REGISTERS_BASE + 0x74))
#define CM_SSC_MODFREQDIV_DPLL_PER      REGISTER(CM_SSC_MODFREQDIV_DPLL_PER_t, (CM_WKUP_REGISTERS_BASE + 0x78))
#define CM_CLKDCOLDO_DPLL_PER           REGISTER(CM_CLKDCOLDO_DPLL_PER_t, (CM_WKUP_REGISTERS_BASE + 0x7c))
#define CM_DIV_M4_DPLL_CORE             REGISTER(CM_DIV_M4_DPLL_CORE_t, (CM_WKUP_REGISTERS_BASE + 0x80))
#define CM_DIV_M5_DPLL_CORE             REGISTER(CM_DIV_M5_DPLL_CORE_t, (CM_WKUP_REGISTERS_BASE + 0x84))
#define CM_CLKMODE_DPLL_MPU             REGISTER(CM_CLKMODE_DPLL_MPU_t, (CM_WKUP_REGISTERS_BASE + 0x88))
#define CM_CLKMODE_DPLL_PER             REGISTER(CM_CLKMODE_DPLL_PER_t, (CM_WKUP_REGISTERS_BASE + 0x8c))
#define CM_CLKMODE_DPLL_CORE            REGISTER(CM_CLKMODE_DPLL_CORE_t, (CM_WKUP_REGISTERS_BASE + 0x90))
#define CM_CLKMODE_DPLL_DDR             REGISTER(CM_CLKMODE_DPLL_DDR_t, (CM_WKUP_REGISTERS_BASE + 0x94))
#define CM_CLKMODE_DPLL_DISP            REGISTER(CM_CLKMODE_DPLL_DISP_t, (CM_WKUP_REGISTERS_BASE + 0x98))
#define CM_CLKSEL_DPLL_PERIPH           REGISTER(CM_CLKSEL_DPLL_PERIPH_t, (CM_WKUP_REGISTERS_BASE + 0x9c))
#define CM_DIV_M2_DPLL_DDR              REGISTER(CM_DIV_M2_DPLL_DDR_t, (CM_WKUP_REGISTERS_BASE + 0xa0))
#define CM_DIV_M2_DPLL_DISP             REGISTER(CM_DIV_M2_DPLL_DISP_t, (CM_WKUP_REGISTERS_BASE + 0xa4))
#define CM_DIV_M2_DPLL_MPU              REGISTER(CM_DIV_M2_DPLL_MPU_t, (CM_WKUP_REGISTERS_BASE + 0xa8))
#define CM_DIV_M2_DPLL_PER              REGISTER(CM_DIV_M2_DPLL_PER_t, (CM_WKUP_REGISTERS_BASE + 0xac))
#define CM_WKUP_WKUP_M3_CLKCTRL         REGISTER(CM_WKUP_WKUP_M3_CLKCTRL_t, (CM_WKUP_REGISTERS_BASE + 0xb0))
#define CM_WKUP_UART0_CLKCTRL           REGISTER(CM_WKUP_UART0_CLKCTRL_t, (CM_WKUP_REGISTERS_BASE + 0xb4))
#define CM_WKUP_I2C0_CLKCTRL            REGISTER(CM_WKUP_I2C0_CLKCTRL_t, (CM_WKUP_REGISTERS_BASE + 0xb8))
#define CM_WKUP_ADC_TSC_CLKCTRL         REGISTER(CM_WKUP_ADC_TSC_CLKCTRL_t, (CM_WKUP_REGISTERS_BASE + 0xbc))
#define CM_WKUP_SMARTREFLEX0_CLKCTRL    REGISTER(CM_WKUP_SMARTREFLEX0_CLKCTRL_t, (CM_WKUP_REGISTERS_BASE + 0xc0))
#define CM_WKUP_TIMER1_CLKCTRL          REGISTER(CM_WKUP_TIMER1_CLKCTRL_t, (CM_WKUP_REGISTERS_BASE + 0xc4))
#define CM_WKUP_SMARTREFLEX1_CLKCTRL    REGISTER(CM_WKUP_SMARTREFLEX1_CLKCTRL_t, (CM_WKUP_REGISTERS_BASE + 0xc8))
#define CM_L4_WKUP_AON_CLKSTCTRL        REGISTER(CM_L4_WKUP_AON_CLKSTCTRL_t, (CM_WKUP_REGISTERS_BASE + 0xcc))
#define CM_WKUP_WDT1_CLKCTRL            REGISTER(CM_WKUP_WDT1_CLKCTRL_t, (CM_WKUP_REGISTERS_BASE + 0xd4))
#define CM_DIV_M6_DPLL_CORE             REGISTER(CM_DIV_M6_DPLL_CORE_t, (CM_WKUP_REGISTERS_BASE + 0xd8))

} // namespace Device

#endif
