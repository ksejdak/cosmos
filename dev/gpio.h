////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       27.12.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef GPIO_H
#define GPIO_H

#include <fs/device.h>

#define PIN_MASK(gpioPinNo)     ((std::uint32_t) (1 << gpioPinNo))

namespace Device::GPIO {

// Each pin has following description:
// - id      - unique number defining processor pin (ex. sequence number)
// - portNo  - corresponding GPIO port number
// - pinNo   - pin number within corresponding GPIO port
typedef struct {
    int portNo;
    int pinNo;
} PinMux_t;

extern PinMux_t pinmux[];
extern int pinmuxSize;

enum class Function {
    _0,
    _1,
    _2,
    _3,
    _4,
    _5,
    _6,
    _7
};

enum class Direction {
    Input,
    Output
};

enum class Resitor {
    None,
    PullUp,
    PullDown
};

class IGPIOPort : public Filesystem::Device {
public:
    virtual void reset() = 0;
    virtual void enable() = 0;
    virtual void disable() = 0;

    virtual bool setFunction(int id, Function function) = 0;
    virtual void setDirection(int pinNo, Direction direction) = 0;
    virtual void setResistor(int id, Resitor resistor) = 0;

    virtual std::uint32_t read() = 0;
    virtual bool write(std::uint32_t value) = 0;
    virtual bool writePin(int pinNo, bool state) = 0;
};

class GPIOPin {
public:
    GPIOPin(int id);
    GPIOPin(int portNo, int pinNo);

    bool setFunction(Function function);
    void setDirection(Direction direction);
    void setResistor(Resitor resistor);

    bool read();
    bool write(bool state);
    void toggle();

private:
    IGPIOPort& m_port;
    int m_pinNo;
    int m_id;
};

} // namespace Device::GPIO

#endif
