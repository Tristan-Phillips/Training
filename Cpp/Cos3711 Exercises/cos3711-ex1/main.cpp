#include <QApplication>
#include "hello.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Hello hi;
    hi.show();

    return a.exec();
}
