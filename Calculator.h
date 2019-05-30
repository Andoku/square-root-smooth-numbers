#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <cstdint>

class Calculator {
public:
    Calculator();
    ~Calculator();
    
    uint64_t start(uint64_t upperLimit);
    
private:
    bool isSquareRootSmooth(uint64_t number) const;  
};

#endif /* CALCULATOR_H */
