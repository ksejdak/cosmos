////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       27.12.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AM335X_GPIO_H
#define AM335X_GPIO_H

#include "am335x_gpio_regs.h"

#include <dev/device_manager.h>
#include <dev/gpio.h>

namespace Device {
namespace GPIO {

typedef enum {
    GPIO_0,
    GPIO_1,
    GPIO_2,
    GPIO_3
} GPIOId_t;

class AM335x_GPIOPort : public IGPIOPort {
public:
    AM335x_GPIOPort(GPIOId_t portNo);

    virtual void init() override;
    virtual void reset();
    virtual void enable();
    virtual void disable();

    virtual bool setFunction(int id, Function function);
    virtual void setDirection(int pinNo, Direction direction);
    virtual void setResistor(int id, Resitor resistor);

    virtual std::uint32_t read();
    virtual bool write(std::uint32_t value);
    virtual bool writePin(int pinNo, bool state);

public:
    static constexpr int PORT_COUNT = 4;
    static constexpr int PIN_COUNT  = 32;

private:
    static int getBaseAddress(int portNo);

private:
    GPIOId_t m_portNo;
    int m_base;
};

} // namespace GPIO

template <>
constexpr int DeviceManager<GPIO::IGPIOPort>::getDeviceCount()
{
    return GPIO::AM335x_GPIOPort::PORT_COUNT;
}

} // namespace Device

#endif
