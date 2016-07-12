#include <core/Kernel.h>
#include <exception>

int main()
{
    int a = 5;
    while (true) {
        a++;
        int b = a + 3;
        a++;

        try {
            Kernel::instance();
        }
        catch (std::exception& e) {
            const char *msg = e.what();
        }
    }

    return 0;
}
