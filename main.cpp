#include <cstdint>
#include <iostream>

#include "Calculator.h"

int main(int, char **) {
    Calculator calculator;
    const uint64_t upperLimit = 10000000000;
    std::cout << calculator.start(upperLimit) << "\n";
    return 0;
}
