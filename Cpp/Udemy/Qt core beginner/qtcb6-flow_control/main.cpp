#include <QCoreApplication>
#include <QDebug>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int max = 0, i = 1;
    qInfo() << "Enter a maximum number: ";
    std::cin >> max;

    if(max <= 0){
        qFatal("Garbage");
    }

    while (i <= max){
        qInfo() << i << " Hello, World!";
        i++;
    }

    return a.exec();
}
