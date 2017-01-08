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
} AM335x_GPIOId_t;

class AM335x_GPIOPort : public IGPIOPort {
public:
    AM335x_GPIOPort(AM335x_GPIOId_t portNo);

    virtual void init();
    virtual int getPinCount();

    virtual uint32_t read();
    virtual bool write(uint32_t value);
    virtual bool writePin(int pinNo, bool state);

    virtual bool setFunction(int id, int function);
    virtual void setDirection(int id, GPIODirection_t direction);

private:
    static const int AM335x_GPIO_PIN_COUNT = 32;

    int m_base;
};

class AM335x_GPIOManager : public IGPIOManager {
public:
    AM335x_GPIOManager();

    virtual int getPortCount();
    virtual IGPIOPort& getPort(int portNo);

private:
    static const int AM335x_GPIO_PORT_COUNT = 4;

    AM335x_GPIOPort m_ports[AM335x_GPIO_PORT_COUNT];
};

} // namespace Device

#endif
