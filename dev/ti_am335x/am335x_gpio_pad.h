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

#ifndef AM335X_GPIO_PAD_H
#define AM335X_GPIO_PAD_H

#include <dev/gpio.h>
#include <os/utils.h>

#include <cstdint>

namespace Device::GPIO {

////////////////////////////////////////////////////////////////////////////////////
// REGISTER DEFINITIONS
////////////////////////////////////////////////////////////////////////////////////

typedef union {
    struct {
        int PAD_FUNC : 3;
        bool PAD_PULLUP_DISABLE : 1;
        bool PAD_PULLUP_SELECT : 1;
        bool PAD_INPUT_ACTIVE : 1;
        bool PAD_SLOW_SLEWRATE : 1;
        std::uint32_t _reserved : 25;
    };

    std::uint32_t value;
} PAD_t;

////////////////////////////////////////////////////////////////////////////////////
// REGISTER ADDRESSES
////////////////////////////////////////////////////////////////////////////////////

#define GPIO_PAD_REGS_BASE                  0x44e10800

#define GPIO_PAD(PIN_NUM)                   REGISTER(PAD_t, (GPIO_PAD_REGS_BASE + PIN_NUM * 4))

////////////////////////////////////////////////////////////////////////////////////
// PIN MUX
////////////////////////////////////////////////////////////////////////////////////

// [Pin number] -> (GPIO port, GPIO pin)
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
    { 1, 21 },          \
    { 1, 22 },          \
    { 1, 23 },          \
    { 1, 24 },          \
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
    { 2, 25 },          \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { -1, -1 },         \
    { 0, 1 },           \
    { 0, 3 },           \
    { 0, 4 },           \
    { 0, 5 },           \
    { -1, -1 },         \
    { 0, 7 },           \
    { -1, -1 },         \
    { -1, -1 },         \
    { 1, 10 },          \
    { 1, 11 },          \
    { 0, 12 },          \
    { 0, 13 },          \
    { 0, 14 },          \
    { 0, 15 },          \
    { -1, -1 },         \
    { -1, -1 },         \
    { 3, 14 },          \
    { 3, 15 },          \
    { 3, 16 },          \
    { 3, 17 },          \
    { -1, -1 },         \
    { 3, 19 },          \
    { -1, -1 },         \
    { 3, 21 },          \
    { -1, -1 },         \
    { 3, 20 }           \
}

} // namespace Device::GPIO

#endif
