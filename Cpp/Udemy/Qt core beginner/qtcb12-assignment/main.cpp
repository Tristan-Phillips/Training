#include <QCoreApplication>
#include "destination.h"
#include "source.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    source obj;
    destination dobj;

    QObject::connect(&obj,&source::signal_conversion,&dobj,&destination::slot_convert);

    obj.doTest();

    return a.exec();
}
