#ifndef WRITETOXML_H
#define WRITETOXML_H

#include <QString>
#include <QDomDocument>

#include "bookinglist.h"

class WriteToXML
{
public:
    WriteToXML();
    QString writeXML(BookingList *list);

private:
    //XML vars
    QDomDocument m_doc;
    QDomElement m_rootElement;
    //Private Functions
    void writeDateToXML(QDomElement element, QString type, QDate date);
    void writePersonToXML(QDomElement element, QString type, Person *person);
};

#endif // WRITETOXML_H
