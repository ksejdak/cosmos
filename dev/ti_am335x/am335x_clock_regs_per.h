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

#include <os/stdint.h>
#include <os/utils.h>

namespace Device {
namespace Clock {
namespace AM335x {

////////////////////////////////////////////////////////////////////////////////////////////////
// REGISTER DEFINITIONS
////////////////////////////////////////////////////////////////////////////////////////////////

typedef union {
    struct {
        uint32_t CLKTRCTRL : 2;
        uint32_t : 6;
        uint32_t CLKACTIVITY_L4LS_GCLK : 1;
        uint32_t : 1;
        uint32_t CLKACTIVITY_UART_GFCLK : 1;
        uint32_t CLKACTIVITY_CAN_CLK : 1;
        uint32_t : 1;
        uint32_t CLKACTIVITY_TIMER7_GCLK : 1;
        uint32_t CLKACTIVITY_TIMER2_GCLK : 1;
        uint32_t CLKACTIVITY_TIMER3_GCLK : 1;
        uint32_t CLKACTIVITY_TIMER4_GCLK : 1;
        uint32_t CLKACTIVITY_LCDC_GCLK : 1;
        uint32_t : 1;
        uint32_t CLKACTIVITY_GPIO_1_GDBCLK : 1;
        uint32_t CLKACTIVITY_GPIO_2_GDBCLK : 1;
        uint32_t CLKACTIVITY_GPIO_3_GDBCLK : 1;
        uint32_t : 2;
        uint32_t CLKACTIVITY_I2C_FCLK : 1;
        uint32_t CLKACTIVITY_SPI_GCLK : 1;
        uint32_t : 1;
        uint32_t CLKACTIVITY_TIMER5_GCLK : 1;
        uint32_t CLKACTIVITY_TIMER6_GCLK : 1;
        uint32_t : 3;
    };

    uint32_t value;
} CM_PER_L4LS_CLKSTCTRL_t;

typedef union {
    struct {
        uint32_t CLKTRCTRL : 2;
        uint32_t : 1;
        uint32_t CLKACTIVITY_L3S_GCLK : 1;
        uint32_t : 28;
    };

    uint32_t value;
} CM_PER_L3S_CLKSTCTRL_t;

typedef union {
    struct {
        uint32_t CLKTRCTRL : 2;
        uint32_t CLKACTIVITY_EMIF_GCLK : 1;
        uint32_t CLKACTIVITY_MMC_FCLK : 1;
        uint32_t CLKACTIVITY_L3_GCLK : 1;
        uint32_t : 1;
        uint32_t CLKACTIVITY_CPTS_RFT_GCLK : 1;
        uint32_t CLKACTIVITY_MCASP_GCLK : 1;
        uint32_t : 24;
    };

    uint32_t value;
} CM_PER_L3_CLKSTCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t STBYST : 1;
        uint32_t : 13;
    };

    uint32_t value;
} CM_PER_CPGMAC0_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t STBYST : 1;
        uint32_t : 13;
    };

    uint32_t value;
} CM_PER_LCDC_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t STBYST : 1;
        uint32_t : 13;
    };

    uint32_t value;
} CM_PER_USB0_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t STBYST : 1;
        uint32_t : 13;
    };

    uint32_t value;
} CM_PER_TPTC0_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_EMIF_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_OCMCRAM_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_GPMC_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_MCASP0_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_UART5_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_MMC0_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_ELM_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_I2C2_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_I2C1_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_SPI0_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_SPI1_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_L4LS_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_MCASP1_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_UART1_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_UART2_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_UART3_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_UART4_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_TIMER7_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_TIMER2_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_TIMER3_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_TIMER4_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t OPTFCLKEN_GPIO_1_GDBCLK : 1;
        uint32_t : 13;
    };

    uint32_t value;
} CM_PER_GPIO1_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t OPTFCLKEN_GPIO_2_GDBCLK : 1;
        uint32_t : 13;
    };

    uint32_t value;
} CM_PER_GPIO2_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t OPTFCLKEN_GPIO_3_GDBCLK : 1;
        uint32_t : 13;
    };

    uint32_t value;
} CM_PER_GPIO3_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_TPCC_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_DCAN0_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_DCAN1_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_EPWMSS1_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_EPWMSS0_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_EPWMSS2_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_L3_INSTR_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_L3_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t STBYST : 1;
        uint32_t : 13;
    };

    uint32_t value;
} CM_PER_IEEE5000_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t STBYST : 1;
        uint32_t : 13;
    };

    uint32_t value;
} CM_PER_PRU_ICSS_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_TIMER5_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_TIMER6_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_MMC1_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_MMC2_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t STBYST : 1;
        uint32_t : 13;
    };

    uint32_t value;
} CM_PER_TPTC1_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t STBYST : 1;
        uint32_t : 13;
    };

    uint32_t value;
} CM_PER_TPTC2_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_SPINLOCK_CLKCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_MAILBOX0_CLKCTRL_t;

