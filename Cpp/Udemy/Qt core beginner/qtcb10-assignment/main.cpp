#include <QCoreApplication>
#include <iostream>
#include "calc.h"

int calculateDogYears(int age, calc* obj){
    return obj->dogYears(age);
}

int calculateCatYears(int age, calc* obj){
    return obj->catYears(age);
}

void input(){
    int age = 0;
    qInfo() << "Enter your age: ";
    std::cin >> age;

    calc* obj = new calc(nullptr);
    qInfo() << "Age in dog years: " << calculateDogYears(age, obj);
    qInfo() << "Age in cat years: " << calculateCatYears(age, obj);

    delete obj;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    input();

    return a.exec();
}
