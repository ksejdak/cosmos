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

namespace Device {

IGPIOManager* IGPIOManager::create()
{
    return new AM335x_GPIOManager();
}

AM335x_GPIOPort::AM335x_GPIOPort(AM335x_GPIOPortId_t id)
    : IGPIOPort(id)
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
    // TODO: implement.
    return 0;
}

AM335x_GPIOManager::AM335x_GPIOManager()
    : m_ports{ AM335x_GPIO_0,
               AM335x_GPIO_1,
               AM335x_GPIO_2,
               AM335x_GPIO_3 }
{
    // TODO:
    // - check REVISION register.
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

} // namespace Device
