#ifndef LISTWRITER_H
#define LISTWRITER_H

#include "customerlistI.h"

class ListWriter
{
public:
    ListWriter(CustomerList cl);
    bool write(QString fileName = "customers.txt");

private:
    CustomerList m_list;
};

#endif // LISTWRITER_H
