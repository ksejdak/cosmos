#ifndef KERNEL_H
#define KERNEL_H

class A {
public:
    virtual void fun() {
        volatile int a = 0;
        ++a;
    }
};

class B : public A {
public:
    virtual void fun() {
        volatile int b = 0;
        ++b;
    }
};

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
