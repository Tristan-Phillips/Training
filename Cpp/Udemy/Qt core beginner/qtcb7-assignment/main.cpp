#include <QCoreApplication>
#include <QDebug>
#include <iostream>

void getUserInput(int &x){
    qInfo() << "Enter a maximum: ";
    std::cin >> x;
}

int printToScreen(int &x){
    if(x > 0){
        qInfo() << "Hello, World!";
        x--;
        return printToScreen(x);
    }else{
        return 0;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int x = 0;
    getUserInput(x);
    printToScreen(x);
    return a.exec();
}
