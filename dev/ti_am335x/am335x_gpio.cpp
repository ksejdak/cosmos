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
#include "am335x_gpio_regs.h"

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
}

int AM335x_GPIOPort::getPinsCount()
{
    return AM335x_GPIO_PINS_COUNT;
}

uint32_t AM335x_GPIOPort::read()
{
    volatile uint32_t value = (GPIO_DATAIN(m_base)->DATAINn & GPIO_OE(m_base));
    return value;
}

void AM335x_GPIOPort::write(uint32_t value)
{
    GPIO_DATAOUT(m_base)->DATAOUTn |= (value & ~(GPIO_OE(m_base)));
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

void AM335x_GPIOManager::init()
{
}

int AM335x_GPIOManager::getPortBaseAddress(AM335x_GPIOPortId_t id)
{
    switch (id) {
        case AM335x_GPIO_0:     return GPIO_0_BASE;
        case AM335x_GPIO_1:     return GPIO_1_BASE;
        case AM335x_GPIO_2:     return GPIO_2_BASE;
        case AM335x_GPIO_3:     return GPIO_3_BASE;
    }
}

} // namespace Device
