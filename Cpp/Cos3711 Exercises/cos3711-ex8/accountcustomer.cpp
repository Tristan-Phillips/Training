#include "accountcustomer.h"

AccountCustomer::AccountCustomer(QString title,
                           QString name,
                           QStringList address,
                           QString postCode,
                           QString code,
                           double balance)
    : Customer(title, name, address, postCode, code, balance)
{
    m_discount = 5.0;
}

double AccountCustomer::calcAmtDue()
{
    return getBalance() * (100 - m_discount) / 100;
}
