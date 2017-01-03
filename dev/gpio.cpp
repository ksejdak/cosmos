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

IGPIOPort::IGPIOPort(int gpioPortNo)
    : m_gpioPortNo(gpioPortNo)
{
}

GPIOPin::GPIOPin(int pinId)
    : GPIOPin(pinmux[pinId].gpioPortNo, pinmux[pinId].gpioPinNo)
{
}

GPIOPin::GPIOPin(int gpioPortNo, int gpioPinNo)
    : m_gpioPort(IGPIOManager::instance()->getPort(gpioPortNo))
    , m_gpioPinNo(gpioPinNo)
    , m_pinId(-1)
{
    for (int i = 0; i < pinmuxSize; ++i) {
        if (pinmux[i].gpioPortNo == gpioPortNo && pinmux[i].gpioPinNo == gpioPinNo) {
            m_pinId = i;
            break;
        }
    }
}

bool GPIOPin::setFunction(int function)
{
    return m_gpioPort.setPinFunction(m_pinId, function);
}

void GPIOPin::setDirection(GPIODirection_t direction)
{
    m_gpioPort.setPinDirection(m_gpioPinNo, direction);
}

bool GPIOPin::read()
{
    return (m_gpioPort.read() & PIN_MASK(m_gpioPinNo));
}

bool GPIOPin::write(bool state)
{
    return m_gpioPort.writePin(m_gpioPinNo, state);
}

void GPIOPin::toogle()
{
    volatile bool state = read();
    write(!state);
}

} // namespace Device
