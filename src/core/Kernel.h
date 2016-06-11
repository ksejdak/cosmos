#ifndef KERNEL_H
#define KERNEL_H

class Kernel {
public:
    static Kernel& instance() {
        static Kernel object;
        return object;
    }

    Kernel(const Kernel& other) = delete;
    Kernel& operator=(Kernel other) = delete;

private:
    Kernel();
};

#endif
