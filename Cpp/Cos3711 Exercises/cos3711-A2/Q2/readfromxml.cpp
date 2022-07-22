#include "readfromxml.h"
#include "single.h"
#include "sharing.h"

#include <QFile>
#include <QDate>
#include <QDomElement>
#include <QDomDocument>

ReadFromXML::ReadFromXML() :
    bookingList{new BookingList}
{}

ReadFromXML::~ReadFromXML()
{}

BookingList *ReadFromXML::loadFile(QString filePath)
{
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        //File cant open
        return nullptr;
    }

    QDomDocument doc;
    if(!doc.setContent(&file)){
        return nullptr;
    }

    QDomElement root = doc.firstChildElement();
    if(root.tagName() != "bookinglist"){
        return nullptr;
    }

    QDomNodeList nodes = root.elementsByTagName("booking");
    for(int i = 0; i < nodes.count(); i++){
        //Arrival Date
        QDate arrivalDate = QDate::currentDate();
        //Departure Date
        QDate departureDate = QDate::currentDate();

        Person *contactPerson = nullptr;
        Person *guestOne = nullptr;
        Person *guestTwo = nullptr;

        QDomNode attributes = nodes.at(i).firstChild();

        if(attributes.toElement().tagName() == "contact"){
            QString contactName = attributes.toElement().attribute("name");
            QString contactContactNumber = attributes.toElement().attribute("telnumber");
            QString contactEmail = attributes.toElement().attribute("email");
            contactPerson = new Person(contactName, contactContactNumber, contactEmail);
            attributes = attributes.nextSibling();
            if(attributes.toElement().tagName() == "arrivaldate"){
                arrivalDate = QDate::fromString(attributes.toElement().text(), "yyyy/MM/dd");
                attributes = attributes.nextSibling();
                if(attributes.toElement().tagName() == "departuredate"){
                    departureDate = QDate::fromString(attributes.toElement().text(), "yyyy/MM/dd");
                    attributes = attributes.nextSibling();
                    if(attributes.toElement().tagName() == "guestone"){
                        QString guestOneName = attributes.toElement().attribute("name");
                        QString guestOneContactNumber = attributes.toElement().attribute("telnumber");
                        QString guestOneEmail = attributes.toElement().attribute("email");
                        guestOne = new Person(guestOneName, guestOneContactNumber, guestOneEmail);
                        attributes = attributes.nextSibling();
                        if(attributes.toElement().tagName() == "guesttwo"){
                            QString guestTwoName = attributes.toElement().attribute("name");
                            QString guestTwoContactNumber = attributes.toElement().attribute("telnumber");
                            QString guestTwoEmail = attributes.toElement().attribute("email");
                            guestTwo = new Person(guestTwoName, guestTwoContactNumber, guestTwoEmail);
                        }
                        bookingList->addBooking(contactPerson, arrivalDate, departureDate, guestOne, guestTwo);
                    }
                }
            }
        }
    }
    return bookingList;
}
