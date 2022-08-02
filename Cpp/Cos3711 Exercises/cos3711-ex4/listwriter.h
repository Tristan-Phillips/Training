#ifndef LISTWRITER_H
#define LISTWRITER_H

#include <QString>
class CustomerList;

class ListWriter
{
public:
    ListWriter(CustomerList *cl);
    bool write(QString fileName = "customers.txt");

private:
    CustomerList *list;
};

#endif // LISTWRITER_H
