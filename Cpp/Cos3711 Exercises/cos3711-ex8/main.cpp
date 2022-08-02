#include <QApplication>
#include "customerclient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CustomerClient main;
    main.show();

    return a.exec();
}
