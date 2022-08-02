#include "listreader.h"
#include "filereader.h"
#include "customerlistI.h"
#include <QStringList>

#include <QDebug>

ListReader::ListReader()
{
}

CustomerList ListReader::read(QString fileName) const
{
    // Read Customer data from file
    FileReader fr(fileName);
    QString inStr(fr.read().trimmed());

    // Instantiate and populate CustomerList object
    CustomerList cl;

    // Split input string into separate lines
    QStringList inData(inStr.split("\n"));
    QStringList line;

    // Instantiate and populate Customer objects
    for (int count = 0; count < inData.size(); count++) {

        // Split each line QString to QStringList
        line = inData.at(count).split("#");

        Customer cust(line.at(0), line.at(1), line.at(2).split("*"), line.at(3), line.at(4));
        cl.append(cust);
    }

    return cl;
}
