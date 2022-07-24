#include <QCoreApplication>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Test obj;
    QObject::connect(&obj,&Test::closeSingnal,&a,&QCoreApplication::quit, Qt::QueuedConnection);

    obj.closeSlot();
    return a.exec();
}
