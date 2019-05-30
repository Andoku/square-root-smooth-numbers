#include <iostream>
#include <vector>
#include <thread>

#include <math.h>

#include "Calculator.h"

Calculator::Calculator() :
numbersCounter(0),
progressCounter(0),
totalNumbers(0) {}

Calculator::~Calculator() {}

uint64_t Calculator::start(uint64_t upperLimit) {
    totalNumbers = upperLimit;
    //return countForRange(1, upperLimit);
    
    const size_t threadsNumber = std::thread::hardware_concurrency();
    const uint64_t range = upperLimit / threadsNumber;
    std::vector<std::thread> threads;
    uint64_t lower = 0;
    for(size_t i = 0; i < threadsNumber; ++i) {
        uint64_t upper = lower + range;
        if((upper > upperLimit) || (upperLimit - upper < range)) {
            upper = upperLimit;
        }
        
        threads.push_back(std::thread(&Calculator::countForRange, this, lower + 1, upper));
        std::cout << i << ": " << lower + 1 << " " << upper << "\n";
        lower += range;
    }
    
    while(progressCounter < totalNumbers) {
        const float percent = (float) progressCounter / totalNumbers * 100;
        std::cout << "\r" << percent << "% " << numbersCounter << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    for(auto &t : threads) {
        t.join();
    }
    return numbersCounter;
}

void Calculator::countForRange(uint64_t lowerLimit, uint64_t upperLimit) {
    for(uint64_t i = lowerLimit; i <= upperLimit; ++i) {
        if(isSquareRootSmooth(i)) {
            ++numbersCounter;
        }
        ++progressCounter;
    }
}

bool Calculator::isSquareRootSmooth(uint64_t number) const {
    if(isPerfectSquare(number)) {
        const uint64_t root = sqrt(number);
        return isPrime(root);
    }
    
    return isPrime(number);
}

bool Calculator::isPrime(uint64_t number) const {
    if(number <= 1) { 
        return false;
    } else if(number <= 3) {
        return true;
    } else if(number % 2 == 0 || number % 3 == 0) {
        return false;
    }
    
    const uint64_t root = sqrt(number);
    for (uint64_t i = 5; i <= root; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
           return false;
        }
    }

    return true;
}

bool Calculator::isPerfectSquare(uint64_t number) const {   
    const long double root = sqrt(number);
    return ((root - floor(root)) == 0); 
}

//bool Calculator::isPrime(uint64_t number) const {
//    if(number == 1) {
//        return false;
//    }
//  
//    const uint64_t root = sqrt(number);
//    for(uint64_t i = 2; i <= root; ++i) {
//        if(number % i == 0) {
//            return false;
//        }
//    }
//    
//    return true;
//}

//bool Calculator::isPerfectSquare(uint64_t number) const { 
//    uint64_t r = 1;
//    uint64_t i = 1;
//    
//	while(r < number) {
//		++i;
//		r = i * i;
//	}
//    
//	return (r == number);
//}