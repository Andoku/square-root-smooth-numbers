#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <cstdint>
#include <atomic>

class Calculator {
public:
    Calculator();
    ~Calculator();
    
    uint64_t start(uint64_t upperLimit);
    
private:
    std::atomic<uint64_t> numbersCounter;
    std::atomic<uint64_t> progressCounter;
    uint64_t totalNumbers;
    
    void countForRange(uint64_t lowerLimit, uint64_t upperLimit);
    bool isSquareRootSmooth(uint64_t number) const;
    bool isPrime(uint64_t number) const;
    bool isPerfectSquare(uint64_t number) const;
};

#endif /* CALCULATOR_H */
