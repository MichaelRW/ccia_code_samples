

#include <iostream>
#include <thread>


void hello() {
    std::cout << "Hello Concurrent World\n";
};

void bigLoop() {
    double product = 1.0;

    for (int i = 0; i < 1e6; i++) {
        product = product * i;
        std::cout << product;
    };
};


int main() {

    /*std::thread t1(bigLoop); t1.join();
    std::thread t2(bigLoop); t2.join();*/


    std::thread t(hello);
    t.join();
};
