#ifndef BOOKING_H
#define BOOKING_H

#include <QDate>
#include <QObject>

#include "person.h"

class Booking : public QObject{
    Q_OBJECT
  private:
    //data members
    Person *m_Contact;
    QDate m_ArrivalDate;
    QDate m_DepartureDate;
  protected:
    //const data members
    const double SINGLE_PPPN;
    const double SHARING_PPPN;

  public:
   //constructor
    Booking(Person *c, QDate a, QDate d);
    //destructor
    virtual ~Booking();
    //checks whether a give date is between the arrival date and departure date
    bool booked(QDate d) const;
    //returns a string representation of a booking
    virtual QString toString() const;
    //abstract function
    virtual double rate() const = 0;

    //Getters
    Person *get_person() const;
    QDate get_arrivalDate() const;
    QDate get_departure() const;

};
#endif // BOOKING_H
