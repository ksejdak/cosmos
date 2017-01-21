////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       21.01.2017
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef DEVICE_MANAGER_H
#define DEVICE_MANAGER_H

namespace Device {

template <typename T>
class DeviceManager {
public:
    static constexpr int getDeviceCount();
    static T& getDevice(int id);

    static void init() {
        constexpr int count = getDeviceCount();
        for (int i = 0; i < count; ++i)
            getDevice(i).init();
    }
};

} // namespace Device

#endif
