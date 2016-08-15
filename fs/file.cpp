////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       15.08.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#include "file.h"

namespace Filesystem {

File::File()
    : m_offset(0)
{
}

bool File::open()
{
    return true;
}

bool File::close()
{
    return true;
}

int File::read(uint8_t*, uint32_t)
{
    return 0;
}

int File::write(uint8_t*, uint32_t)
{
    return 0;
}

bool File::ioctl(uint32_t, void*)
{
    return true;
}

} // namespace Filesystem
