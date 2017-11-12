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

#ifndef AM335X_GPIO_H
#define AM335X_GPIO_H

#include "am335x_gpio_regs.h"

#include <dev/device_manager.h>
#include <dev/gpio.h>

namespace Device::GPIO {

enum class GPIOId {
    _0,
    _1,
    _2,
    _3
};

class AM335x_GPIO : public IGPIO<4> {
public:
    using id_type = GPIOId;
    friend class DeviceManager<AM335x_GPIO>;

public:
    virtual void init() override;
    virtual void reset();
    virtual void enable();
    virtual void disable();

    virtual bool setFunction(int id, Function function);
    virtual void setDirection(int pinNo, Direction direction);
    virtual void setResistor(int id, Resitor resistor);

    virtual std::uint32_t read();
    virtual bool write(std::uint32_t value);
    virtual bool writePin(int pinNo, bool state);

private:
    AM335x_GPIO();

private:
    GPIOId m_id;
    int m_base;

    static constexpr int PIN_COUNT  = 32;
    static int m_nextId;
};

} // namespace Device::GPIO

#endif
