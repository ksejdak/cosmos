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

#include <os/stdint.h>
#include <os/utils.h>

namespace Device {

typedef union {
    struct {
        uint32_t MINOR : 6;
        uint32_t CUSTOM : 2;
        uint32_t MAJOR : 3;
        uint32_t RTL : 5;
        uint32_t FUNC : 12;
        uint32_t : 2;
        uint32_t SCHEME : 2;
    };

    uint32_t value;
} GPIO_REVISION_t;

typedef union {
    struct {
        uint32_t AUTOIDLE : 1;
        uint32_t SOFTRESET : 1;
        uint32_t ENAWAKEUP : 1;
        uint32_t IDLEMODE : 2;
        uint32_t : 27;
    };

    uint32_t value;
} GPIO_SYSCONFIG_t;

typedef union {
    struct {
        uint32_t DMAEvent_Ack : 1;
        uint32_t : 31;
    };

    uint32_t value;
} GPIO_EOI_t;

typedef union {
    struct {
        uint32_t INTLINEn;
    };

    uint32_t value;
} GPIO_IRQSTATUS_RAW_0_t;

typedef union {
    struct {
        uint32_t INTLINEn;
    };

    uint32_t value;
} GPIO_IRQSTATUS_RAW_1_t;

typedef union {
    struct {
        uint32_t INTLINEn;
    };

    uint32_t value;
} GPIO_IRQSTATUS_0_t;

typedef union {
    struct {
        uint32_t INTLINEn;
    };

    uint32_t value;
} GPIO_IRQSTATUS_1_t;

typedef union {
    struct {
        uint32_t INTLINEn;
    };

    uint32_t value;
} GPIO_IRQSTATUS_SET_0_t;

typedef union {
    struct {
        uint32_t INTLINEn;
    };

    uint32_t value;
} GPIO_IRQSTATUS_SET_1_t;

typedef union {
    struct {
        uint32_t INTLINEn;
    };

    uint32_t value;
} GPIO_IRQSTATUS_CLR_0_t;

typedef union {
    struct {
        uint32_t INTLINEn;
    };

    uint32_t value;
} GPIO_IRQSTATUS_CLR_1_t;

typedef union {
    struct {
        uint32_t INTLINEn;
    };

    uint32_t value;
} GPIO_IRQWAKEN_0_t;

typedef union {
    struct {
        uint32_t INTLINEn;
    };

    uint32_t value;
} GPIO_IRQWAKEN_1_t;

typedef union {
    struct {
        uint32_t RESETDONE : 1;
        uint32_t : 31;
    };

    uint32_t value;
} GPIO_SYSSTATUS_t;

typedef union {
    struct {
        uint32_t DISABLEMODULE : 1;
        uint32_t GATINGRATIO : 2;
        uint32_t : 29;
    };

    uint32_t value;
} GPIO_CTRL_t;

typedef union {
    struct {
        uint32_t OUTPUTENn;
    };

    uint32_t value;
} GPIO_OE_t;

typedef union {
    struct {
        uint32_t DATAINn;
    };

    uint32_t value;
} GPIO_DATAIN_t;

typedef union {
    struct {
        uint32_t DATAOUTn;
    };

    uint32_t value;
} GPIO_DATAOUT_t;

typedef union {
    struct {
        uint32_t LEVELDETECT0n;
    };

    uint32_t value;
} GPIO_LEVELDETECT0_t;

typedef union {
    struct {
        uint32_t LEVELDETECT1n;
    };

    uint32_t value;
} GPIO_LEVELDETECT1_t;

typedef union {
    struct {
        uint32_t RISINGDETECTn;
    };

    uint32_t value;
} GPIO_RISINGDETECT_t;

typedef union {
    struct {
        uint32_t FALLINGDETECTn;
    };

    uint32_t value;
} GPIO_FALLINGDETECT_t;

typedef union {
    struct {
        uint32_t DEBOUNCEENABLEn;
    };

    uint32_t value;
} GPIO_DEBOUNCENABLE_t;

typedef union {
    struct {
        uint32_t DEBOUNCETIME : 8;
        uint32_t : 24;
    };

    uint32_t value;
} GPIO_DEBOUNCINGTIME_t;

typedef union {
    struct {
        uint32_t INTLINEn;
    };

    uint32_t value;
} GPIO_CLEARDATAOUT_t;

typedef union {
    struct {
        uint32_t INTLINEn;
    };

    uint32_t value;
} GPIO_SETDATAOUT_t;

// Define gpio module registers.
#define GPIO_0_BASE                         0x44e07000
#define GPIO_1_BASE                         0x4804c000
#define GPIO_2_BASE                         0x481ac000
#define GPIO_3_BASE                         0x481ae000

#define GPIO_REVISION(GPIO_BASE)            REGISTER(GPIO_REVISION_t, (GPIO_BASE + 0x0))
#define GPIO_SYSCONFIG(GPIO_BASE)           REGISTER(GPIO_SYSCONFIG_t, (GPIO_BASE + 0x10))
#define GPIO_EOI(GPIO_BASE)                 REGISTER(GPIO_EOI_t, (GPIO_BASE + 0x20))
#define GPIO_IRQSTATUS_RAW_0(GPIO_BASE)     REGISTER(GPIO_IRQSTATUS_RAW_0_t, (GPIO_BASE + 0x24))
#define GPIO_IRQSTATUS_RAW_1(GPIO_BASE)     REGISTER(GPIO_IRQSTATUS_RAW_1_t, (GPIO_BASE + 0x28))
#define GPIO_IRQSTATUS_0(GPIO_BASE)         REGISTER(GPIO_IRQSTATUS_0_t, (GPIO_BASE + 0x2c))
#define GPIO_IRQSTATUS_1(GPIO_BASE)         REGISTER(GPIO_IRQSTATUS_1_t, (GPIO_BASE + 0x30))
#define GPIO_IRQSTATUS_SET_0(GPIO_BASE)     REGISTER(GPIO_IRQSTATUS_SET_0_t, (GPIO_BASE + 0x34))
#define GPIO_IRQSTATUS_SET_1(GPIO_BASE)     REGISTER(GPIO_IRQSTATUS_SET_1_t, (GPIO_BASE + 0x38))
#define GPIO_IRQSTATUS_CLR_0(GPIO_BASE)     REGISTER(GPIO_IRQSTATUS_CLR_0_t, (GPIO_BASE + 0x3c))
#define GPIO_IRQSTATUS_CLR_1(GPIO_BASE)     REGISTER(GPIO_IRQSTATUS_CLR_1_t, (GPIO_BASE + 0x40))
#define GPIO_IRQWAKEN_0(GPIO_BASE)          REGISTER(GPIO_IRQWAKEN_0_t, (GPIO_BASE + 0x44))
#define GPIO_IRQWAKEN_1(GPIO_BASE)          REGISTER(GPIO_IRQWAKEN_1_t, (GPIO_BASE + 0x48))
#define GPIO_SYSSTATUS(GPIO_BASE)           REGISTER(GPIO_SYSSTATUS_t, (GPIO_BASE + 0x114))
#define GPIO_CTRL(GPIO_BASE)                REGISTER(GPIO_CTRL_t, (GPIO_BASE + 0x130))
#define GPIO_OE(GPIO_BASE)                  REGISTER(GPIO_OE_t, (GPIO_BASE + 0x134))
#define GPIO_DATAIN(GPIO_BASE)              REGISTER(GPIO_DATAIN_t, (GPIO_BASE + 0x138))
#define GPIO_DATAOUT(GPIO_BASE)             REGISTER(GPIO_DATAOUT_t, (GPIO_BASE + 0x13c))
#define GPIO_LEVELDETECT0(GPIO_BASE)        REGISTER(GPIO_LEVELDETECT0_t, (GPIO_BASE + 0x140))
#define GPIO_LEVELDETECT1(GPIO_BASE)        REGISTER(GPIO_LEVELDETECT1_t, (GPIO_BASE + 0x144))
#define GPIO_RISINGDETECT(GPIO_BASE)        REGISTER(GPIO_RISINGDETECT_t, (GPIO_BASE + 0x148))
#define GPIO_FALLINGDETECT(GPIO_BASE)       REGISTER(GPIO_FALLINGDETECT_t, (GPIO_BASE + 0x14c))
#define GPIO_DEBOUNCENABLE(GPIO_BASE)       REGISTER(GPIO_DEBOUNCENABLE_t, (GPIO_BASE + 0x150))
#define GPIO_DEBOUNCINGTIME(GPIO_BASE)      REGISTER(GPIO_DEBOUNCINGTIME_t, (GPIO_BASE + 0x154))
#define GPIO_CLEARDATAOUT(GPIO_BASE)        REGISTER(GPIO_CLEARDATAOUT_t, (GPIO_BASE + 0x190))
#define GPIO_SETDATAOUT(GPIO_BASE)          REGISTER(GPIO_SETDATAOUT_t, (GPIO_BASE + 0x194))

} // namespace Device

#endif
