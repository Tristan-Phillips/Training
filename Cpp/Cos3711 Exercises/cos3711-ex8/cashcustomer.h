#ifndef CASHCUSTOMER_H
#define CASHCUSTOMER_H

#include "customer.h"

class CashCustomer : public Customer
{
    Q_OBJECT
public:
    CashCustomer(QString title, QString name, QStringList address, QString postCode,
                 QString code, double balance);
    double calcAmtDue();
};

#endif // CASHCUSTOMER_H
