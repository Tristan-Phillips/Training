#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person {

  private:
    //data members
    QString m_Name;
    QString m_ContactNo;
    QString m_Email;

  public:
    //constructor
    Person(QString n, QString cn, QString e = "");
    //returns a string representation of a person
    QString toString() const;

    //Getters
    QString get_name() const;
    QString get_contactNumber() const;
    QString get_email() const;

};
#endif // PERSON_H

