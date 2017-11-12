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

#include <cstdint>

namespace Filesystem {

class File {
public:
    enum class FileType {
        Regular,
        Device
    };

    File(FileType fileType = FileType::Regular);
    FileType fileType() const;

    bool open();
    bool close();

    int read(std::uint8_t* buffer, std::uint32_t size);
    int write(std::uint8_t* buffer, std::uint32_t size);

protected:
    FileType m_fileType;
    std::uint32_t m_offset;
};

} // namespace Filesystem;

#endif
