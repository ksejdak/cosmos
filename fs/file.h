////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       15.08.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef FILE_H
#define FILE_H

#include <os/stdint.h>

namespace Filesystem {

class File {
public:
    File();

    bool open();
    bool close();

    int read(uint8_t* buffer, uint32_t size);
    int write(uint8_t* buffer, uint32_t size);

    bool ioctl(uint32_t command, void* arg);

protected:
    uint32_t m_offset;
};

} // namespace Filesystem;

#endif
