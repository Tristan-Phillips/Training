#include <QApplication>
#include <QTextStream>

#include "custinput.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextStream cout(stdout);

    CustInput cust;
    cust.exec();

    if (cust.result() == QDialog::Accepted) {

        cout << cust.getCustomer().toString() << Qt::endl;
    }
    else {
        cout << "Dialog closed" << Qt::endl;
    }

    return a.exec();
}
