////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       29.12.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef BEAGLEBONE_BLACK_PINMUX_H
#define BEAGLEBONE_BLACK_PINMUX_H

#include <board/board.h>

namespace Board {

typedef enum {
////////////////////////////////////////////////////////////////////////////////////////////////
// P8 HEADER
////////////////////////////////////////////////////////////////////////////////////////////////

    // PIN_P8_01 - GND
    // PIN_P8_02 - GND
    // PIN_P8_02 - GND
    PIN_P8_03 = 6,
    PIN_P8_04 = 7,
    PIN_P8_05 = 2,
    PIN_P8_06 = 3,
    PIN_P8_07 = 36,
    PIN_P8_08 = 37,
    PIN_P8_09 = 39,
    PIN_P8_10 = 38,
    PIN_P8_11 = 13,
    PIN_P8_12 = 12,
    PIN_P8_13 = 9,
    PIN_P8_14 = 10,
    PIN_P8_15 = 15,
    PIN_P8_16 = 14,
    PIN_P8_17 = 11,
    PIN_P8_18 = 35,
    PIN_P8_19 = 8,
    PIN_P8_20 = 33,
    PIN_P8_21 = 32,
    PIN_P8_22 = 5,
    PIN_P8_23 = 4,
    PIN_P8_24 = 1,
    PIN_P8_25 = 0,
    PIN_P8_26 = 31,
    PIN_P8_27 = 56,
    PIN_P8_28 = 58,
    PIN_P8_29 = 57,
    PIN_P8_30 = 59,
    PIN_P8_31 = 54,
    PIN_P8_32 = 55,
    PIN_P8_33 = 53,
    PIN_P8_34 = 51,
    PIN_P8_35 = 52,
    PIN_P8_36 = 50,
    PIN_P8_37 = 48,
    PIN_P8_38 = 49,
    PIN_P8_39 = 46,
    PIN_P8_40 = 47,
    PIN_P8_41 = 44,
    PIN_P8_42 = 45,
    PIN_P8_43 = 42,
    PIN_P8_44 = 43,
    PIN_P8_45 = 40,
    PIN_P8_46 = 41,

////////////////////////////////////////////////////////////////////////////////////////////////
// P9 HEADER
////////////////////////////////////////////////////////////////////////////////////////////////

    // PIN_P9_01 - GND
    // PIN_P9_02 - GND
    // PIN_P9_03 - DC_3.3V
    // PIN_P9_04 - DC_3.3V
    // PIN_P9_05 - VDD_5V
    // PIN_P9_06 - VDD_5V
    // PIN_P9_07 - SYS_5V
    // PIN_P9_08 - SYS_5V
    // PIN_P9_09 - PWR_BUT
    // PIN_P9_10 - SYS_RESETn
    PIN_P9_11 = 28,
    PIN_P9_12 = 30,
    PIN_P9_13 = 29,
    PIN_P9_14 = 18,
    PIN_P9_15 = 16,
    PIN_P9_16 = 19,
    PIN_P9_17 = 87,
    PIN_P9_18 = 86,
    PIN_P9_19 = 95,
    PIN_P9_20 = 94,
    PIN_P9_21 = 85,
    PIN_P9_22 = 84,
    PIN_P9_23 = 17,
    PIN_P9_24 = 97,
    PIN_P9_25 = 107,
    PIN_P9_26 = 96,
    PIN_P9_27 = 105,
    PIN_P9_28 = 103,
    PIN_P9_29 = 101,
    PIN_P9_30 = 102,
    PIN_P9_31 = 100,
    // PIN_P9_32 - VADC
    // PIN_P9_33 - AIN4
    // PIN_P9_34 - AGND
    // PIN_P9_35 - AIN6
    // PIN_P9_36 - AIN5
    // PIN_P9_37 - AIN2
    // PIN_P9_38 - AIN3
    // PIN_P9_39 - AIN0
    // PIN_P9_40 - AIN1
    PIN_P9_41 = 109,
    PIN_P9_42 = 89,
    // PIN_P9_43 - GND
    // PIN_P9_44 - GND
    // PIN_P9_45 - GND
    // PIN_P9_46 - GND

////////////////////////////////////////////////////////////////////////////////////////////////
// OTHER
////////////////////////////////////////////////////////////////////////////////////////////////

    PIN_USER_LED0 = 21,
    PIN_USER_LED1 = 22,
    PIN_USER_LED2 = 23,
    PIN_USER_LED3 = 24,
    PIN_SERIAL_DEBUG_RX = 92,
    PIN_SERIAL_DEBUG_TX = 93

} BeagleBoneBlackPin_t;

} // namespace Board

#endif
