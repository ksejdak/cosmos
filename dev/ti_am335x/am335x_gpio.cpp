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
#include "am335x_clock_regs_per.h"
#include "am335x_clock_regs_wkup.h"
#include "am335x_gpio_pad.h"

#include <cassert>

namespace Device::GPIO {

PinMux_t pinmux[] = AM335X_PINMUX;
int pinmuxSize = sizeof(pinmux) / sizeof(PinMux_t);

int AM335x_GPIO::m_nextId = 0;

AM335x_GPIO::AM335x_GPIO()
    : m_id(static_cast<GPIOId>(m_nextId++))
    , m_base([&]() {
        switch (m_id) {
            case GPIOId::_0:     return GPIO_0_BASE;
            case GPIOId::_1:     return GPIO_1_BASE;
            case GPIOId::_2:     return GPIO_2_BASE;
            case GPIOId::_3:     return GPIO_3_BASE;
        }

        assert(false);
    }())
{
    // TODO:
    // - check REVISION register.
    // - register IRQ handler for given port.
    // - register /dev/gpioX device.
}

void AM335x_GPIO::init()
{
    using namespace Clock;

    if (m_initialized)
        return;

    // Enable interface and functional clocks.
    switch (m_id) {
        case GPIOId::_0:
            CM_WKUP_GPIO0_CLKCTRL->MODULEMODE = CM_WKUP_MODULEMODE_ENABLE;
            while (CM_WKUP_GPIO0_CLKCTRL->MODULEMODE != CM_WKUP_MODULEMODE_ENABLE);
            CM_WKUP_GPIO0_CLKCTRL->OPTFCLKEN_GPIO0_GDBCLK = CM_WKUP_CLK_ACTIVE;
            while (CM_WKUP_GPIO0_CLKCTRL->OPTFCLKEN_GPIO0_GDBCLK != CM_WKUP_CLK_ACTIVE);
            while (CM_WKUP_CONTROL_CLKCTRL->IDLEST != CM_WKUP_IDLEST_FUNCTIONAL);
            while (CM_L3_AON_CLKSTCTRL->CLKACTIVITY_L3_AON_GCLK != CM_WKUP_CLK_ACTIVE);
            while (CM_WKUP_L4WKUP_CLKCTRL->IDLEST != CM_WKUP_IDLEST_FUNCTIONAL);
            while (CM_WKUP_CLKSTCTRL->CLKACTIVITY_L4_WKUP_GCLK != CM_WKUP_CLK_ACTIVE);
            while (CM_L4_WKUP_AON_CLKSTCTRL->CLKACTIVITY_L4_WKUP_AON_GCLK != CM_WKUP_CLK_ACTIVE);
            while (CM_WKUP_GPIO0_CLKCTRL->IDLEST != CM_WKUP_IDLEST_FUNCTIONAL);
            while (CM_WKUP_CLKSTCTRL->CLKACTIVITY_GPIO0_GDBCLK != CM_WKUP_CLK_ACTIVE);
            break;
        case GPIOId::_1:
            CM_PER_GPIO1_CLKCTRL->MODULEMODE = CM_PER_MODULEMODE_ENABLE;
            while (CM_PER_GPIO1_CLKCTRL->MODULEMODE != CM_PER_MODULEMODE_ENABLE);
            CM_PER_GPIO1_CLKCTRL->OPTFCLKEN_GPIO_1_GDBCLK = CM_PER_CLK_ACTIVE;
            while (CM_PER_GPIO1_CLKCTRL->OPTFCLKEN_GPIO_1_GDBCLK != CM_PER_CLK_ACTIVE);
            while (CM_PER_GPIO1_CLKCTRL->IDLEST != CM_PER_IDLEST_FUNCTIONAL);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_GPIO_1_GDBCLK != CM_PER_CLK_ACTIVE);
            break;
        case GPIOId::_2:
            CM_PER_GPIO2_CLKCTRL->MODULEMODE = CM_PER_MODULEMODE_ENABLE;
            while (CM_PER_GPIO2_CLKCTRL->MODULEMODE != CM_PER_MODULEMODE_ENABLE);
            CM_PER_GPIO2_CLKCTRL->OPTFCLKEN_GPIO_2_GDBCLK = CM_PER_CLK_ACTIVE;
            while (CM_PER_GPIO2_CLKCTRL->OPTFCLKEN_GPIO_2_GDBCLK != CM_PER_CLK_ACTIVE);
            while (CM_PER_GPIO2_CLKCTRL->IDLEST != CM_PER_IDLEST_FUNCTIONAL);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_GPIO_2_GDBCLK != CM_PER_CLK_ACTIVE);
            break;
        case GPIOId::_3:
            CM_PER_GPIO3_CLKCTRL->MODULEMODE = CM_PER_MODULEMODE_ENABLE;
            while (CM_PER_GPIO3_CLKCTRL->MODULEMODE != CM_PER_MODULEMODE_ENABLE);
            CM_PER_GPIO3_CLKCTRL->OPTFCLKEN_GPIO_3_GDBCLK = CM_PER_CLK_ACTIVE;
            while (CM_PER_GPIO3_CLKCTRL->OPTFCLKEN_GPIO_3_GDBCLK != CM_PER_CLK_ACTIVE);
            while (CM_PER_GPIO3_CLKCTRL->IDLEST != CM_PER_IDLEST_FUNCTIONAL);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_GPIO_3_GDBCLK != CM_PER_CLK_ACTIVE);
            break;
    }

    enable();
    reset();

    m_initialized = true;
}

