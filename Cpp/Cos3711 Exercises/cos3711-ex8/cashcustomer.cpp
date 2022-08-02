#include "cashcustomer.h"

CashCustomer::CashCustomer(QString title,
                           QString name,
                           QStringList address,
                           QString postCode,
                           QString code,
                           double balance)
    : Customer(title, name, address, postCode, code, balance)
{
    m_discount = 10.0;
}

double CashCustomer::calcAmtDue()
{
    return getBalance() * (100 - m_discount) / 100;
}
