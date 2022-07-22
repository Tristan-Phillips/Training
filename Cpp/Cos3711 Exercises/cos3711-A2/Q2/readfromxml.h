#ifndef READFROMXML_H
#define READFROMXML_H

#include <QString>

#include "bookinglist.h"

class ReadFromXML
{
public:
    ReadFromXML();
    ~ReadFromXML();
    BookingList *loadFile(QString filePath);
private:
    BookingList *bookingList;
};

#endif // READFROMXML_H
