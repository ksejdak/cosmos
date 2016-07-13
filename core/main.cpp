#include <core/Kernel.h>

int main()
{
    int a = 5;
    while (true) {
        a++;
        int b = a + 3;
        a++;

        Kernel::instance();
    }

    return 0;
}
