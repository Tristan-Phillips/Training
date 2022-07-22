#include <QApplication>

#include "gui.h"
#include "bookinglist.h"
#include "person.h"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    GUI window;
    window.show();

   return a.exec();
}
