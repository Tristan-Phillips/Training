#ifndef CUSTOMERFACTORY_H
#define CUSTOMERFACTORY_H

#include "customer.h"

class CustomerFactory
{
public:
    CustomerFactory();
    Customer* createCustomer(QString type,
                             QString title,
                             QString name,
                             QStringList address,
                             QString postCode,
                             QString code,
                             double balance);
};

#endif // CUSTOMERFACTORY_H
