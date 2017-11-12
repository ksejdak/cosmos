////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       26.07.2017
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

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
