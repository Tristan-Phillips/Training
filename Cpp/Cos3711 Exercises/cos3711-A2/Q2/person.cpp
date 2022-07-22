#include "person.h"

//3-arg constructor
Person::Person(QString n, QString cn, QString e): m_Name(n), m_ContactNo(cn), m_Email(e) {}

//creates and returns a string equivalent of a Person object
QString Person::toString() const {
    return "Name: " + m_Name + "\n\tContact number: " + m_ContactNo + "\n\tEmail: " + m_Email;
}

QString Person::get_name() const
{
    return m_Name;
}

QString Person::get_contactNumber() const
{
    return m_ContactNo;
}

QString Person::get_email() const
{
    return m_Email;
}
