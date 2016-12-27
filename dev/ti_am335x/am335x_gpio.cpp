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

namespace Device {

IGPIOManager* IGPIOManager::create()
{
    return new AM335x_GPIOManager();
}

AM335x_GPIOPort::AM335x_GPIOPort(AM335x_GPIOPortId_t id)
    : IGPIOPort(id)
    , m_base(IGPIOManager::instance()->getPortBaseAddress(id))
{
    // TODO:
    // - register IRQ handler for given port
    // - register /dev/gpioX device.
}

void AM335x_GPIOPort::init()
{
    // Enable interface clock.
    switch (m_id) {
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

void AM335x_GPIOPort::write(uint32_t value)
{
    GPIO_DATAOUT(m_base)->DATAOUTn |= (value & ~(GPIO_OE(m_base)->OUTPUTENn));
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

int AM335x_GPIOManager::getPortsCount()
{
    return AM335x_GPIO_PORTS_COUNT;
}

IGPIOPort* AM335x_GPIOManager::getPort(int id)
{
    if (id < 0 || id >= AM335x_GPIO_PORTS_COUNT)
        return nullptr;

    return &m_ports[id];
}

int AM335x_GPIOManager::getPortBaseAddress(int id)
{
    switch (id) {
        case AM335x_GPIO_0:     return GPIO_0_BASE;
        case AM335x_GPIO_1:     return GPIO_1_BASE;
        case AM335x_GPIO_2:     return GPIO_2_BASE;
        case AM335x_GPIO_3:     return GPIO_3_BASE;
    }

    return -1;
}

void AM335x_GPIOManager::init()
{
}

} // namespace Device
