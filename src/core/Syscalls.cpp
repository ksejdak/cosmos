extern "C" {

void _exit(int) {}
int _getpid() { return 0; }
int _sbrk(int) { return 0; }
int _kill(int, int) { return 0; }

}
