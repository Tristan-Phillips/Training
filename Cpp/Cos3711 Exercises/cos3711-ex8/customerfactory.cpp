#include "customerfactory.h"
#include "cashcustomer.h"
#include "accountcustomer.h"
#include "corpcustomer.h"

CustomerFactory::CustomerFactory()
{
}

Customer* CustomerFactory::createCustomer(QString type,
                         QString title,
                         QString name,
                         QStringList address,
                         QString postCode,
                         QString code,
                         double balance)
{
    if (type == "CashCustomer") {
        return new CashCustomer(title, name, address, postCode, code, balance);
    }
    else if (type == "AccountCustomer") {
        return new AccountCustomer(title, name, address, postCode, code, balance);
    }
    else if (type == "CorpCustomer") {
        return new CorpCustomer(title, name, address, postCode, code, balance);
    }
    else {
        return nullptr;
    }
}
