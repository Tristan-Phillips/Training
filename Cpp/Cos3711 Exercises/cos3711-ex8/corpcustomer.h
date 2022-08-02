#ifndef CORPCUSTOMER_H
#define CORPCUSTOMER_H

#include "customer.h"

class CorpCustomer : public Customer
{
    Q_OBJECT
public:
    CorpCustomer(QString title, QString name, QStringList address, QString postCode,
                 QString code, double balance);
    double calcAmtDue();
};

#endif // CORPCUSTOMER_H