typedef union {
    struct {
        uint32_t CLKTRCTRL : 2;
        uint32_t : 1;
        uint32_t CLKACTIVITY_L4HS_GCLK : 1;
        uint32_t CLKACTIVITY_CPSW_250MHZ_GCLK : 1;
        uint32_t CLKACTIVITY_CPSW_50MHZ_GCLK : 1;
        uint32_t CLKACTIVITY_CPSW_5MHZ_GCLK : 1;
        uint32_t : 25;
    };

    uint32_t value;
} CM_PER_L4HS_CLKSTCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_L4HS_CLKCTRL_t;

typedef union {
    struct {
        uint32_t CLKTRCTRL : 2;
        uint32_t : 2;
        uint32_t CLKACTIVITY_OCPWP_L3_GCLK : 1;
        uint32_t CLKACTIVITY_OCPWP_L4_GCLK : 1;
        uint32_t : 26;
    };

    uint32_t value;
} CM_PER_OCPWP_L3_CLKSTCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t STBYST : 1;
        uint32_t : 13;
    };

    uint32_t value;
} CM_PER_OCPWP_CLKCTRL_t;

typedef union {
    struct {
        uint32_t CLKTRCTRL : 2;
        uint32_t : 2;
        uint32_t CLKACTIVITY_PRU_ICSS_OCP_GCLK : 1;
        uint32_t CLKACTIVITY_PRU_ICSS_IEP_GCLK : 1;
        uint32_t CLKACTIVITY_PRU_ICSS_UART_GCLK : 1;
        uint32_t : 25;
    };

    uint32_t value;
} CM_PER_PRU_ICSS_CLKSTCTRL_t;

typedef union {
    struct {
        uint32_t CLKTRCTRL : 2;
        uint32_t : 2;
        uint32_t CLKACTIVITY_CPSW_125MHz_GCLK : 1;
        uint32_t : 27;
    };

    uint32_t value;
} CM_PER_CPSW_CLKSTCTRL_t;

typedef union {
    struct {
        uint32_t CLKTRCTRL : 2;
        uint32_t : 2;
        uint32_t CLKACTIVITY_LCDC_L3_OCP_GCLK : 1;
        uint32_t CLKACTIVITY_LCDC_L4_OCP_GCLK : 1;
        uint32_t : 26;
    };

    uint32_t value;
} CM_PER_LCDC_CLKSTCTRL_t;

typedef union {
    struct {
        uint32_t MODULEMODE : 2;
        uint32_t : 14;
        uint32_t IDLEST : 2;
        uint32_t : 14;
    };

    uint32_t value;
} CM_PER_CLKDIV32K_CLKCTRL_t;

typedef union {
    struct {
        uint32_t CLKTRCTRL: 2;
        uint32_t : 2;
        uint32_t CLKACTIVITY_CLK_24MHZ_GCLK : 1;
        uint32_t : 27;
    };

    uint32_t value;
} CM_PER_CLK_24MHZ_CLKSTCTRL_t;

////////////////////////////////////////////////////////////////////////////////////////////////
// FIELD VALUES
////////////////////////////////////////////////////////////////////////////////////////////////

typedef enum {
    CM_PER_MODULEMODE_DISABLE = 0x0,
    CM_PER_MODULEMODE_ENABLE  = 0x2
} AM335x_ClockPerModulemode_t;

typedef enum {
    CM_PER_CLKTRCTRL_NO_SLEEP = 0x0,
    CM_PER_CLKTRCTRL_SW_SLEEP = 0x1,
    CM_PER_CLKTRCTRL_SW_WKUP  = 0x2
} AM335x_ClockPerClktrctrl_t;

