#include "source.h"
#include <QDebug>

source::source(QObject *parent)
    : QObject{parent}
{

}

void source::sayHello()
{
    qInfo() << "Hello, World!";
}

void source::doTest()
{
    emit signal_conversion();
}
