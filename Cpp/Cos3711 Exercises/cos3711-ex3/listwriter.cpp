#include "listwriter.h"
#include "filewriter.h"

ListWriter::ListWriter(CustomerList cl)
    : m_list(cl)
{
}

bool ListWriter::write(QString fileName)
{
    QString outStr;

    foreach(Customer cust, m_list.getList()) {
        outStr.append(QString("%1#%2#%3#%4#%5\n")
                      .arg(cust.getTitle())
                      .arg(cust.getName())
                      .arg(cust.getAddress().join("*"))
                      .arg(cust.getPostCode())
                      .arg(cust.getCode()));
    }

    FileWriter fw(fileName);
    if (!fw.write(outStr)) {
        return false;
    }

    return true;
}
