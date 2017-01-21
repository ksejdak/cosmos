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
#include <os/stdint.h>

#define PIN_MASK(gpioPinNo)     (1 << gpioPinNo)

namespace Device {

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

typedef enum {
    GPIO_INPUT,
    GPIO_OUTPUT
} GPIODirection_t;

typedef enum {
    GPIO_RESISTOR_NONE,
    GPIO_RESISTOR_PULLUP,
    GPIO_RESISTOR_PULLDOWN
} GPIOResitor_t;

class IGPIOPort : public Filesystem::Device {
public:
    virtual void reset() = 0;
    virtual void enable() = 0;
    virtual void disable() = 0;

    virtual uint32_t read() = 0;
    virtual bool write(uint32_t value) = 0;
    virtual bool writePin(int pinNo, bool state) = 0;

    virtual bool setFunction(int id, int function) = 0;
    virtual void setDirection(int pinNo, GPIODirection_t direction) = 0;
    virtual void setResistor(int id, GPIOResitor_t resistor) = 0;
};

class GPIOPin {
public:
    GPIOPin(int id);
    GPIOPin(int portNo, int pinNo);

    bool setFunction(int function);
    void setDirection(GPIODirection_t direction);
    void setResistor(GPIOResitor_t resistor);

    bool read();
    bool write(bool state);
    void toggle();

private:
    IGPIOPort& m_port;
    int m_pinNo;
    int m_id;
};

} // namespace Device

#endif
