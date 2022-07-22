#ifndef SINGLE_H
#define SINGLE_H

#include <QObject>

#include "booking.h"
#include "person.h"

class Single : public Booking {
    Q_OBJECT
  private:
    //data member
    Person *m_Guest;

  public:
    //constructor
    Single(Person *c, QDate a, QDate d, Person *g);
    ~Single();
    //returns a string representation of a Single object
    QString toString() const;
    //computes and returns the rate of a Single booking
    double rate() const;

    //Getter
    Person *getGuest() const;
};
#endif // SINGLE_H
