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

#include "beaglebone_black.h"
#include "beaglebone_black_pinmux.h"

#include <core/console.h>
#include <dev/device_manager.h>
#include <dev/gpio.h>
#include <dev/uart.h>
#include <dev/ti_am335x/am335x_gpio.h>
#include <dev/ti_am335x/am335x_uart.h>

using namespace Device;
using namespace Device::GPIO;
using namespace Device::UART;

namespace Board {

IBoard* IBoard::create()
{
    return new BeagleBoneBlack();
}

BeagleBoneBlack::BeagleBoneBlack()
{
    m_name = "BeagleBone Black";
    m_vendor = "Texas Instruments";
    m_version = "1.0";
}

bool BeagleBoneBlack::initDevice()
{
    DeviceManager<AM335x_GPIO>::init();
    DeviceManager<AM335x_UART>::init();

    initUserLED();
    initConsole();

    return true;
}

bool BeagleBoneBlack::initUserLED()
{
    // Init user led0.
    auto led0 = GPIOPin<AM335x_GPIO>(PIN_USER_LED0);
    led0.setFunction(Function::_7);
    led0.setDirection(GPIO::Direction::Output);
    led0.setResistor(Resitor::None);
    led0.write(true);

    return true;
}

bool BeagleBoneBlack::initConsole()
{
    // Init console on UART1.
    auto consoleTx = GPIOPin<AM335x_GPIO>(PIN_SERIAL_DEBUG_TX);
    consoleTx.setFunction(Function::_0);
    consoleTx.setDirection(GPIO::Direction::Output);
    consoleTx.setResistor(Resitor::None);

    auto& consoleUart = DeviceManager<AM335x_UART>::get(UARTId::_0);
    consoleUart.setBaudRate(115200);
    consoleUart.setDataBits(DataBits::_8);
    consoleUart.setStopBits(StopBits::_1);
    consoleUart.setPartity(Partity::None);
    consoleUart.setFlowControl(FlowControl::None);
    consoleUart.setDirection(UART::Direction::Write);
    consoleUart.setTransmissionMode(TransmissionMode::Asynchronous);

    return console.init();

}

} // namespace Board
