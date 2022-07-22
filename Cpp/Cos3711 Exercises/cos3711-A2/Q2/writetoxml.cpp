#include "writetoxml.h"
#include "single.h"
#include "sharing.h"

WriteToXML::WriteToXML()
{
    m_rootElement = m_doc.createElement("bookinglist");
    m_doc.appendChild(m_rootElement);
}

QString WriteToXML::writeXML(BookingList *list)
{

    for(int i = 0; i < list->size(); i++){
        Booking *booking = list->at(i);

        const QMetaObject *metaObj = booking->metaObject();
        QString className = QString(metaObj->className());

        QDomElement bookingElement = m_doc.createElement("booking");
        bookingElement.setAttribute("type", className);
        m_rootElement.appendChild(bookingElement);

        //Add the contact person to XML
        writePersonToXML(bookingElement, "contact", booking->get_person());

        //Write Arrival Date
        writeDateToXML(bookingElement, "arrivaldate", booking->get_arrivalDate());
        //Write Departure Date
        writeDateToXML(bookingElement, "departuredate", booking->get_departure());

        //Guest to XML
        if(className == "Single"){
            Single *single = qobject_cast<Single*>(booking);
            writePersonToXML(bookingElement, "guestone", single->getGuest());
        }else{
            Sharing *sharing = qobject_cast<Sharing*>(booking);
            writePersonToXML(bookingElement, "guestone", sharing->get_guestOne());
            writePersonToXML(bookingElement, "guesttwo", sharing->get_guestTwo());
        }
    }
    return m_doc.toString();
}

void WriteToXML::writeDateToXML(QDomElement element, QString type, QDate date)
{
    QDomElement dateElement = m_doc.createElement(type);
    QDomText dateText = m_doc.createTextNode(date.toString("yyyy/MM/dd"));
    dateElement.appendChild(dateText);
    element.appendChild(dateElement);
}

void WriteToXML::writePersonToXML(QDomElement element, QString type, Person *person)
{
    QDomElement personElement = m_doc.createElement(type);
    personElement.setAttribute("name", person->get_name());
    personElement.setAttribute("telnumber", person->get_contactNumber());
    personElement.setAttribute("email", person->get_email());
    element.appendChild(personElement);
}
