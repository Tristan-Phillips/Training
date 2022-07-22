#include "bookinglist.h"
#include "sharing.h"
#include "single.h"

//no-arg constructor
BookingList::BookingList():NO_OF_ROOMS(5){}

//destructor
BookingList::~BookingList(){
    qDeleteAll(listBooking);
    listBooking.clear();
}

//checks and returns the number of rooms of available for a given date
int BookingList::roomsAvailable(QDate d) const {
    int result = NO_OF_ROOMS;
    foreach (Booking * b, listBooking) {
        if (b->booked(d)) {
            result--;
        }
    }
    return result;
}

//checks and returns whether there is room available in a given period
bool BookingList::vacancy(QDate a, QDate d) const {
    if (a.isValid() && d.isValid() && a < d) {
        for (QDate i = a; i < d; i = i.addDays(1)) {
            if (roomsAvailable(i) <= 0) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

//creates a booking instance if there is vacancy
bool BookingList::addBooking(Person *c, QDate a, QDate d, Person* g1, Person*g2) {
    Booking* b = NULL;
    if(vacancy(a,d) == true){
        if (g2 == NULL) {
            b = new Single(c, a, d, g1);
        } else {
            b = new Sharing(c, a, d, g1, g2);
        }
        listBooking.append(b);
        return true;
    }
    return false;
}

void BookingList::addBooking(Booking *booking){
    listBooking.append(booking);
}

//returns a string representation of the entire booking list
QString BookingList::toString() const{
    QString result;
    foreach (Booking * b, listBooking) {
        result.append(b->toString());
        result.append("\n-------------------------------\n");
    }
    return result;
}

Booking* BookingList::at(int index) const{
    return listBooking.at(index);
}

int BookingList::size() const{
    return listBooking.size();
}
