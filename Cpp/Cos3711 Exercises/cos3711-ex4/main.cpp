#include <QApplication>
#include "custview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CustView view;
    view.show();

    return a.exec();
}
