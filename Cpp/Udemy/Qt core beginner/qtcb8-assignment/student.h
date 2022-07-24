#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

class student : public Person
{
public:
    student();

    void position() { qDebug() << "Student";}
};

#endif // STUDENT_H
