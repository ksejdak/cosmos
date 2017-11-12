////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       21.08.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

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
