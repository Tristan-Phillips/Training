#include <QCoreApplication>
#include "student.h"
#include "teacher.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    student stud;
    teacher teach;

    qInfo() << "Student ";
    stud.position();
    qInfo() << "Teacher ";
    teach.position();

    return a.exec();
}
