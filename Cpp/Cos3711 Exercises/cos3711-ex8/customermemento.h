#ifndef CUSTOMERMEMENTO_H
#define CUSTOMERMEMENTO_H

#include "customer.h"

class CustomerMemento
{
public:
    ~CustomerMemento();

private:
    //All class members, other than destructor, are private
    friend class CustView;
    CustomerMemento();
    void setState(QList<Customer*> inState);
    QList<Customer*> getState();

    QList<Customer*> state;
};

#endif // CUSTOMERMEMENTO_H
