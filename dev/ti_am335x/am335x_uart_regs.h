////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       14.01.2017
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AM335X_UART_REGS_H
#define AM335X_UART_REGS_H

#include <os/stdint.h>
#include <os/utils.h>

namespace Device {
namespace AM335x {

////////////////////////////////////////////////////////////////////////////////////////////////
// REGISTER DEFINITIONS
////////////////////////////////////////////////////////////////////////////////////////////////

typedef union {
    struct {
        uint16_t THR : 8;
        uint16_t : 8;
    };

    uint16_t value;
} UART_THR_t;

typedef union {
    struct {
        uint16_t RHR : 8;
        uint16_t : 8;
    };

    uint16_t value;
} UART_RHR_t;

typedef union {
    struct {
        uint16_t CLOCK_LSB : 8;
        uint16_t : 8;
    };

    uint16_t value;
} UART_DLL_t;

typedef union {
    struct {
        uint16_t RHRIT : 1;
        uint16_t THRIT : 1;
        uint16_t LASTRXBYTEIT : 1;
        uint16_t RXOVERRUNIT : 1;
        uint16_t STSFIFOTRIGIT : 1;
        uint16_t TXSTATUSIT : 1;
        uint16_t LINESTSIT : 1;
        uint16_t EOFIT : 1;
        uint16_t : 8;
    };

    uint16_t value;
} IRDA_IER_t;

typedef union {
    struct {
        uint16_t RHRIT : 1;
        uint16_t THRIT : 1;
        uint16_t RXSTOPIT : 1;
        uint16_t RXOVERRUNIT : 1;
        uint16_t : 1;
        uint16_t TXSTATUSIT : 1;
        uint16_t : 10;
    };

    uint16_t value;
} CIR_IER_t;

typedef union {
    struct {
        uint16_t RHRIT : 1;
        uint16_t THRIT : 1;
        uint16_t LINESTSIT : 1;
        uint16_t MODEMSTSIT : 1;
        uint16_t SLEEPMODE : 1;
        uint16_t XOFFIT : 1;
        uint16_t RTSIT : 1;
        uint16_t CTSIT : 1;
        uint16_t : 8;
    };

    uint16_t value;
} UART_IER_t;

typedef union {
    struct {
        uint16_t CLOCK_MSB : 6;
        uint16_t : 10;
    };

    uint16_t value;
} UART_DLH_t;

typedef union {
    struct {
        uint16_t SWFLOWCONTROL : 4;
        uint16_t ENHANCEDEN : 1;
        uint16_t SPECIALCHARDETECT : 1;
        uint16_t AUTORTSEN : 1;
        uint16_t AUTOCTSEN : 1;
        uint16_t : 8;
    };

    uint16_t value;
} UART_EFR_t;

typedef union {
    struct {
        uint16_t IT_PENDING : 1;
        uint16_t IT_TYPE : 5;
        uint16_t FCR_MIRROR : 2;
        uint16_t : 8;
    };

    uint16_t value;
} UART_IIR_t;

typedef union {
    struct {
        uint16_t RHRIT : 1;
        uint16_t THRIT : 1;
        uint16_t RXSTOPIT : 1;
        uint16_t RXOEIT : 1;
        uint16_t : 1;
        uint16_t TXSTATUSIT : 1;
        uint16_t : 10;
    };

    uint16_t value;
} CIR_IIR_t;

typedef union {
    struct {
        uint16_t FIFO_EN : 1;
        uint16_t RX_FIFO_CLEAR : 1;
        uint16_t TX_FIFO_CLEAR : 1;
        uint16_t DMA_MODE : 1;
        uint16_t TX_FIFO_TRIG : 2;
        uint16_t RX_FIFO_TRIG : 2;
        uint16_t : 8;
    };

    uint16_t value;
} UART_FCR_t;

typedef union {
    struct {
        uint16_t RHR_IT : 1;
        uint16_t THR_IT : 1;
        uint16_t RX_FIFO_LAST_BYTE_IT : 1;
        uint16_t RX_OE_IT : 1;
        uint16_t STS_FIFO_IT : 1;
        uint16_t TX_STATUS_IT : 1;
        uint16_t LINE_STS_IT : 1;
        uint16_t EOF_IT : 1;
        uint16_t : 8;
    };

    uint16_t value;
} IRDA_IIR_t;

typedef union {
    struct {
        uint16_t CHAR_LENGTH : 2;
        uint16_t NB_STOP : 1;
        uint16_t PARITY_EN : 1;
        uint16_t PARITY_TYPE1 : 1;
        uint16_t PARITY_TYPE2 : 1;
        uint16_t BREAK_EN : 1;
        uint16_t DIV_EN : 1;
        uint16_t : 8;
    };

    uint16_t value;
} UART_LCR_t;

typedef union {
    struct {
        uint16_t DTR : 1;
        uint16_t RTS : 1;
        uint16_t RISTSCH : 1;
        uint16_t CDSTSCH : 1;
        uint16_t LOOPBACKEN : 1;
        uint16_t XONEN : 1;
        uint16_t TCRTLR : 1;
        uint16_t : 9;
    };

    uint16_t value;
} UART_MCR_t;

typedef union {
    struct {
        uint16_t XONWORD1 : 8;
        uint16_t : 8;
    };

    uint16_t value;
} UART_XON1_ADDR1_t;

typedef union {
    struct {
        uint16_t XONWORD2 : 8;
        uint16_t : 8;
    };

    uint16_t value;
} UART_XON2_ADDR2_t;

typedef union {
    struct {
        uint16_t RXFIFOE : 1;
        uint16_t : 4;
        uint16_t RXSTOP : 1;
        uint16_t : 1;
        uint16_t THREMPTY : 1;
        uint16_t : 8;
    };

    uint16_t value;
} CIR_LSR_t;

typedef union {
    struct {
        uint16_t RX_FIFO_E : 1;
        uint16_t STS_FIFO_E : 1;
        uint16_t CRC : 1;
        uint16_t ABORT : 1;
        uint16_t FRAME_TOO_LONG : 1;
        uint16_t RX_LAST_BYTE : 1;
        uint16_t STS_FIFO_FULL : 1;
        uint16_t THR_EMPTY : 1;
        uint16_t : 8;
    };

    uint16_t value;
} IRDA_LSR_t;

typedef union {
    struct {
        uint16_t RXFIFOE : 1;
        uint16_t RXOE : 1;
        uint16_t RXPE : 1;
        uint16_t RXFE : 1;
        uint16_t RXBI : 1;
        uint16_t TXFIFOE : 1;
        uint16_t TXSRE : 1;
        uint16_t RXFIFOSTS : 1;
        uint16_t : 8;
    };

    uint16_t value;
} UART_LSR_t;

typedef union {
    struct {
        uint16_t RXFIFOTRIGHALT : 4;
        uint16_t RXFIFOTRIGSTART : 4;
        uint16_t : 8;
    };

    uint16_t value;
} UART_TCR_t;

typedef union {
    struct {
        uint16_t CTS_STS : 1;
        uint16_t DSR_STS : 1;
        uint16_t RI_STS : 1;
        uint16_t DCD_STS : 1;
        uint16_t NCTS_STS : 1;
        uint16_t NDSR_STS : 1;
        uint16_t NRI_STS : 1;
        uint16_t NCD_STS : 1;
        uint16_t : 8;
    };

    uint16_t value;
} UART_MSR_t;

typedef union {
    struct {
        uint16_t XOFFWORD1 : 8;
        uint16_t : 8;
    };

    uint16_t value;
} UART_XOFF1_t;

typedef union {
    struct {
        uint16_t SPR_WORD : 8;
        uint16_t : 8;
    };

    uint16_t value;
} UART_SPR_t;

typedef union {
    struct {
        uint16_t TX_FIFO_TRIG_DMA : 4;
        uint16_t RX_FIFO_TRIG_DMA : 4;
        uint16_t : 8;
    };

    uint16_t value;
} UART_TLR_t;

typedef union {
    struct {
        uint16_t XOFFWORD2 : 8;
        uint16_t : 8;
    };

    uint16_t value;
} UART_XOFF2_t;

typedef union {
    struct {
        uint16_t MODESELECT : 3;
        uint16_t IRSLEEP : 1;
        uint16_t SETTXIR : 1;
        uint16_t SCT : 1;
        uint16_t SIPMODE : 1;
        uint16_t FRAMEENDMODE : 1;
        uint16_t : 8;
    };

    uint16_t value;
} UART_MDR1_t;

typedef union {
    struct {
        uint16_t IRTXUNDERRUN : 1;
        uint16_t STSFIFOTRIG : 2;
        uint16_t UARTPULSE : 1;
        uint16_t CIRPULSEMODE : 2;
        uint16_t IRRXINVERT : 1;
        uint16_t SETTXIRALT : 1;
        uint16_t : 8;
    };

    uint16_t value;
} UART_MDR2_t;

typedef union {
    struct {
        uint16_t TXFLL : 8;
        uint16_t : 8;
    };

    uint16_t value;
} UART_TXFLL_t;

typedef union {
    struct {
        uint16_t : 1;
        uint16_t CRC_ERROR : 1;
        uint16_t ABORT_DETECT : 1;
        uint16_t FRAME_TOO_LONG_ERROR : 1;
        uint16_t OE_ERROR : 1;
        uint16_t : 11;
    };

    uint16_t value;
} UART_SFLSR_t;

typedef union {
    struct {
        uint16_t RESUME : 8;
        uint16_t : 8;
    };

    uint16_t value;
} UART_RESUME_t;

typedef union {
    struct {
        uint16_t TXFLH : 5;
        uint16_t : 11;
    };

    uint16_t value;
} UART_TXFLH_t;

typedef union {
    struct {
        uint16_t RXFLL : 8;
        uint16_t : 8;
    };

    uint16_t value;
} UART_RXFLL_t;

typedef union {
    struct {
        uint16_t SFREGL : 8;
        uint16_t : 8;
    };

    uint16_t value;
} UART_SFREGL_t;

typedef union {
    struct {
        uint16_t SFREGH : 4;
        uint16_t : 12;
    };

    uint16_t value;
} UART_SFREGH_t;

typedef union {
    struct {
        uint16_t RXFLH : 4;
        uint16_t : 12;
    };

    uint16_t value;
} UART_RXFLH_t;

typedef union {
    struct {
        uint16_t : 6;
        uint16_t XBOFTYPE : 1;
        uint16_t STSFIFORESET : 1;
        uint16_t : 8;
    };

    uint16_t value;
} UART_BLR_t;

typedef union {
    struct {
        uint16_t SPEED : 5;
        uint16_t BITBYCHAR : 1;
        uint16_t PARITYTYPE : 2;
        uint16_t : 8;
    };

    uint16_t value;
} UART_UASR_t;

typedef union {
    struct {
        uint16_t EOTEN : 1;
        uint16_t ABORTEN : 1;
        uint16_t SCTXEN : 1;
        uint16_t SENDSIP : 1;
        uint16_t DISTXUNDERRUN : 1;
        uint16_t DISIRRX : 1;
        uint16_t SDMOD : 1;
        uint16_t PULSETYPE : 1;
        uint16_t : 8;
    };

    uint16_t value;
} UART_ACREG_t;

typedef union {
    struct {
        uint16_t DMAMODECTL : 1;
        uint16_t DMAMODE2 : 2;
        uint16_t TXEMPTYCTLIT : 1;
        uint16_t RXCTSDSRWAKEUPENABLE : 1;
        uint16_t DSRIT : 1;
        uint16_t TXTRIGGRANU1 : 1;
        uint16_t RXTRIGGRANU1 : 1;
        uint16_t : 8;
    };

    uint16_t value;
} UART_SCR_t;

typedef union {
    struct {
        uint16_t TXFIFOFULL : 1;
        uint16_t RXCTSDSRWAKEUPSTS : 1;
        uint16_t DMACOUNTERRST : 1;
        uint16_t : 13;
    };

    uint16_t value;
} UART_SSR_t;

typedef union {
    struct {
        uint16_t EBLR : 8;
        uint16_t : 8;
    };

    uint16_t value;
} UART_EBLR_t;

typedef union {
    struct {
        uint16_t MINORREV : 6;
        uint16_t : 2;
        uint16_t MAJORREV : 3;
        uint16_t : 5;
    };

    uint16_t value;
} UART_MVR_t;

typedef union {
    struct {
        uint16_t AUTOIDLE : 1;
        uint16_t SOFTRESET : 1;
        uint16_t ENAWAKEUP : 1;
        uint16_t IDLEMODE : 2;
        uint16_t : 11;
    };

    uint16_t value;
} UART_SYSC_t;

typedef union {
    struct {
        uint16_t RESETDONE : 1;
        uint16_t : 15;
    };

    uint16_t value;
} UART_SYSS_t;

typedef union {
    struct {
        uint16_t CTS_ACTIVITY : 1;
        uint16_t DSR_ACTIVITY : 1;
        uint16_t RI_ACTIVITY : 1;
        uint16_t DCD_ACTIVITY : 1;
        uint16_t RX_ACTIVITY : 1;
        uint16_t RHR_INTERRUPT : 1;
        uint16_t RLS_INTERRUPT : 1;
        uint16_t TXWAKEUPEN : 1;
        uint16_t : 8;
    };

    uint16_t value;
} UART_WER_t;

typedef union {
    struct {
        uint16_t CFPS : 8;
        uint16_t : 8;
    };

    uint16_t value;
} UART_CFPS_t;

typedef union {
    struct {
        uint16_t RXFIFO_LVL : 8;
        uint16_t : 8;
    };

    uint16_t value;
} UART_RXFIFO_LVL_t;

typedef union {
    struct {
        uint16_t TXFIFO_LVL : 8;
        uint16_t : 8;
    };

    uint16_t value;
} UART_TXFIFO_LVL_t;

typedef union {
    struct {
        uint16_t EN_RXFIFO_EMPTY : 1;
        uint16_t EN_TXFIFO_EMPTY : 1;
        uint16_t : 14;
    };

    uint16_t value;
} UART_IER2_t;

typedef union {
    struct {
        uint16_t RXFIFO_EMPTY_STS : 1;
        uint16_t TXFIFO_EMPTY_STS : 1;
        uint16_t : 14;
    };

    uint16_t value;
} UART_ISR2_t;

typedef union {
    struct {
        uint16_t FREQ_SEL : 8;
        uint16_t : 8;
    };

    uint16_t value;
} UART_FREQ_SEL_t;

typedef union {
    struct {
        uint16_t DISABLE_CIR_RX_DEMOD : 1;
        uint16_t NONDEFAULT_FREQ : 1;
        uint16_t SET_DMA_TX_THRESHOLD : 1;
        uint16_t : 13;
    };

    uint16_t value;
} UART_MDR3_t;

typedef union {
    struct {
        uint16_t TX_DMA_THRESHOLD : 6;
        uint16_t : 12;
    };

    uint16_t value;
} UART_TX_DMA_THRESHOLD_t;

////////////////////////////////////////////////////////////////////////////////////////////////
// REGISTER ADDRESSES
////////////////////////////////////////////////////////////////////////////////////////////////

#define UART_0_BASE                      0x44e09000
#define UART_1_BASE                      0x48022000
#define UART_2_BASE                      0x48024000
#define UART_3_BASE                      0x481a6000
#define UART_4_BASE                      0x481a8000
#define UART_5_BASE                      0x481aa000

#define UART_THR(UART_BASE)              REGISTER(UART_THR_t, (UART_BASE + 0x0))
#define UART_RHR(UART_BASE)              REGISTER(UART_RHR_t, (UART_BASE + 0x0))
#define UART_DLL(UART_BASE)              REGISTER(UART_DLL_t, (UART_BASE + 0x0))
#define IRDA_IER(UART_BASE)              REGISTER(IRDA_IER_t, (UART_BASE + 0x4))
#define CIR_IER(UART_BASE)               REGISTER(CIR_IER_t, (UART_BASE + 0x4))
#define UART_IER(UART_BASE)              REGISTER(UART_IER_t, (UART_BASE + 0x4))
#define UART_DLH(UART_BASE)              REGISTER(UART_DLH_t, (UART_BASE + 0x4))
#define UART_EFR(UART_BASE)              REGISTER(UART_EFR_t, (UART_BASE + 0x8))
#define UART_IIR(UART_BASE)              REGISTER(UART_IIR_t, (UART_BASE + 0x8))
#define CIR_IIR(UART_BASE)               REGISTER(CIR_IIR_t, (UART_BASE + 0x8))
#define UART_FCR(UART_BASE)              REGISTER(UART_FCR_t, (UART_BASE + 0x8))
#define IRDA_IRR(UART_BASE)              REGISTER(IRDA_IRR_t, (UART_BASE + 0x8))
#define UART_LCR(UART_BASE)              REGISTER(UART_LCR_t, (UART_BASE + 0xc))
#define UART_MCR(UART_BASE)              REGISTER(UART_MCR_t, (UART_BASE + 0x10))
#define UART_XON1_ADDR1(UART_BASE)       REGISTER(UART_XON1_ADDR1_t, (UART_BASE + 0x10))
#define UART_XON2_ADDR2(UART_BASE)       REGISTER(UART_XON2_ADDR2_t, (UART_BASE + 0x14))
#define CIR_LSR(UART_BASE)               REGISTER(CIR_LSR_t, (UART_BASE + 0x14))
#define IRDA_LSR(UART_BASE)              REGISTER(IRDA_LSR_t, (UART_BASE + 0x14))
#define UART_LSR(UART_BASE)              REGISTER(UART_LSR_t, (UART_BASE + 0x14))
#define UART_TCR(UART_BASE)              REGISTER(UART_TCR_t, (UART_BASE + 0x18))
#define UART_MSR(UART_BASE)              REGISTER(UART_MSR_t, (UART_BASE + 0x18))
#define UART_XOFF1(UART_BASE)            REGISTER(UART_XOFF1_t, (UART_BASE + 0x18))
#define UART_SPR(UART_BASE)              REGISTER(UART_SPR_t, (UART_BASE + 0x1c))
#define UART_TLR(UART_BASE)              REGISTER(UART_TLR_t, (UART_BASE + 0x1c))
#define UART_XOFF2(UART_BASE)            REGISTER(UART_XOFF2_t, (UART_BASE + 0x1c))
#define UART_MDR1(UART_BASE)             REGISTER(UART_MDR1_t, (UART_BASE + 0x20))
#define UART_MDR2(UART_BASE)             REGISTER(UART_MDR2_t, (UART_BASE + 0x24))
#define UART_TXFLL(UART_BASE)            REGISTER(UART_TXFLL_t, (UART_BASE + 0x28))
#define UART_SFLSR(UART_BASE)            REGISTER(UART_SFLSR_t, (UART_BASE + 0x28))
#define UART_RESUME(UART_BASE)           REGISTER(UART_RESUME_t, (UART_BASE + 0x2c))
#define UART_TXFLH(UART_BASE)            REGISTER(UART_TXFLH_t, (UART_BASE + 0x2c))
#define UART_RXFLL(UART_BASE)            REGISTER(UART_RXFLL_t, (UART_BASE + 0x30))
#define UART_SFREGL(UART_BASE)           REGISTER(UART_SFREGL_t, (UART_BASE + 0x30))
#define UART_SFREGH(UART_BASE)           REGISTER(UART_SFREGH_t, (UART_BASE + 0x34))
#define UART_RXFLH(UART_BASE)            REGISTER(UART_RXFLH_t, (UART_BASE + 0x34))
#define UART_BLR(UART_BASE)              REGISTER(UART_BLR_t, (UART_BASE + 0x38))
#define UART_UASR(UART_BASE)             REGISTER(UART_UASR_t, (UART_BASE + 0x38))
#define UART_ACREG(UART_BASE)            REGISTER(UART_ACREG_t, (UART_BASE + 0x3c))
#define UART_SCR(UART_BASE)              REGISTER(UART_SCR_t, (UART_BASE + 0x40))
#define UART_SSR(UART_BASE)              REGISTER(UART_SSR_t, (UART_BASE + 0x44))
#define UART_EBLR(UART_BASE)             REGISTER(UART_EBLR_t, (UART_BASE + 0x48))
#define UART_MVR(UART_BASE)              REGISTER(UART_MVR_t, (UART_BASE + 0x50))
#define UART_SYSC(UART_BASE)             REGISTER(UART_SYSC_t, (UART_BASE + 0x54))
#define UART_SYSS(UART_BASE)             REGISTER(UART_SYSS_t, (UART_BASE + 0x58))
#define UART_WER(UART_BASE)              REGISTER(UART_WER_t, (UART_BASE + 0x5c))
#define UART_CFPS(UART_BASE)             REGISTER(UART_CFPS_t, (UART_BASE + 0x60))
#define UART_RXFIFO_LVL(UART_BASE)       REGISTER(UART_RXFIFO_LVL_t, (UART_BASE + 0x64))
#define UART_TXFIFO_LVL(UART_BASE)       REGISTER(UART_TXFIFO_LVL_t, (UART_BASE + 0x68))
#define UART_IER2(UART_BASE)             REGISTER(UART_IER2_t, (UART_BASE + 0x6c))
#define UART_ISR2(UART_BASE)             REGISTER(UART_ISR2_t, (UART_BASE + 0x70))
#define UART_FREQ_SEL(UART_BASE)         REGISTER(UART_FREQ_SEL_t, (UART_BASE + 0x74))
#define UART_MDR3(UART_BASE)             REGISTER(UART_MDR3_t, (UART_BASE + 0x80))
#define UART_TX_DMA_THRESHOLD(UART_BASE) REGISTER(UART_TX_DMA_THRESHOLD_t, (UART_BASE + 0x84))

} // namespace AM335x
} // namespace Device

#endif
