#include "booking.h"

//3-arg constructor
Booking::Booking(Person *c, QDate a, QDate d): m_Contact(c), m_ArrivalDate(a), m_DepartureDate(d),SINGLE_PPPN(300),SHARING_PPPN(500) {
}

Booking::~Booking(){
    delete m_Contact;
}

//checks and returns whether a booking is made for a given date
bool Booking::booked(QDate d) const{
    return d >= m_ArrivalDate && d < m_DepartureDate;
}
//creates and returns a string representation of a Booking instance
QString Booking::toString() const {
    return "Contact: " + m_Contact->toString() + "\nDate of arrival: " +
    m_ArrivalDate.toString() + "\nDate of departure: " +
            m_DepartureDate.toString();
}

Person *Booking::get_person() const
{
    return m_Contact;
}

QDate Booking::get_arrivalDate() const
{
    return m_ArrivalDate;
}

QDate Booking::get_departure() const
{
    return m_DepartureDate;
}
