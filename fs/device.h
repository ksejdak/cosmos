////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       21.08.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef DEVICE_H
#define DEVICE_H

#include "file.h"

#include <os/stdint.h>

namespace Filesystem {

class Device : public File {
public:
    Device();
    virtual void init();

    virtual bool ioctl(uint32_t command, void* arg);

protected:
    bool m_initialized;
};

} // namespace Filesystem;

#endif
