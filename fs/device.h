////////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2017, Kuba Sejdak <kuba.sejdak@gmail.com>
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
////////////////////////////////////////////////////////////////////////////////////

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
