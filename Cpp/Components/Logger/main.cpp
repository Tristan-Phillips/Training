#include <QCoreApplication>
#include <QDebug>
#include "logger.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "File: " << Logger::m_filename;
    Logger::attach();

    qInfo() << "test!";

    Logger::m_logging = false;
    qInfo() << "Dont Log This!";

    Logger::m_logging = true;

    qInfo() << "Finished";
    return a.exec();
}
