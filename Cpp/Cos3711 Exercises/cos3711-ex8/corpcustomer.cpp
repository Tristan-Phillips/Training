#include "corpcustomer.h"

CorpCustomer::CorpCustomer(QString title,
                           QString name,
                           QStringList address,
                           QString postCode,
                           QString code,
                           double balance)
    : Customer(title, name, address, postCode, code, balance)
{
    m_discount = 20.0;
}

double CorpCustomer::calcAmtDue()
{
    return getBalance() * (100 - m_discount) / 100;
}
