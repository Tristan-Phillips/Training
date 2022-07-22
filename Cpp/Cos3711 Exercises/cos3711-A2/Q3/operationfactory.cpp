#include "operationfactory.h"
#include "addition.h"
#include "subtraction.h"
#include "multiplication.h"
#include "division.h"

OperationFactory* OperationFactory::onlyInstance = NULL;

OperationFactory::OperationFactory()
{}

OperationFactory *OperationFactory::get_Instance(){
    if(onlyInstance == NULL){
        onlyInstance = new OperationFactory();
    }
    return onlyInstance;
}

void OperationFactory::delete_Instance(){
    delete onlyInstance;
}

Operation *OperationFactory::createOperation(char type) const{
    switch (type) {
    case '+':
        return new Addition();
        break;
    case '-':
        return new Subtraction();
        break;
    case '*':
        return new Multiplication();
        break;
    case '/':
        return new Division();
        break;
    default:
        return NULL;
        break;
    }
}
