////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       11.12.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AM335X_CLOCK_REGS_PER_H
#define AM335X_CLOCK_REGS_PER_H

#include <os/utils.h>

#include <cstdint>

namespace Device {
namespace Clock {

////////////////////////////////////////////////////////////////////////////////////////////////
// REGISTER DEFINITIONS
////////////////////////////////////////////////////////////////////////////////////////////////

typedef union {
    struct {
        std::uint32_t CLKTRCTRL : 2;
        std::uint32_t _reserved1 : 6;
        std::uint32_t CLKACTIVITY_L4LS_GCLK : 1;
        std::uint32_t _reserved2 : 1;
        std::uint32_t CLKACTIVITY_UART_GFCLK : 1;
        std::uint32_t CLKACTIVITY_CAN_CLK : 1;
        std::uint32_t _reserved3 : 1;
        std::uint32_t CLKACTIVITY_TIMER7_GCLK : 1;
        std::uint32_t CLKACTIVITY_TIMER2_GCLK : 1;
        std::uint32_t CLKACTIVITY_TIMER3_GCLK : 1;
        std::uint32_t CLKACTIVITY_TIMER4_GCLK : 1;
        std::uint32_t CLKACTIVITY_LCDC_GCLK : 1;
        std::uint32_t _reserved4 : 1;
        std::uint32_t CLKACTIVITY_GPIO_1_GDBCLK : 1;
        std::uint32_t CLKACTIVITY_GPIO_2_GDBCLK : 1;
        std::uint32_t CLKACTIVITY_GPIO_3_GDBCLK : 1;
        std::uint32_t _reserved5 : 2;
        std::uint32_t CLKACTIVITY_I2C_FCLK : 1;
        std::uint32_t CLKACTIVITY_SPI_GCLK : 1;
        std::uint32_t _reserved6 : 1;
        std::uint32_t CLKACTIVITY_TIMER5_GCLK : 1;
        std::uint32_t CLKACTIVITY_TIMER6_GCLK : 1;
        std::uint32_t _reserved7 : 3;
    };

    std::uint32_t value;
} CM_PER_L4LS_CLKSTCTRL_t;

typedef union {
    struct {
        std::uint32_t CLKTRCTRL : 2;
        std::uint32_t _reserved1 : 1;
        std::uint32_t CLKACTIVITY_L3S_GCLK : 1;
        std::uint32_t _reserved2 : 28;
    };

    std::uint32_t value;
} CM_PER_L3S_CLKSTCTRL_t;

typedef union {
    struct {
        std::uint32_t CLKTRCTRL : 2;
        std::uint32_t CLKACTIVITY_EMIF_GCLK : 1;
        std::uint32_t CLKACTIVITY_MMC_FCLK : 1;
        std::uint32_t CLKACTIVITY_L3_GCLK : 1;
        std::uint32_t _reserved1 : 1;
        std::uint32_t CLKACTIVITY_CPTS_RFT_GCLK : 1;
        std::uint32_t CLKACTIVITY_MCASP_GCLK : 1;
        std::uint32_t _reserved2 : 24;
    };

    std::uint32_t value;
} CM_PER_L3_CLKSTCTRL_t;

typedef union {
    struct {
        std::uint32_t MODULEMODE : 2;
        std::uint32_t _reserved1 : 14;
        std::uint32_t IDLEST : 2;
        std::uint32_t _reserved2 : 14;
    };

    std::uint32_t value;
} CM_PER_UART5_CLKCTRL_t;

typedef union {
    struct {
        std::uint32_t MODULEMODE : 2;
        std::uint32_t _reserved1 : 14;
        std::uint32_t IDLEST : 2;
        std::uint32_t _reserved2 : 14;
    };

    std::uint32_t value;
} CM_PER_UART1_CLKCTRL_t;

typedef union {
    struct {
        std::uint32_t MODULEMODE : 2;
        std::uint32_t _reserved1 : 14;
        std::uint32_t IDLEST : 2;
        std::uint32_t _reserved2 : 14;
    };

    std::uint32_t value;
} CM_PER_UART2_CLKCTRL_t;

typedef union {
    struct {
        std::uint32_t MODULEMODE : 2;
        std::uint32_t _reserved1 : 14;
        std::uint32_t IDLEST : 2;
        std::uint32_t _reserved2 : 14;
    };

    std::uint32_t value;
} CM_PER_UART3_CLKCTRL_t;

typedef union {
    struct {
        std::uint32_t MODULEMODE : 2;
        std::uint32_t _reserved1 : 14;
        std::uint32_t IDLEST : 2;
        std::uint32_t _reserved2 : 14;
    };

    std::uint32_t value;
} CM_PER_UART4_CLKCTRL_t;

typedef union {
    struct {
        std::uint32_t MODULEMODE : 2;
        std::uint32_t _reserved1 : 14;
        std::uint32_t IDLEST : 2;
        std::uint32_t OPTFCLKEN_GPIO_1_GDBCLK : 1;
        std::uint32_t _reserved2 : 13;
    };

    std::uint32_t value;
} CM_PER_GPIO1_CLKCTRL_t;

typedef union {
    struct {
        std::uint32_t MODULEMODE : 2;
        std::uint32_t _reserved1 : 14;
        std::uint32_t IDLEST : 2;
        std::uint32_t OPTFCLKEN_GPIO_2_GDBCLK : 1;
        std::uint32_t _reserved2 : 13;
    };

    std::uint32_t value;
} CM_PER_GPIO2_CLKCTRL_t;

typedef union {
    struct {
        std::uint32_t MODULEMODE : 2;
        std::uint32_t _reserved1 : 14;
        std::uint32_t IDLEST : 2;
        std::uint32_t OPTFCLKEN_GPIO_3_GDBCLK : 1;
        std::uint32_t _reserved2 : 13;
    };

    std::uint32_t value;
} CM_PER_GPIO3_CLKCTRL_t;

typedef union {
    struct {
        std::uint32_t MODULEMODE : 2;
        std::uint32_t _reserved1 : 14;
        std::uint32_t IDLEST : 2;
        std::uint32_t _reserved2 : 14;
    };

    std::uint32_t value;
} CM_PER_L3_INSTR_CLKCTRL_t;

typedef union {
    struct {
        std::uint32_t MODULEMODE : 2;
        std::uint32_t _reserved1 : 14;
        std::uint32_t IDLEST : 2;
        std::uint32_t _reserved2 : 14;
    };

    std::uint32_t value;
} CM_PER_L3_CLKCTRL_t;

typedef union {
    struct {
        std::uint32_t CLKTRCTRL : 2;
        std::uint32_t _reserved1 : 2;
        std::uint32_t CLKACTIVITY_OCPWP_L3_GCLK : 1;
        std::uint32_t CLKACTIVITY_OCPWP_L4_GCLK : 1;
        std::uint32_t _reserved2 : 26;
    };

    std::uint32_t value;
} CM_PER_OCPWP_L3_CLKSTCTRL_t;

////////////////////////////////////////////////////////////////////////////////////////////////
// FIELD VALUES
////////////////////////////////////////////////////////////////////////////////////////////////

typedef enum {
    CM_PER_MODULEMODE_DISABLE = 0x0,
    CM_PER_MODULEMODE_ENABLE  = 0x2
} PerModulemode_t;

typedef enum {
    CM_PER_CLKTRCTRL_NO_SLEEP = 0x0,
    CM_PER_CLKTRCTRL_SW_SLEEP = 0x1,
    CM_PER_CLKTRCTRL_SW_WKUP  = 0x2
} PerClktrctrl_t;

typedef enum {
    CM_PER_CLK_INACTIVE = 0x0,
    CM_PER_CLK_ACTIVE   = 0x1
} PerClk_t;

typedef enum {
    CM_PER_IDLEST_FUNCTIONAL = 0x0,
    CM_PER_IDLEST_TRANSITION = 0x1,
    CM_PER_IDLEST_IDLE       = 0x2,
    CM_PER_IDLEST_DISABLED   = 0x3
} PerIdlest_t;

////////////////////////////////////////////////////////////////////////////////////////////////
// REGISTER ADDRESSES
////////////////////////////////////////////////////////////////////////////////////////////////

#define CM_PER_REGISTERS_BASE           0x44e00000

#define CM_PER_L4LS_CLKSTCTRL           REGISTER(CM_PER_L4LS_CLKSTCTRL_t, (CM_PER_REGISTERS_BASE + 0x0))
#define CM_PER_L3S_CLKSTCTRL            REGISTER(CM_PER_L3S_CLKSTCTRL_t, (CM_PER_REGISTERS_BASE + 0x4))
#define CM_PER_L3_CLKSTCTRL             REGISTER(CM_PER_L3_CLKSTCTRL_t, (CM_PER_REGISTERS_BASE + 0xc))
#define CM_PER_UART5_CLKCTRL            REGISTER(CM_PER_UART5_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x38))
#define CM_PER_UART1_CLKCTRL            REGISTER(CM_PER_UART1_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x6c))
#define CM_PER_UART2_CLKCTRL            REGISTER(CM_PER_UART2_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x70))
#define CM_PER_UART3_CLKCTRL            REGISTER(CM_PER_UART3_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x74))
#define CM_PER_UART4_CLKCTRL            REGISTER(CM_PER_UART4_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x78))
#define CM_PER_GPIO1_CLKCTRL            REGISTER(CM_PER_GPIO1_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0xac))
#define CM_PER_GPIO2_CLKCTRL            REGISTER(CM_PER_GPIO2_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0xb0))
#define CM_PER_GPIO3_CLKCTRL            REGISTER(CM_PER_GPIO3_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0xb4))
#define CM_PER_L3_INSTR_CLKCTRL         REGISTER(CM_PER_L3_INSTR_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0xdc))
#define CM_PER_L3_CLKCTRL               REGISTER(CM_PER_L3_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0xe0))
#define CM_PER_OCPWP_L3_CLKSTCTRL       REGISTER(CM_PER_OCPWP_L3_CLKSTCTRL_t, (CM_PER_REGISTERS_BASE + 0x12c))

} // namespace Clock
} // namespace Device

#endif
