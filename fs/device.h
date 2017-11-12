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

#include <cstdint>
#include <cstring>

namespace Filesystem {

template <int N>
class Device : public File {
public:
    static constexpr int count() { return N; }

public:
    Device()
        : File(FileType::Device)
        , m_initialized(false)
    {
    }

    // Initialization.
    virtual void init()
    {
        m_initialized = true;
    }

    // I/O operations.
    virtual std::size_t read(void* buff __attribute__((unused)), std::size_t size __attribute__((unused)))
    {
        return 0;
    }

    virtual std::size_t write(const void* buff __attribute__((unused)), std::size_t size __attribute__((unused)))
    {
        return 0;
    }

    virtual bool ioctl(std::uint32_t command __attribute__((unused)), void* arg __attribute__((unused)))
    {
        return true;
    }

protected:
    bool m_initialized;
};

} // namespace Filesystem;

#endif
