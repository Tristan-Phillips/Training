#ifndef ACCOUNTCUSTOMER_H
#define ACCOUNTCUSTOMER_H

#include "customer.h"

class AccountCustomer : public Customer
{
    Q_OBJECT
public:
    AccountCustomer(QString title, QString name, QStringList address, QString postCode,
                 QString code, double balance);
    double calcAmtDue();
};

#endif // ACCOUNTCUSTOMER_H
