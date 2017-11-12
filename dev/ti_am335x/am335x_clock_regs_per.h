////////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2017, Kuba Sejdak <kuba.sejdak@gmail.com>
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
////////////////////////////////////////////////////////////////////////////////////

#ifndef AM335X_CLOCK_REGS_PER_H
#define AM335X_CLOCK_REGS_PER_H

#include <os/utils.h>

#include <cstdint>

namespace Device::Clock {

////////////////////////////////////////////////////////////////////////////////////
// REGISTER DEFINITIONS
////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////
// FIELD VALUES
////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////
// REGISTER ADDRESSES
////////////////////////////////////////////////////////////////////////////////////

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

} // namespace Device::Clock

#endif
