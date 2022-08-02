#include "customermemento.h"
#include "customer.h"
#include "customerfactory.h"

CustomerMemento::CustomerMemento()
{
}

CustomerMemento::~CustomerMemento()
{
    qDeleteAll(state);
}

void CustomerMemento::setState(QList<Customer*> inState)
{
    // Declare objects
    QString className;
    Customer *copyCustomer;
    CustomerFactory cf;

    // Make sure list is empty
    state.clear();

    // Deep copy required
    for (int count = 0; count <inState.count(); count++) {

        className = inState.at(count)->metaObject()->className();

        copyCustomer = cf.createCustomer(className,
                                         inState.at(count)->getTitle(),
                                         inState.at(count)->getName(),
                                         inState.at(count)->getAddress(),
                                         inState.at(count)->getPostCode(),
                                         inState.at(count)->getCode(),
                                         inState.at(count)->getBalance());
        // Do not append null object
        if (copyCustomer != nullptr) {
            state.append(copyCustomer);
        }
    }
}

QList<Customer*> CustomerMemento::getState()
{
    return state;
}
