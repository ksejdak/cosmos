extern "C" {

#include <sys/stat.h>

void _exit(int) {}
int _getpid() { return 0; }
int _sbrk(int) { return 0; }
int _kill(int, int) { return 0; }
int _close(int) { return 0; }
unsigned int _write(int, const void *, unsigned int) { return 0; }
unsigned int _read(int, void *, unsigned int) { return 0; }
int _open(const char *, int) { return 0; }
off_t _lseek(int, off_t, int) { return 0; }
int _fstat(int, struct stat *) { return 0; }

}
