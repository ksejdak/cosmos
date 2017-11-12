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

#include <dev/device_manager.h>
#include <dev/ti_am335x/am335x_uart.h>

#include <array>
#include <cstdint>
#include <sys/types.h>

using namespace Device;
using namespace Device::UART;

extern "C" {

caddr_t _sbrk(intptr_t increment)
{
    static std::array<char, 2048> buffer;
    static std::size_t offset = 0;

    std::size_t prevOffset = offset;

    if (offset + increment > buffer.size())
        return nullptr;

    offset += increment;
    return &buffer[prevOffset];
}

int _write(int, const void *buf, std::size_t count)
{
    auto& consoleUart = DeviceManager<AM335x_UART>::get(UARTId::_0);
    return consoleUart.write(buf, count);
}

int _open(const char *, int, mode_t)    { return -1; }
int _close(int)                         { return -1; }
int _read(int, void *, std::size_t)     { return 0; }
off_t _lseek(int, off_t, int)           { return static_cast<off_t>(-1); }
void _exit(int)                         { while (true); }
int _kill(pid_t, int)                   { return -1; }
pid_t _getpid()                         { return 0; }
int _fstat(int, struct stat *)          { return -1; }
int _isatty(int)                        { return 0; }

}
