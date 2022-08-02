#include "custview.h"
#include "custinput.h"
#include "listwriter.h"
#include "listreader.h"
#include "customerlistC.h"
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QCloseEvent>
#include <QMessageBox>
#include <QTextStream>

CustView::CustView(QWidget *parent)
    : QWidget(parent),
      list(new CustomerList),
      txtDisplay(new QTextEdit),
      btnAddCust(new QPushButton("Add customer")),
      btnRead(new QPushButton("Read")),
      btnWrite(new QPushButton("Write")),
      btnExit(new QPushButton("Exit"))
{
    // SetupGUI
    setupGUI();

    // Connect Signals and Slots
    connect(btnAddCust, SIGNAL(clicked()), this, SLOT(addCustomer()));
    connect(btnRead, &QPushButton::clicked, this, &CustView::readList);
    connect(btnWrite, &QPushButton::clicked, this, &CustView::writeList);
    connect(btnExit, SIGNAL(clicked()), this, SLOT(close()));

    // Set up window
    setWindowTitle("Customers");
}

void CustView::addCustomer()
{
    CustInput newCust;
    QTextStream cout(stdout);

    newCust.exec();

    if (newCust.result() == QDialog::Accepted) {

        list->append(newCust.getCustomer());
        txtDisplay->append(newCust.getCustomer()->toString());
        cout << list->toString() << Qt::endl;
    }
    else {
        cout << "Dialog closed - No data available" << Qt::flush;
    }
}

void CustView::readList()
{
    // Clear list before reading from file
    list->clear();
    ListReader lr;
    list = lr.read();

    txtDisplay->clear();
    txtDisplay->append(list->toString());

    QTextStream cout(stdout);
    cout << "Customer list read from file" << Qt::endl;
}

void CustView::writeList()
{
    QString prompt("Customer list written to file");

    ListWriter lw(list);
    if (!lw.write()) {
        prompt = "Error: Customer list not written to file";
    }

    QTextStream cout(stdout);
    cout << prompt << Qt::endl;
}

void CustView::closeEvent(QCloseEvent *event)
{
    int response;
    response = QMessageBox::warning(this, "Exit", "Are you sure you want to Exit ?",
                                    QMessageBox::Yes | QMessageBox::No);
    if (response == QMessageBox::Yes) {
        event->accept();
    }
    else {
        event->ignore();
    }
}

void CustView::setupGUI()
{
    // Setup layout
    QVBoxLayout *layout(new QVBoxLayout(this));
    layout->addWidget(txtDisplay);
    layout->addWidget(btnAddCust);
    layout->addWidget(btnRead);
    layout->addWidget(btnWrite);
    layout->addWidget(btnExit);

    // Initialize widgets
    txtDisplay->setReadOnly(true);
}
