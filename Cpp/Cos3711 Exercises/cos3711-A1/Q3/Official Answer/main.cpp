#include <QApplication>
#include "cdview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CDView cv;
    cv.show();

    return a.exec();
}
