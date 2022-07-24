#include <QCoreApplication>
#include <QDebug>
#include <iostream>

int age(){
    int input = 0;
    qInfo() << "Enter your age: ";
    std::cin >> input;
    return input;
}

void age(int &input){
    qInfo() << "In ten years you will be: " << input+10;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int i = age();
    age(i);

    return a.exec();
}