void AM335x_GPIO::reset()
{
    GPIO_SYSCONFIG(m_base)->SOFTRESET = true;
    while (!GPIO_SYSSTATUS(m_base)->RESETDONE);
}

void AM335x_GPIO::enable()
{
    GPIO_CTRL(m_base)->DISABLEMODULE = false;
}

void AM335x_GPIO::disable()
{
    GPIO_CTRL(m_base)->DISABLEMODULE = true;
}

bool AM335x_GPIO::setFunction(int id, Function function)
{
    if (function > Function::_7)
        return false;

    GPIO_PAD(id)->PAD_FUNC = static_cast<int>(function);
    GPIO_PAD(id)->PAD_SLOW_SLEWRATE = false;
    return true;
}

void AM335x_GPIO::setDirection(int pinNo, Direction direction)
{
    // TODO: Set also PAD_RECEIVER_ACTIVE using pin id.
    if (direction == Direction::Input)
        GPIO_OE(m_base)->OUTPUTENn |= PIN_MASK(pinNo);
    else
        GPIO_OE(m_base)->OUTPUTENn &= ~PIN_MASK(pinNo);
}

void AM335x_GPIO::setResistor(int id, Resitor resistor)
{
    GPIO_PAD(id)->PAD_PULLUP_DISABLE = (resistor == Resitor::None);
    if (resistor == Resitor::None)
        return;

    GPIO_PAD(id)->PAD_PULLUP_SELECT = (resistor == Resitor::PullUp);
}

std::uint32_t AM335x_GPIO::read()
{
    volatile std::uint32_t value = GPIO_DATAIN(m_base)->DATAINn;
    return value;
}

bool AM335x_GPIO::write(std::uint32_t value)
{
    if (value & GPIO_OE(m_base)->OUTPUTENn) {
        // Attempt to write to input pin.
        return false;
    }

    GPIO_DATAOUT(m_base)->DATAOUTn = value;
    return true;
}

bool AM335x_GPIO::writePin(int pinNo, bool state)
{
    if (pinNo < 0 || pinNo >= PIN_COUNT)
        return false;

    if (state)
        GPIO_SETDATAOUT(m_base)->INTLINEn = PIN_MASK(pinNo);
    else
        GPIO_CLEARDATAOUT(m_base)->INTLINEn = PIN_MASK(pinNo);

    return true;
}

} // namespace Device::GPIO
