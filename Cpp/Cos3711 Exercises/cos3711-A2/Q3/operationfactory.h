#ifndef OPERATIONFACTORY_H
#define OPERATIONFACTORY_H

#include "operation.h"

class OperationFactory
{
public:
    //Operation is a abstract class
    Operation *createOperation(char type) const;
    static OperationFactory *get_Instance();
    static void delete_Instance();
private:
    OperationFactory();
    static OperationFactory *onlyInstance;
};

#endif // OPERATIONFACTORY_H
