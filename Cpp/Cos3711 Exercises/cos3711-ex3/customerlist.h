#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

/**************************
 * CustomerList implemented using composition
 *************************/

#include "customer.h"

class CustomerList
{
public:
    CustomerList();
    void append(Customer c);
    void clear();
    QList<Customer> getList() const;
    QString toString() const;

private:
    QList<Customer> list;
};

#endif // CUSTOMERLIST_H
