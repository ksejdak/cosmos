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
// - pinId      - unique number defining processor pin (ex. sequence number)
// - gpioPortNo - corresponding GPIO port number
// - gpioPinNo  - pin number within corresponding GPIO port
typedef struct {
    int gpioPortNo;
    int gpioPinNo;
} PinMux_t;

extern PinMux_t pinmux[];
extern int pinmuxSize;

class IGPIOPort {
public:
    IGPIOPort(int gpioPortNo);

    virtual void init() = 0;
    virtual int getPinsCount() = 0;

    virtual uint32_t read() = 0;
    virtual bool write(uint32_t value) = 0;
    virtual bool writePin(int gpioPinNo, bool state) = 0;

    virtual bool setPinFunction(int pinId, int function) = 0;

protected:
    int m_gpioPortNo;
};

class GPIOPin {
public:
    GPIOPin(int pinId, int function = 0);
    GPIOPin(int gpioPortNo, int gpioPinNo, int function);

    bool setFunction(int function);

    bool read();
    bool write(bool state);
    void toogle();

private:
    IGPIOPort& m_gpioPort;
    int m_gpioPinNo;
    int m_pinId;
};

class IGPIOManager : public Filesystem::Device {
public:
    static IGPIOManager* instance() {
        static IGPIOManager* object = create();
        return object;
    }

    virtual int getPortsCount() = 0;
    virtual int getPortBaseAddress(int gpioPortNo) = 0;

    virtual IGPIOPort& getPort(int gpioPortNo) = 0;

protected:
    static IGPIOManager* create();

    IGPIOManager() {}
};

} // namespace Device

#endif
