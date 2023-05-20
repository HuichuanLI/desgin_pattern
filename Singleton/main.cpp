#include <iostream>

#include "DBConfig.h"
#include <thread>


void func() {
    for (int i = 0; i < 100; i++) {
        DBConfig::getInstance();
    }
}

int main() {
    std::thread t1(func);
    std::thread t2(func);

    t1.join();
    t2.join();

    return 0;
}
