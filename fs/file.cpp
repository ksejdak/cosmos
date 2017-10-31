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

File::File(FileType fileType)
    : m_fileType(fileType)
    , m_offset(0)
{
}

File::FileType File::fileType() const
{
    return m_fileType;
}

bool File::open()
{
    return true;
}

bool File::close()
{
    return true;
}

int File::read(std::uint8_t*, std::uint32_t)
{
    return 0;
}

int File::write(std::uint8_t*, std::uint32_t)
{
    return 0;
}

} // namespace Filesystem
