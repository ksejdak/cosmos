////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       26.12.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AM335X_GPIO_REGS_H
#define AM335X_GPIO_REGS_H

#include <os/utils.h>

#include <cstdint>

namespace Device::GPIO {

////////////////////////////////////////////////////////////////////////////////////////////////
// REGISTER DEFINITIONS
////////////////////////////////////////////////////////////////////////////////////////////////

typedef union {
    struct {
        bool AUTOIDLE : 1;
        bool SOFTRESET : 1;
        bool ENAWAKEUP : 1;
        std::uint32_t IDLEMODE : 2;
        std::uint32_t _reserved : 27;
    };

    std::uint32_t value;
} GPIO_SYSCONFIG_t;

typedef union {
    struct {
        bool RESETDONE : 1;
        std::uint32_t _reserved : 31;
    };

    std::uint32_t value;
} GPIO_SYSSTATUS_t;

typedef union {
    struct {
        bool DISABLEMODULE : 1;
        std::uint32_t GATINGRATIO : 2;
        std::uint32_t _reserved : 29;
    };

    std::uint32_t value;
} GPIO_CTRL_t;

typedef union {
    struct {
        std::uint32_t OUTPUTENn;
    };

    std::uint32_t value;
} GPIO_OE_t;

typedef union {
    struct {
        std::uint32_t DATAINn;
    };

    std::uint32_t value;
} GPIO_DATAIN_t;

typedef union {
    struct {
        std::uint32_t DATAOUTn;
    };

    std::uint32_t value;
} GPIO_DATAOUT_t;

typedef union {
    struct {
        std::uint32_t INTLINEn;
    };

    std::uint32_t value;
} GPIO_CLEARDATAOUT_t;

typedef union {
    struct {
        std::uint32_t INTLINEn;
    };

    std::uint32_t value;
} GPIO_SETDATAOUT_t;

////////////////////////////////////////////////////////////////////////////////////////////////
// REGISTER ADDRESSES
////////////////////////////////////////////////////////////////////////////////////////////////

#define GPIO_0_BASE                         0x44e07000
#define GPIO_1_BASE                         0x4804c000
#define GPIO_2_BASE                         0x481ac000
#define GPIO_3_BASE                         0x481ae000

#define GPIO_SYSCONFIG(GPIO_BASE)           REGISTER(GPIO_SYSCONFIG_t, (GPIO_BASE + 0x10))
#define GPIO_SYSSTATUS(GPIO_BASE)           REGISTER(GPIO_SYSSTATUS_t, (GPIO_BASE + 0x114))
#define GPIO_CTRL(GPIO_BASE)                REGISTER(GPIO_CTRL_t, (GPIO_BASE + 0x130))
#define GPIO_OE(GPIO_BASE)                  REGISTER(GPIO_OE_t, (GPIO_BASE + 0x134))
#define GPIO_DATAIN(GPIO_BASE)              REGISTER(GPIO_DATAIN_t, (GPIO_BASE + 0x138))
#define GPIO_DATAOUT(GPIO_BASE)             REGISTER(GPIO_DATAOUT_t, (GPIO_BASE + 0x13c))
#define GPIO_CLEARDATAOUT(GPIO_BASE)        REGISTER(GPIO_CLEARDATAOUT_t, (GPIO_BASE + 0x190))
#define GPIO_SETDATAOUT(GPIO_BASE)          REGISTER(GPIO_SETDATAOUT_t, (GPIO_BASE + 0x194))

} // namespace Device::GPIO

#endif
