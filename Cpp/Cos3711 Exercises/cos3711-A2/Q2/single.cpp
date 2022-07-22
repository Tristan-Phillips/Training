#include "single.h"

//4-arg constructor
Single::Single(Person *c, QDate a, QDate d, Person *g): Booking(c, a, d), m_Guest(g) {}

Single::~Single(){
    delete m_Guest;
}

//creates and returns a string equivalent of a Single object
QString Single::toString() const {
    return Booking::toString() + "\nGuest: " + m_Guest->toString();
}

//computes and returns the rate of a single booking
double Single::rate() const{
    return Booking::SINGLE_PPPN;
}

Person *Single::getGuest() const{
    return m_Guest;
}
