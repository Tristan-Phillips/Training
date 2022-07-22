#include "sharing.h"

//5-arg constructor
Sharing::Sharing(Person *c, QDate a, QDate d, Person *g1, Person *g2): Booking(c, a, d), m_Guest1(g1), m_Guest2(g2) {}

Sharing::~Sharing(){
    delete m_Guest1;
    delete m_Guest2;
}

//creates and returns a string equivalent of a Sharing object
QString Sharing::toString() const {
    return Booking::toString() + "\nGuest 1: " + m_Guest1->toString() +"\nGuest 2: "
    + m_Guest2->toString();
}

//computes and returns the rate of a shared booking
double Sharing::rate()const{
    return 2 * Booking::SHARING_PPPN;
}

Person *Sharing::get_guestOne() const
{
    return m_Guest1;
}

Person *Sharing::get_guestTwo() const
{
    return m_Guest2;
}
