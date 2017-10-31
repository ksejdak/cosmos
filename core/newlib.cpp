////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       26.07.2017
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#include <cstdint>
#include <sys/types.h>

extern "C" {

int _open(const char *pathname __attribute__((unused)), int flags __attribute__((unused)), mode_t mode __attribute__((unused)))
{
    return -1;
}

int _close(int fd __attribute__((unused)))
{
    return -1;
}

int _read(int fd __attribute__((unused)), void *buf __attribute__((unused)), std::size_t count __attribute__((unused)))
{
    return 0;
}

int _write(int fd __attribute__((unused)), const void *buf __attribute__((unused)), std::size_t count __attribute__((unused)))
{
    return 0;
}

off_t _lseek(int fd __attribute__((unused)), off_t offset __attribute__((unused)), int whence __attribute__((unused)))
{
    return static_cast<off_t>(-1);
}

void _exit(int status __attribute__((unused)))
{
    while (true);
}

int _kill(pid_t pid __attribute__((unused)), int sig __attribute__((unused)))
{
    return -1;
}

pid_t _getpid()
{
    return 0;
}

int _fstat(int fd __attribute__((unused)), struct stat *buf __attribute__((unused)))
{
    return -1;
}

int _isatty(int fd __attribute__((unused)))
{
    return 0;
}

caddr_t _sbrk(intptr_t increment __attribute__((unused)))
{
    return NULL;
}

}
