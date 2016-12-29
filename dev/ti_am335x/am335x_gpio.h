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
    AM335x_GPIOPort(AM335x_GPIOPortId_t portNo);

    virtual void init();
    virtual int getPinsCount();
    virtual uint32_t read();
    virtual void write(uint32_t value);
    virtual void writePin(int pinNo, bool state);

private:
    static const int AM335x_GPIO_PINS_COUNT = 32;

    int m_base;
};

class AM335x_GPIOManager : public IGPIOManager {
public:
    AM335x_GPIOManager();

    virtual int getPortsCount();
    virtual IGPIOPort& getPort(int portNo);
    virtual int getPortBaseAddress(int portNo);

private:
    void init();

private:
    static const int AM335x_GPIO_PORTS_COUNT = 4;

    AM335x_GPIOPort m_ports[AM335x_GPIO_PORTS_COUNT];
};

} // namespace Device

#endif
