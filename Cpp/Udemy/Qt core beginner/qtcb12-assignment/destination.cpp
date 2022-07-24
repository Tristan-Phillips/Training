#include "destination.h"
#include "source.h"

destination::destination(QObject *parent)
    : QObject{parent}
{

}

void destination::slot_convert()
{
    source* sobj = dynamic_cast<source*>(sender());
    if(sobj) {
        sobj->sayHello();
    }
}
