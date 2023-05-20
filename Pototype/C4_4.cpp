#include <stdio.h>

class A {
public:
    A() {
        printf("A()\n");
    }

    virtual ~A() {
        printf("~A()\n");
    }

    A(const A &a) {
        printf("A(const A & a)\n");
        *this = a;
    }

    A &operator=(const A &a) {
        printf("A & operator = (const A & a)\n");
        return *this;
    }

    virtual void func() {
        printf("A::func()\n");
    }

    void func2() {
        printf("A::func2()\n");
    }
};

class B : public A {
public:
    B() {
        printf("B()\n");
    }

    ~B() {
        printf("~B()\n");
    }

    B(const B &b) {
        printf("B(const A & b)\n");
        *this = b;
    }

    B &operator=(const B &b) {
        printf("B & operator = (const B & b)\n");
        return *this;
    }

    virtual void func() override {
        printf("B::func()\n");
    }
};

int main() {
    A *a = nullptr;

    a->func2();

    return 0;
}