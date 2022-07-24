#include "calc.h"

calc::calc(QObject *parent)
    : QObject{parent}
{
    qInfo() << this << "Calc Constructed";
}

int calc::dogYears(int age)
{
    return age*7;
}

int calc::catYears(int age)
{
    return age*6;
}

calc::~calc()
{
    qInfo() << this << "Calc Deconstructed";
}
