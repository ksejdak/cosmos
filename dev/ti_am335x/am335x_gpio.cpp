////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       27.12.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#include "am335x_gpio.h"
#include "am335x_clock.h"

#include <os/assert.h>

namespace Device {

PinMux_t pinmux[] = AM335X_PINMUX;
int pinmuxSize = sizeof(pinmux) / sizeof(PinMux_t);

IGPIOManager* IGPIOManager::create()
{
    return new AM335x_GPIOManager();
}

AM335x_GPIOPort::AM335x_GPIOPort(AM335x_GPIOPortId_t gpioPortNo)
    : IGPIOPort(gpioPortNo)
    , m_base(IGPIOManager::instance()->getPortBaseAddress(gpioPortNo))
{
    // TODO:
    // - register IRQ handler for given port
    // - register /dev/gpioX device.
}

void AM335x_GPIOPort::init()
{
    // Enable interface clock.
    switch (m_gpioPortNo) {
        case AM335x_GPIO_0:
            CM_WKUP_GPIO0_CLKCTRL->MODULEMODE = CM_WKUP_MODULEMODE_ENABLE;
            while (CM_WKUP_GPIO0_CLKCTRL->IDLEST != CM_WKUP_IDLEST_FUNCTIONAL);
            break;
        case AM335x_GPIO_1:
            CM_PER_GPIO1_CLKCTRL->MODULEMODE = CM_PER_MODULEMODE_ENABLE;
            while (CM_PER_GPIO1_CLKCTRL->IDLEST != CM_PER_IDLEST_FUNCTIONAL);
            break;
        case AM335x_GPIO_2:
            CM_PER_GPIO2_CLKCTRL->MODULEMODE = CM_PER_MODULEMODE_ENABLE;
            while (CM_PER_GPIO2_CLKCTRL->IDLEST != CM_PER_IDLEST_FUNCTIONAL);
            break;
        case AM335x_GPIO_3:
            CM_PER_GPIO3_CLKCTRL->MODULEMODE = CM_PER_MODULEMODE_ENABLE;
            while (CM_PER_GPIO3_CLKCTRL->IDLEST != CM_PER_IDLEST_FUNCTIONAL);
            break;
    }

    // Enable module.
    GPIO_CTRL(m_base)->DISABLEMODULE = 0;
}

int AM335x_GPIOPort::getPinsCount()
{
    return AM335x_GPIO_PINS_COUNT;
}

uint32_t AM335x_GPIOPort::read()
{
    volatile uint32_t value = (GPIO_DATAIN(m_base)->DATAINn & GPIO_OE(m_base)->OUTPUTENn);
    return value;
}

bool AM335x_GPIOPort::write(uint32_t value)
{
    if (value & GPIO_OE(m_base)->OUTPUTENn) {
        // Attempt to write to input pin.
        return false;
    }

    GPIO_DATAOUT(m_base)->DATAOUTn = value;
    return true;
}

bool AM335x_GPIOPort::writePin(int gpioPinNo, bool state)
{
    if (gpioPinNo < 0 || gpioPinNo >= getPinsCount())
        return false;

    if (state)
        GPIO_SETDATAOUT(m_base)->INTLINEn = PIN_MASK(gpioPinNo);
    else
        GPIO_CLEARDATAOUT(m_base)->INTLINEn = PIN_MASK(gpioPinNo);

    return true;
}

bool AM335x_GPIOPort::setPinFunction(int pinId, int function)
{
    if (function < AM335X_PAD_FUNC_0 || function > AM335X_PAD_FUNC_7)
        return false;

    GPIO_PAD(pinId)->PAD_FUNC = function;
    return true;
}

AM335x_GPIOManager::AM335x_GPIOManager()
    : m_ports{ AM335x_GPIO_0,
               AM335x_GPIO_1,
               AM335x_GPIO_2,
               AM335x_GPIO_3 }
{
    init();
}

int AM335x_GPIOManager::getPortsCount()
{
    return AM335x_GPIO_PORTS_COUNT;
}

int AM335x_GPIOManager::getPortBaseAddress(int gpioPortNo)
{
    switch (gpioPortNo) {
        case AM335x_GPIO_0:     return GPIO_0_BASE;
        case AM335x_GPIO_1:     return GPIO_1_BASE;
        case AM335x_GPIO_2:     return GPIO_2_BASE;
        case AM335x_GPIO_3:     return GPIO_3_BASE;
    }

    return -1;
}

IGPIOPort& AM335x_GPIOManager::getPort(int gpioPortNo)
{
    assert(gpioPortNo >= AM335x_GPIO_0 && gpioPortNo <= AM335x_GPIO_3);
    return m_ports[gpioPortNo];
}

void AM335x_GPIOManager::init()
{
    // TODO:
    // - check REVISION register.
    // - register /dev/gpio-control device.
}

} // namespace Device
