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
    static T& get(typename T::id_type id)
    {
        static T devices[T::count()];
        return devices[static_cast<int>(id)];
    }

    static void init()
    {
        for (int i = 0; i < T::count(); ++i)
            get(static_cast<typename T::id_type>(i)).init();
    }
};

} // namespace Device

#endif
