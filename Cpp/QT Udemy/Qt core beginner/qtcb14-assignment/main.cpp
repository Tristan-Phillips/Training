#include <QCoreApplication>
#include <QDebug>

template<class T, class J>
void addition(T oi, J oj){
    qInfo() << "Result: " << oi + oj;;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    addition<int, int>(5,1);
    return a.exec();
}
