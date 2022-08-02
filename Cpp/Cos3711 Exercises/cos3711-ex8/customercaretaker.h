#ifndef CUSTOMERCARETAKER_H
#define CUSTOMERCARETAKER_H

#include "customermemento.h"

class CustomerCaretaker
{
public:
    CustomerCaretaker();

    void requestMemento(CustomerMemento *memento);
    CustomerMemento* restoreMemento();
    bool mementoAvailable();

private:
    QList<CustomerMemento*> mementos;
    bool isMemento;
};

#endif // CUSTOMERCARETAKER_H
