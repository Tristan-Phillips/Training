#include "ui_artdb.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ui_ArtDB w;
    w.show();
    return a.exec();
}
