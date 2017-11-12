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

namespace Device::GPIO {

enum class GPIOId {
    _0,
    _1,
    _2,
    _3
};

class AM335x_GPIO : public IGPIO<4> {
public:
    using id_type = GPIOId;
    friend class DeviceManager<AM335x_GPIO>;

public:
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

private:
    AM335x_GPIO();

private:
    GPIOId m_id;
    int m_base;

    static constexpr int PIN_COUNT  = 32;
    static int m_nextId;
};

} // namespace Device::GPIO

#endif
