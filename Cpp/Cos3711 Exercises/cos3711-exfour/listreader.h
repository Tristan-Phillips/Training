#ifndef LISTREADER_H
#define LISTREADER_H

#include <QString>
class CustomerList;

class ListReader
{
public:
    ListReader();
    CustomerList read(QString fileName = "customers.txt") const;
};

#endif // LISTREADER_H
