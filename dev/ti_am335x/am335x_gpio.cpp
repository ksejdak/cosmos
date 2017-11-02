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

namespace Device {

template <>
GPIO::IGPIOPort& DeviceManager<GPIO::IGPIOPort>::getDevice(int id)
{
    using namespace GPIO;

    static AM335x_GPIOPort ports[getDeviceCount()] {
        GPIO_0,
        GPIO_1,
        GPIO_2,
        GPIO_3
    };

    assert(id >= 0 && id < getDeviceCount());
    return ports[id];
}

namespace GPIO {

PinMux_t pinmux[] = AM335X_PINMUX;
int pinmuxSize = sizeof(pinmux) / sizeof(PinMux_t);

AM335x_GPIOPort::AM335x_GPIOPort(GPIOId_t portNo)
    : m_portNo(portNo)
    , m_base(getBaseAddress(portNo))
{
    // TODO:
    // - check REVISION register.
    // - register IRQ handler for given port.
    // - register /dev/gpioX device.
}

void AM335x_GPIOPort::init()
{
    using namespace Clock;

    if (m_initialized)
        return;

    // Enable interface and functional clocks.
    switch (m_portNo) {
        case GPIO_0:
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
        case GPIO_1:
            CM_PER_GPIO1_CLKCTRL->MODULEMODE = CM_PER_MODULEMODE_ENABLE;
            while (CM_PER_GPIO1_CLKCTRL->MODULEMODE != CM_PER_MODULEMODE_ENABLE);
            CM_PER_GPIO1_CLKCTRL->OPTFCLKEN_GPIO_1_GDBCLK = CM_PER_CLK_ACTIVE;
            while (CM_PER_GPIO1_CLKCTRL->OPTFCLKEN_GPIO_1_GDBCLK != CM_PER_CLK_ACTIVE);
            while (CM_PER_GPIO1_CLKCTRL->IDLEST != CM_PER_IDLEST_FUNCTIONAL);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_GPIO_1_GDBCLK != CM_PER_CLK_ACTIVE);
            break;
        case GPIO_2:
            CM_PER_GPIO2_CLKCTRL->MODULEMODE = CM_PER_MODULEMODE_ENABLE;
            while (CM_PER_GPIO2_CLKCTRL->MODULEMODE != CM_PER_MODULEMODE_ENABLE);
            CM_PER_GPIO2_CLKCTRL->OPTFCLKEN_GPIO_2_GDBCLK = CM_PER_CLK_ACTIVE;
            while (CM_PER_GPIO2_CLKCTRL->OPTFCLKEN_GPIO_2_GDBCLK != CM_PER_CLK_ACTIVE);
            while (CM_PER_GPIO2_CLKCTRL->IDLEST != CM_PER_IDLEST_FUNCTIONAL);
            while (CM_PER_L4LS_CLKSTCTRL->CLKACTIVITY_GPIO_2_GDBCLK != CM_PER_CLK_ACTIVE);
            break;
        case GPIO_3:
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

void AM335x_GPIOPort::reset()
{
    GPIO_SYSCONFIG(m_base)->SOFTRESET = true;
    while (!GPIO_SYSSTATUS(m_base)->RESETDONE);
}

void AM335x_GPIOPort::enable()
{
    GPIO_CTRL(m_base)->DISABLEMODULE = false;
}

void AM335x_GPIOPort::disable()
{
    GPIO_CTRL(m_base)->DISABLEMODULE = true;
}

bool AM335x_GPIOPort::setFunction(int id, Function function)
{
    if (function > Function::_7)
        return false;

    GPIO_PAD(id)->PAD_FUNC = static_cast<int>(function);
    GPIO_PAD(id)->PAD_SLOW_SLEWRATE = false;
    return true;
}

void AM335x_GPIOPort::setDirection(int pinNo, Direction direction)
{
    // TODO: Set also PAD_RECEIVER_ACTIVE using pin id.
    if (direction == Direction::Input)
        GPIO_OE(m_base)->OUTPUTENn |= PIN_MASK(pinNo);
    else
        GPIO_OE(m_base)->OUTPUTENn &= ~PIN_MASK(pinNo);
}

void AM335x_GPIOPort::setResistor(int id, Resitor resistor)
{
    GPIO_PAD(id)->PAD_PULLUP_DISABLE = (resistor == Resitor::None);
    if (resistor == Resitor::None)
        return;

    GPIO_PAD(id)->PAD_PULLUP_SELECT = (resistor == Resitor::PullUp);
}

std::uint32_t AM335x_GPIOPort::read()
{
    volatile std::uint32_t value = GPIO_DATAIN(m_base)->DATAINn;
    return value;
}

bool AM335x_GPIOPort::write(std::uint32_t value)
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
    if (pinNo < 0 || pinNo >= PIN_COUNT)
        return false;

    if (state)
        GPIO_SETDATAOUT(m_base)->INTLINEn = PIN_MASK(pinNo);
    else
        GPIO_CLEARDATAOUT(m_base)->INTLINEn = PIN_MASK(pinNo);

    return true;
}

int AM335x_GPIOPort::getBaseAddress(int portNo)
{
    switch (portNo) {
        case GPIO_0:     return GPIO_0_BASE;
        case GPIO_1:     return GPIO_1_BASE;
        case GPIO_2:     return GPIO_2_BASE;
        case GPIO_3:     return GPIO_3_BASE;
        default:         break;
    }

    return -1;
}

} // namespace GPIO
} // namespace Device
