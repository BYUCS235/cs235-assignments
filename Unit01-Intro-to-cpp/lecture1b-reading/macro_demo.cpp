#include <iostream>

#define SEVEN 7

#include "debug.h"

void message(int num) {
    TRACE
    TRACK(num)
    std::cout << "message: " << SEVEN + num << std::endl;
    TRACE
}

int main() {
    message(8);
    std::cout << "hello world!" << std::endl;
    message(9);
}