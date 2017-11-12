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

#ifndef AM335X_CLOCK_REGS_WKUP_H
#define AM335X_CLOCK_REGS_WKUP_H

#include <os/utils.h>

#include <cstdint>

namespace Device::Clock {

////////////////////////////////////////////////////////////////////////////////////
// REGISTER DEFINITIONS
////////////////////////////////////////////////////////////////////////////////////

typedef union {
    struct {
        std::uint32_t CLKTRCTRL : 2;
        std::uint32_t CLKACTIVITY_L4_WKUP_GCLK : 1;
        std::uint32_t CLKACTIVITY_SR_SYSCLK : 1;
        std::uint32_t CLKACTIVITY_WDT1_CLK : 1;
        std::uint32_t _reserved1 : 3;
        std::uint32_t CLKACTIVITY_GPIO0_GDBCLK : 1;
        std::uint32_t _reserved2 : 1;
        std::uint32_t CLKACTIVITY_TIMER0_GCLK : 1;
        std::uint32_t CLKACTIVITY_I2C0_GFCLK : 1;
        std::uint32_t CLKACTIVITY_UART0_GFCLK : 1;
        std::uint32_t CLKACTIVITY_TIMER1_GCLK : 1;
        std::uint32_t CLKACTIVITY_ADC_FCLK : 1;
        std::uint32_t _reserved3 : 17;
    };

    std::uint32_t value;
} CM_WKUP_CLKSTCTRL_t;

typedef union {
    struct {
        std::uint32_t MODULEMODE : 2;
        std::uint32_t _reserved1 : 14;
        std::uint32_t IDLEST : 2;
        std::uint32_t _reserved2 : 14;
    };

    std::uint32_t value;
} CM_WKUP_CONTROL_CLKCTRL_t;

typedef union {
    struct {
        std::uint32_t MODULEMODE : 2;
        std::uint32_t _reserved1 : 14;
        std::uint32_t IDLEST : 2;
        std::uint32_t OPTFCLKEN_GPIO0_GDBCLK : 1;
        std::uint32_t _reserved2 : 13;
    };

    std::uint32_t value;
} CM_WKUP_GPIO0_CLKCTRL_t;

typedef union {
    struct {
        std::uint32_t MODULEMODE : 2;
        std::uint32_t _reserved1 : 14;
        std::uint32_t IDLEST : 2;
        std::uint32_t _reserved2 : 14;
    };

    std::uint32_t value;
} CM_WKUP_L4WKUP_CLKCTRL_t;

typedef union {
    struct {
        std::uint32_t CLKTRCTRL : 2;
        std::uint32_t CLKACTIVITY_DBGSYSCLK : 1;
        std::uint32_t CLKACTIVITY_L3_AON_GCLK : 1;
        std::uint32_t CLKACTIVITY_DEBUG_CLKA : 1;
        std::uint32_t _reserved : 27;
    };

    std::uint32_t value;
} CM_L3_AON_CLKSTCTRL_t;

typedef union {
    struct {
        std::uint32_t MODULEMODE : 2;
        std::uint32_t _reserved1 : 14;
        std::uint32_t IDLEST : 2;
        std::uint32_t _reserved2 : 14;
    };

    std::uint32_t value;
} CM_WKUP_UART0_CLKCTRL_t;

typedef union {
    struct {
        std::uint32_t CLKTRCTRL : 2;
        std::uint32_t CLKACTIVITY_L4_WKUP_AON_GCLK : 1;
        std::uint32_t _reserved : 29;
    };

    std::uint32_t value;
} CM_L4_WKUP_AON_CLKSTCTRL_t;

////////////////////////////////////////////////////////////////////////////////////
// FIELD VALUES
////////////////////////////////////////////////////////////////////////////////////

typedef enum {
    CM_WKUP_MODULEMODE_DISABLE = 0x0,
    CM_WKUP_MODULEMODE_ENABLE  = 0x2
} WkupModulemode_t;

typedef enum {
    CM_WKUP_CLKTRCTRL_NO_SLEEP = 0x0,
    CM_WKUP_CLKTRCTRL_SW_SLEEP = 0x1,
    CM_WKUP_CLKTRCTRL_SW_WKUP  = 0x2
} WkupClktrctrl_t;

typedef enum {
    CM_WKUP_CLK_INACTIVE = 0x0,
    CM_WKUP_CLK_ACTIVE   = 0x1
} WkupClk_t;

typedef enum {
    CM_WKUP_IDLEST_FUNCTIONAL = 0x0,
    CM_WKUP_IDLEST_TRANSITION = 0x1,
    CM_WKUP_IDLEST_IDLE       = 0x2,
    CM_WKUP_IDLEST_DISABLED   = 0x3
} WkupIdlest_t;

////////////////////////////////////////////////////////////////////////////////////
// REGISTER ADDRESSES
////////////////////////////////////////////////////////////////////////////////////

#define CM_WKUP_REGISTERS_BASE          0x44e00400

#define CM_WKUP_CLKSTCTRL               REGISTER(CM_WKUP_CLKSTCTRL_t, (CM_WKUP_REGISTERS_BASE + 0x0))
#define CM_WKUP_CONTROL_CLKCTRL         REGISTER(CM_WKUP_CONTROL_CLKCTRL_t, (CM_WKUP_REGISTERS_BASE + 0x4))
#define CM_WKUP_GPIO0_CLKCTRL           REGISTER(CM_WKUP_GPIO0_CLKCTRL_t, (CM_WKUP_REGISTERS_BASE + 0x8))
#define CM_WKUP_L4WKUP_CLKCTRL          REGISTER(CM_WKUP_L4WKUP_CLKCTRL_t, (CM_WKUP_REGISTERS_BASE + 0xc))
#define CM_L3_AON_CLKSTCTRL             REGISTER(CM_L3_AON_CLKSTCTRL_t, (CM_WKUP_REGISTERS_BASE + 0x18))
#define CM_WKUP_UART0_CLKCTRL           REGISTER(CM_WKUP_UART0_CLKCTRL_t, (CM_WKUP_REGISTERS_BASE + 0xb4))
#define CM_L4_WKUP_AON_CLKSTCTRL        REGISTER(CM_L4_WKUP_AON_CLKSTCTRL_t, (CM_WKUP_REGISTERS_BASE + 0xcc))

} // namespace Device::Clock

#endif
