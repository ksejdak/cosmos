////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       26.07.2017
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#include <array>
#include <cstdint>
#include <sys/types.h>

extern "C" {

caddr_t _sbrk(intptr_t increment)
{
    static std::array<char, 1024> buffer;
    static std::size_t offset = 0;

    std::size_t prevOffset = offset;

    if (offset + increment > buffer.size())
        return nullptr;

    offset += increment;
    return &buffer[prevOffset];
}

int _write(int, const void *buf __attribute__((unused)), std::size_t count __attribute__((unused)))
{
    return 0;
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
