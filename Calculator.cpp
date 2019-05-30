#include <iostream>

#include <math.h>

#include "Calculator.h"

Calculator::Calculator() {}

Calculator::~Calculator() {}

uint64_t Calculator::start(uint64_t upperLimit) {
    uint64_t counter = 0;
    for(uint64_t i = 1; i <= upperLimit; ++i) {
        if(isSquareRootSmooth(i)) {
            ++counter;
        }
        
        if(i % 10000 == 0) {
            const float percent = (float) i / upperLimit * 100;
            std::cout << "\r" << percent << "% " << counter;
        }
    }
    
    return counter;
}

bool Calculator::isSquareRootSmooth(uint64_t number) const {
    const double root = sqrt(number);
    
    while (number % 2 == 0) {  
        if(2 >= root) {
            return false;
        }
        number /= 2;  
    }  
  
    for (uint64_t i = 3; i <= root; i += 2) {  
        while (number % i == 0) {  
            if(i >= root) {
                return false;
            }
            number /= i;  
        }  
    }  
  
    if (number > 2 && number >= root) {
        return false;
    }
    
    return true;
}