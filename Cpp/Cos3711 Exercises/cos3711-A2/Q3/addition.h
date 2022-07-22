#ifndef ADDITION_H
#define ADDITION_H

#include "operation.h"

class Addition : public Operation
{
public:
    Addition();
    double compute(double x, double y){
        return (x+y);
    }
};

#endif // ADDITION_H
