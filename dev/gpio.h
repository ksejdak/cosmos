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

class IGPIOPort {
public:
    IGPIOPort(int id);

    virtual int getPinsCount() = 0;
    virtual uint32_t read() = 0;

private:
    int m_id;
};

class IGPIOManager : public Filesystem::Device {
public:
    static IGPIOManager* instance() {
        static IGPIOManager* object = create();
        return object;
    }

    virtual int getPortsCount() = 0;
    virtual IGPIOPort* getPort(int id) = 0;

protected:
    static IGPIOManager* create();

    IGPIOManager() {}
};

} // namespace Device

#endif