typedef enum {
    CM_PER_CLK_INACTIVE = 0x0,
    CM_PER_CLK_ACTIVE   = 0x1
} AM335x_ClockPerClk_t;

typedef enum {
    CM_PER_IDLEST_FUNCTIONAL = 0x0,
    CM_PER_IDLEST_TRANSITION = 0x1,
    CM_PER_IDLEST_IDLE       = 0x2,
    CM_PER_IDLEST_DISABLED   = 0x3
} AM335x_ClockPerIdlest_t;

typedef enum {
    CM_PER_STBYST_FUNCTIONAL = 0x0,
    CM_PER_STBYST_STANDBY    = 0x1
} AM335x_ClockPerStbyst_t;

////////////////////////////////////////////////////////////////////////////////////////////////
// REGISTER ADDRESSES
////////////////////////////////////////////////////////////////////////////////////////////////

#define CM_PER_REGISTERS_BASE           0x44e00000

#define CM_PER_L4LS_CLKSTCTRL           REGISTER(CM_PER_L4LS_CLKSTCTRL_t, (CM_PER_REGISTERS_BASE + 0x0))
#define CM_PER_L3S_CLKSTCTRL            REGISTER(CM_PER_L3S_CLKSTCTRL_t, (CM_PER_REGISTERS_BASE + 0x4))
#define CM_PER_L3_CLKSTCTRL             REGISTER(CM_PER_L3_CLKSTCTRL_t, (CM_PER_REGISTERS_BASE + 0xc))
#define CM_PER_CPGMAC0_CLKCTRL          REGISTER(CM_PER_CPGMAC0_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x14))
#define CM_PER_LCDC_CLKCTRL             REGISTER(CM_PER_LCDC_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x18))
#define CM_PER_USB0_CLKCTRL             REGISTER(CM_PER_USB0_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x1c))
#define CM_PER_TPTC0_CLKCTRL            REGISTER(CM_PER_TPTC0_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x24))
#define CM_PER_EMIF_CLKCTRL             REGISTER(CM_PER_EMIF_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x28))
#define CM_PER_OCMCRAM_CLKCTRL          REGISTER(CM_PER_OCMCRAM_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x2c))
#define CM_PER_GPMC_CLKCTRL             REGISTER(CM_PER_GPMC_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x30))
#define CM_PER_MCASP0_CLKCTRL           REGISTER(CM_PER_MCASP0_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x34))
#define CM_PER_UART5_CLKCTRL            REGISTER(CM_PER_UART5_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x38))
#define CM_PER_MMC0_CLKCTRL             REGISTER(CM_PER_MMC0_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x3c))
#define CM_PER_ELM_CLKCTRL              REGISTER(CM_PER_ELM_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x40))
#define CM_PER_I2C2_CLKCTRL             REGISTER(CM_PER_I2C2_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x44))
#define CM_PER_I2C1_CLKCTRL             REGISTER(CM_PER_I2C1_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x48))
#define CM_PER_SPI0_CLKCTRL             REGISTER(CM_PER_SPI0_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x4c))
#define CM_PER_SPI1_CLKCTRL             REGISTER(CM_PER_SPI1_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x50))
#define CM_PER_L4LS_CLKCTRL             REGISTER(CM_PER_L4LS_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x60))
#define CM_PER_MCASP1_CLKCTRL           REGISTER(CM_PER_MCASP1_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x68))
#define CM_PER_UART1_CLKCTRL            REGISTER(CM_PER_UART1_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x6c))
#define CM_PER_UART2_CLKCTRL            REGISTER(CM_PER_UART2_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x70))
#define CM_PER_UART3_CLKCTRL            REGISTER(CM_PER_UART3_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x74))
#define CM_PER_UART4_CLKCTRL            REGISTER(CM_PER_UART4_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x78))
#define CM_PER_TIMER7_CLKCTRL           REGISTER(CM_PER_TIMER7_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x7c))
#define CM_PER_TIMER2_CLKCTRL           REGISTER(CM_PER_TIMER2_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x80))
#define CM_PER_TIMER3_CLKCTRL           REGISTER(CM_PER_TIMER3_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x84))
#define CM_PER_TIMER4_CLKCTRL           REGISTER(CM_PER_TIMER4_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x88))
#define CM_PER_GPIO1_CLKCTRL            REGISTER(CM_PER_GPIO1_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0xac))
#define CM_PER_GPIO2_CLKCTRL            REGISTER(CM_PER_GPIO2_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0xb0))
#define CM_PER_GPIO3_CLKCTRL            REGISTER(CM_PER_GPIO3_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0xb4))
#define CM_PER_TPCC_CLKCTRL             REGISTER(CM_PER_TPCC_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0xbc))
#define CM_PER_DCAN0_CLKCTRL            REGISTER(CM_PER_DCAN0_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0xc0))
#define CM_PER_DCAN1_CLKCTRL            REGISTER(CM_PER_DCAN1_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0xc4))
#define CM_PER_EPWMSS1_CLKCTRL          REGISTER(CM_PER_EPWMSS1_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0xcc))
#define CM_PER_EPWMSS0_CLKCTRL          REGISTER(CM_PER_EPWMSS0_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0xd4))
#define CM_PER_EPWMSS2_CLKCTRL          REGISTER(CM_PER_EPWMSS2_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0xd8))
#define CM_PER_L3_INSTR_CLKCTRL         REGISTER(CM_PER_L3_INSTR_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0xdc))
#define CM_PER_L3_CLKCTRL               REGISTER(CM_PER_L3_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0xe0))
#define CM_PER_IEEE5000_CLKCTRL         REGISTER(CM_PER_IEEE5000_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0xe4))
#define CM_PER_PRU_ICSS_CLKCTRL         REGISTER(CM_PER_PRU_ICSS_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0xe8))
#define CM_PER_TIMER5_CLKCTRL           REGISTER(CM_PER_TIMER5_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0xec))
#define CM_PER_TIMER6_CLKCTRL           REGISTER(CM_PER_TIMER6_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0xf0))
#define CM_PER_MMC1_CLKCTRL             REGISTER(CM_PER_MMC1_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0xf4))
#define CM_PER_MMC2_CLKCTRL             REGISTER(CM_PER_MMC2_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0xf8))
#define CM_PER_TPTC1_CLKCTRL            REGISTER(CM_PER_TPTC1_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0xfc))
#define CM_PER_TPTC2_CLKCTRL            REGISTER(CM_PER_TPTC2_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x100))
#define CM_PER_SPINLOCK_CLKCTRL         REGISTER(CM_PER_SPINLOCK_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x10c))
#define CM_PER_MAILBOX0_CLKCTRL         REGISTER(CM_PER_MAILBOX0_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x110))
#define CM_PER_L4HS_CLKSTCTRL           REGISTER(CM_PER_L4HS_CLKSTCTRL_t, (CM_PER_REGISTERS_BASE + 0x11c))
#define CM_PER_L4HS_CLKCTRL             REGISTER(CM_PER_L4HS_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x120))
#define CM_PER_OCPWP_L3_CLKSTCTRL       REGISTER(CM_PER_OCPWP_L3_CLKSTCTRL_t, (CM_PER_REGISTERS_BASE + 0x12c))
#define CM_PER_OCPWP_CLKCTRL            REGISTER(CM_PER_OCPWP_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x130))
#define CM_PER_PRU_ICSS_CLKSTCTRL       REGISTER(CM_PER_PRU_ICSS_CLKSTCTRL_t, (CM_PER_REGISTERS_BASE + 0x140))
#define CM_PER_CPSW_CLKSTCTRL           REGISTER(CM_PER_CPSW_CLKSTCTRL_t, (CM_PER_REGISTERS_BASE + 0x144))
#define CM_PER_LCDC_CLKSTCTRL           REGISTER(CM_PER_LCDC_CLKSTCTRL_t, (CM_PER_REGISTERS_BASE + 0x148))
#define CM_PER_CLKDIV32K_CLKCTRL        REGISTER(CM_PER_CLKDIV32K_CLKCTRL_t, (CM_PER_REGISTERS_BASE + 0x14c))
#define CM_PER_CLK_24MHZ_CLKSTCTRL      REGISTER(CM_PER_CLK_24MHZ_CLKSTCTRL_t, (CM_PER_REGISTERS_BASE + 0x150))

} // namespace AM335x
} // namespace Clock
} // namespace Device

#endif
