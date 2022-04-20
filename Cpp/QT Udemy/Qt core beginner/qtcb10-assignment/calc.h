#ifndef CALC_H
#define CALC_H

#include <QObject>
#include <QDebug>

class calc : public QObject
{
    Q_OBJECT
public:
    explicit calc(QObject *parent = nullptr);
    int dogYears(int age);
    int catYears(int age);
    ~calc();

signals:

};

#endif // CALC_H
