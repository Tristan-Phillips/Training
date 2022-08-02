#include "customercaretaker.h"

CustomerCaretaker::CustomerCaretaker()
{
}

void CustomerCaretaker::requestMemento(CustomerMemento *memento)
{
    mementos.append(memento);
    if (mementos.count() > 5) {
        mementos.removeLast();
    }
}

CustomerMemento* CustomerCaretaker::restoreMemento()
{
    if (mementos.count() > 1) {
        isMemento = true;
    }
    else {
        isMemento = false;
    }

    if (!mementos.isEmpty()) {
        return mementos.takeFirst();
    }

    return nullptr;
}

bool CustomerCaretaker::mementoAvailable()
{
    return isMemento;
}
