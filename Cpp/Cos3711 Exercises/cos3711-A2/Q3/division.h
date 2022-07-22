#ifndef DIVISION_H
#define DIVISION_H

#include <math.h>
#include "operation.h"

class Division : public Operation
{
public:
    Division();
    double compute(double x, double y){
        if(y == 0){
            return NAN;
        }
        return (x / y);
    }
};

#endif // DIVISION_H
