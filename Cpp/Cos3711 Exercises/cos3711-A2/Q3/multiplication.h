#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "operation.h"

class Multiplication : public Operation
{
public:
    Multiplication();
    double compute(double x, double y){
        return (x * y);
    }
};

#endif // MULTIPLICATION_H
