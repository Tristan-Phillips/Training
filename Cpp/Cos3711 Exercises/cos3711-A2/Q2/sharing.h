#ifndef SHARING_H
#define SHARING_H

#include <QObject>

#include "booking.h"
#include "person.h"

class Sharing : public Booking {
    Q_OBJECT
  private:
    //data members
    Person *m_Guest1;
    Person *m_Guest2;

  public:
    //constructor
    Sharing(Person *c, QDate a, QDate d, Person *g1, Person *g2);
    ~Sharing();
    //returns a string representation of a sharing object
    QString toString() const;
    //computes and returns the rate of a shared booking
    double rate() const;

    //Getters
    Person *get_guestOne() const;
    Person *get_guestTwo() const;
};
#endif // SHARING_H
