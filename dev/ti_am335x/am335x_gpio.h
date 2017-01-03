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

#include "am335x_gpio_pad.h"
#include "am335x_gpio_regs.h"

#include <dev/gpio.h>

namespace Device {

typedef enum {
    AM335x_GPIO_0,
    AM335x_GPIO_1,
    AM335x_GPIO_2,
    AM335x_GPIO_3
} AM335x_GPIOPortId_t;

class AM335x_GPIOPort : public IGPIOPort {
public:
    AM335x_GPIOPort(AM335x_GPIOPortId_t gpioPortNo);

    virtual void init();
    virtual int getPinsCount();

    virtual uint32_t read();
    virtual bool write(uint32_t value);
    virtual bool writePin(int gpioPinNo, bool state);

    virtual bool setPinFunction(int pinId, int function);
    virtual bool setPinDirection(int gpioPinNo, GPIODirection_t direction);

private:
    static const int AM335x_GPIO_PINS_COUNT = 32;

    int m_base;
};

class AM335x_GPIOManager : public IGPIOManager {
public:
    AM335x_GPIOManager();

    virtual int getPortsCount();
    virtual int getPortBaseAddress(int gpioPortNo);

    virtual IGPIOPort& getPort(int gpioPortNo);

private:
    static const int AM335x_GPIO_PORTS_COUNT = 4;

    AM335x_GPIOPort m_ports[AM335x_GPIO_PORTS_COUNT];
};

} // namespace Device

#endif
