#ifndef BOOKINGLIST_H
#define BOOKINGLIST_H

#include <QList>

#include "booking.h"

class BookingList {

  public:
    //constructor
    BookingList();
    //destructor
    ~BookingList();
    //checks whether a room is available for a given date
    int roomsAvailable(QDate d) const;
    //checks whether there is a vacancy in the given period
    bool vacancy(QDate a, QDate d) const;
    //create, add and return a booking to the list
    bool addBooking(Person *c, QDate a, QDate d, Person* g1, Person* g2 = NULL);
    void addBooking(Booking *booking);
    QString toString() const;

    Booking *at(int index) const;
    int size() const;

private:
   QList<Booking*> listBooking;
   const int NO_OF_ROOMS;
};
#endif // BOOKINGLIST_H
