#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include "operation.h"

class Subtraction : public Operation
{
public:
    Subtraction();
    double compute(double x, double y){
        return (x - y);
    }
};

#endif // SUBTRACTION_H
