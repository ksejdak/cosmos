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

namespace Device {

typedef struct {
    int port;
    int pin;
} PinMux_t;

extern PinMux_t pinmux[];

class IGPIOPort {
public:
    IGPIOPort(int portNo);

    virtual void init() = 0;
    virtual int getPinsCount() = 0;
    virtual uint32_t read() = 0;
    virtual void write(uint32_t value) = 0;
    virtual void writePin(int pinNo, bool state) = 0;

protected:
    int m_portNo;
};

class GPIOPin {
public:
    GPIOPin(int pinNo);
    GPIOPin(int gpioPortNo, int gpioPinNo);

    bool read();
    void write(bool state);
    void toogle();

private:
    IGPIOPort& m_port;
    int m_pinNo;
};

class IGPIOManager : public Filesystem::Device {
public:
    static IGPIOManager* instance() {
        static IGPIOManager* object = create();
        return object;
    }

    virtual int getPortsCount() = 0;
    virtual IGPIOPort& getPort(int portNo) = 0;
    virtual int getPortBaseAddress(int portNo) = 0;

protected:
    static IGPIOManager* create();

    IGPIOManager() {}
};

} // namespace Device

#endif
