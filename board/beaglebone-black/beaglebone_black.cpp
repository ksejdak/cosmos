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
#include <dev/ti_am335x/am335x_gpio.h>

using namespace Device;

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
    DeviceManager<IGPIOPort>::init();

    // Init user led0.
    GPIOPin led0(PIN_USER_LED0);
    led0.setFunction(AM335X_PAD_FUNC_7);
    led0.setDirection(GPIO_OUTPUT);
    led0.setResistor(GPIO_RESISTOR_NONE);
    led0.write(true);

    // Init console on UART1.
    GPIOPin consoleTx(PIN_P9_24);
    consoleTx.setFunction(AM335X_PAD_FUNC_0);
    consoleTx.setDirection(GPIO_OUTPUT);

    if (!console.init())
        return false;

    return true;
}

} // namespace Board
