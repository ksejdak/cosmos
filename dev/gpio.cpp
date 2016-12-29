////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       27.12.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#include "gpio.h"

namespace Device {

IGPIOPort::IGPIOPort(int portNo)
    : m_portNo(portNo)
{
}

GPIOPin::GPIOPin(int pinNo)
    : GPIOPin(pinmux[pinNo].port, pinmux[pinNo].pin)
{
}

GPIOPin::GPIOPin(int gpioPortNo, int gpioPinNo)
    : m_port(IGPIOManager::instance()->getPort(gpioPortNo))
    , m_pinNo(gpioPinNo)
{
}

bool GPIOPin::read()
{
    return (m_port.read() & PIN_MASK(m_pinNo));
}

bool GPIOPin::write(bool state)
{
    return m_port.writePin(m_pinNo, state);
}

void GPIOPin::toogle()
{
    volatile bool state = read();
    write(!state);
}

} // namespace Device
