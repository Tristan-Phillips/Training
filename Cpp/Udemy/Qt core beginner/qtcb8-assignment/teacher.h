#ifndef TEACHER_H
#define TEACHER_H

#include "person.h"

class teacher : public Person
{
public:
    teacher();

    void position() { qDebug() << "Teacher";}
};

#endif // TEACHER_H
