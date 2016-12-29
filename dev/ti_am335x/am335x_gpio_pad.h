////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       26.12.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AM335X_GPIO_PAD_H
#define AM335X_GPIO_PAD_H

#include <os/stdint.h>
#include <os/utils.h>

namespace Device {

////////////////////////////////////////////////////////////////////////////////////////////////
// REGISTER DEFINITIONS
////////////////////////////////////////////////////////////////////////////////////////////////

typedef union {
    struct {
        uint32_t PAD_FUNC : 3;
        uint32_t PAD_PULLUP_ENABLE : 1;
        uint32_t PAD_PULLUP_SELECT : 1;
        uint32_t PAD_INPUT_ACTIVE : 1;
        uint32_t PAD_SLEW_RATE : 1;
        uint32_t : 25;
    };

    uint32_t value;
} PAD_t;

////////////////////////////////////////////////////////////////////////////////////////////////
// FIELD VALUES
////////////////////////////////////////////////////////////////////////////////////////////////

typedef enum {
    AM335X_PAD_FUNC_0 = 0x0,
    AM335X_PAD_FUNC_1 = 0x1,
    AM335X_PAD_FUNC_2 = 0x2,
    AM335X_PAD_FUNC_3 = 0x3,
    AM335X_PAD_FUNC_4 = 0x4,
    AM335X_PAD_FUNC_5 = 0x5,
    AM335X_PAD_FUNC_6 = 0x6,
    AM335X_PAD_FUNC_7 = 0x7
} AM335x_PadFunc_t;

typedef enum {
    AM335X_PAD_PULL_ENABLED  = 0x0,
    AM335X_PAD_PULL_DISABLED = 0x1
} AM335x_PadPull_t;

typedef enum {
    AM335X_PAD_PULLDOWN = 0x0,
    AM335X_PAD_PULLUP   = 0x1
} AM335x_PadPullType_t;

typedef enum {
    AM335X_PAD_OUTPUT = 0x0,
    AM335X_PAD_INPUT  = 0x1
} AM335x_PadDir_t;

typedef enum {
    AM335X_PAD_SLEW_FAST = 0x0,
    AM335X_PAD_SLEW_SLOW = 0x1
} AM335x_PadSlewRate_t;

////////////////////////////////////////////////////////////////////////////////////////////////
// REGISTER ADDRESSES
////////////////////////////////////////////////////////////////////////////////////////////////

#define GPIO_PAD_REGS_BASE                  0x44e10800

#define GPIO_PAD(PIN_NUM)                   REGISTER(PAD_t, (GPIO_PAD_REGS_BASE + PIN_NUM * 4))

////////////////////////////////////////////////////////////////////////////////////////////////
// PIN MUX
////////////////////////////////////////////////////////////////////////////////////////////////

// Pin number -> (GPIO port, GPIO pin)
#define AM335X_PINMUX { \
    { 1, 0 },           \
    { 1, 1 },           \
    { 1, 2 },           \
    { 1, 3 },           \
    { 1, 4 },           \
    { 1, 5 },           \
    { 1, 6 },           \
    { 1, 7 },           \
    { 0, 22 },          \
    { 0, 23 },          \
    { 0, 26 },          \
    { 0, 27 },          \
    { 1, 12 },          \
    { 1, 13 },          \
    { 1, 14 },          \
    { 1, 15 },          \
    { 1, 16 },          \
    { 1, 17 },          \
    { 1, 18 },          \
    { 1, 19 },          \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { 0, 30 },          \
    { 0, 31 },          \
    { 1, 28 },          \
    { 1, 29 },          \
    { 1, 30 },          \
    { 1, 31 },          \
    { -1, -1 },         \
    { 2, 1 },           \
    { 2, 2 },           \
    { 2, 3 },           \
    { 2, 4 },           \
    { 2, 5 },           \
    { 2, 6 },           \
    { 2, 7 },           \
    { 2, 8 },           \
    { 2, 9 },           \
    { 2, 10 },          \
    { 2, 11 },          \
    { 2, 12 },          \
    { 2, 13 },          \
    { 2, 14 },          \
    { 2, 15 },          \
    { 2, 16 },          \
    { 2, 17 },          \
    { 0, 8 },           \
    { 0, 9 },           \
    { 0, 10 },          \
    { 0, 11 },          \
    { 2, 22 },          \
    { 2, 23 },          \
    { 2, 24 },          \
    { 2, 25 }           \
}

} // namespace Device

#endif
