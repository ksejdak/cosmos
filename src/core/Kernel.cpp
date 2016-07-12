#include "Kernel.h"
#include <list>

Kernel::Kernel()
{
    int a = 8;
    ++a;
    int b = a + 8;
    --b;

    std::list<int> l;
    l.push_back(a);
    l.push_back(b);

    throw "a";
}
