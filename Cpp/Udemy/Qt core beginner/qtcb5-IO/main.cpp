#include <QCoreApplication>
#include <iostream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Integer: ";
    int value;
    std::cin >> value;
    std::cout << value;

    //Difference, cerr used when output isnt expected
    std::cerr << "C-Error!" << std::endl;

    qInfo() << "Q-Info";
    qDebug() << "Not something the user should see";
    qCritical() << "Something bad has happened";
    qFatal("Will crash program");

    return a.exec();
}
