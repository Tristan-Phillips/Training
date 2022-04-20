#include "test.h"
#include <QDebug>

Test::Test(QObject *parent)
    : QObject{parent}
{

}

void Test::closeSlot()
{
    qInfo() << "Quitting";
    emit closeSingnal();
}
