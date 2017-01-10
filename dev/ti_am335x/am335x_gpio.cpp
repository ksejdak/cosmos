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

int IGPIOManager::getPortBaseAddress(int portNo)
{
    switch (portNo) {
        case AM335x_GPIO_0:     return GPIO_0_BASE;
        case AM335x_GPIO_1:     return GPIO_1_BASE;
        case AM335x_GPIO_2:     return GPIO_2_BASE;
        case AM335x_GPIO_3:     return GPIO_3_BASE;
    }

    return -1;
}

AM335x_GPIOPort::AM335x_GPIOPort(AM335x_GPIOId_t portNo)
    : IGPIOPort(portNo)
    , m_base(IGPIOManager::getPortBaseAddress(portNo))
    , m_initialized(false)
{
    // TODO:
    // - register IRQ handler for given port
    // - register /dev/gpioX device.
}

void AM335x_GPIOPort::init()
{
    if (m_initialized)
        return;

    // Enable interface and functional clocks.
    switch (m_portNo) {
        case AM335x_GPIO_0:
            CM_WKUP_GPIO0_CLKCTRL->MODULEMODE = CM_WKUP_MODULEMODE_ENABLE;
            while (CM_WKUP_GPIO0_CLKCTRL->MODULEMODE != CM_WKUP_MODULEMODE_ENABLE);
            CM_WKUP_GPIO0_CLKCTRL->OPTFCLKEN_GPIO0_GDBCLK = CM_WKUP_CLK_ACTIVE;
            while (CM_WKUP_CONTROL_CLKCTRL->IDLEST != CM_WKUP_IDLEST_FUNCTIONAL);
            while (CM_L3_AON_CLKSTCTRL->CLKACTIVITY_L3_AON_GCLK != CM_WKUP_CLK_ACTIVE);
            while (CM_WKUP_L4WKUP_CLKCTRL->IDLEST != CM_WKUP_IDLEST_FUNCTIONAL);
            while (CM_WKUP_CLKSTCTRL->CLKACTIVITY_L4_WKUP_GCLK != CM_WKUP_IDLEST_FUNCTIONAL);
            while (CM_L4_WKUP_AON_CLKSTCTRL->CLKACTIVITY_L4_WKUP_AON_GCLK != CM_WKUP_IDLEST_FUNCTIONAL);
            while (CM_WKUP_GPIO0_CLKCTRL->IDLEST != CM_WKUP_IDLEST_FUNCTIONAL);
            while (CM_WKUP_CLKSTCTRL->CLKACTIVITY_GPIO0_GDBCLK != CM_WKUP_CLK_ACTIVE);
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
    m_initialized = true;
}

int AM335x_GPIOPort::getPinCount()
{
    return AM335x_GPIO_PIN_COUNT;
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

bool AM335x_GPIOPort::writePin(int pinNo, bool state)
{
    if (pinNo < 0 || pinNo >= getPinCount())
        return false;

    if (state)
        GPIO_SETDATAOUT(m_base)->INTLINEn = PIN_MASK(pinNo);
    else
        GPIO_CLEARDATAOUT(m_base)->INTLINEn = PIN_MASK(pinNo);

    return true;
}

bool AM335x_GPIOPort::setFunction(int id, int function)
{
    if (function < AM335X_PAD_FUNC_0 || function > AM335X_PAD_FUNC_7)
        return false;

    GPIO_PAD(id)->PAD_FUNC = function;
    GPIO_PAD(id)->PAD_SLEW_RATE = 0;
    return true;
}

void AM335x_GPIOPort::setDirection(int id, GPIODirection_t direction)
{
    GPIO_PAD(id)->PAD_INPUT_ACTIVE = (direction == GPIO_INPUT);
}

void AM335x_GPIOPort::setResistor(int id, GPIOResitor_t resistor)
{
    GPIO_PAD(id)->PAD_PULLUP_ENABLE = (resistor != GPIO_RESISTOR_NONE);
    if (resistor == GPIO_RESISTOR_NONE)
        return;

    GPIO_PAD(id)->PAD_PULLUP_SELECT = (resistor == GPIO_RESISTOR_PULLUP);
}

AM335x_GPIOManager::AM335x_GPIOManager()
    : m_ports{ AM335x_GPIO_0,
               AM335x_GPIO_1,
               AM335x_GPIO_2,
               AM335x_GPIO_3 }
{
    // TODO:
    // - check REVISION register.
    // - register /dev/gpio-control device.
}

int AM335x_GPIOManager::getPortCount()
{
    return AM335x_GPIO_PORT_COUNT;
}

IGPIOPort& AM335x_GPIOManager::getPort(int portNo)
{
    assert(portNo >= AM335x_GPIO_0 && portNo <= AM335x_GPIO_3);
    return m_ports[portNo];
}

} // namespace Device
