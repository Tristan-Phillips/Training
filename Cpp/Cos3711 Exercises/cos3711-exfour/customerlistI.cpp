#include "customerlistI.h"

CustomerList::CustomerList()
{
}

QList<Customer> CustomerList::getList() const
{
    QList<Customer> list;

    for (int count = 0; count < list.size(); count++) {
        list.append(this->at(count));
    }

    return list;
}

QString CustomerList::toString() const
{
    QString outStr;

    for (int count = 0; count < this->size(); count++) {
        outStr += this->at(count).toString() + "\n\n";
    }

    return outStr;
}
