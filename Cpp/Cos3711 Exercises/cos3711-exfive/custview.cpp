#include "custview.h"
#include "custinput.h"
#include "listwriter.h"
#include "listreader.h"
#include "customertablemodel.h"
#include "comboboxdelegate.h"
#include "doublespinboxdelegate.h"
#include <QTableView>
#include <QPushButton>
#include <QVBoxLayout>
#include <QCloseEvent>
#include <QMessageBox>
#include <QTextStream>
//#include <QList>

CustView::CustView(QWidget *parent)
    : QWidget(parent),
      model(new CustomerTableModel),
      view(new QTableView),
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
    setMinimumSize(700, 400);
}

void CustView::addCustomer()
{
    CustInput newCust;
    QTextStream cout(stdout);

    newCust.exec();

    if (newCust.result() == QDialog::Accepted) {

        model->addCustomer(newCust.getCustomer());
    }
    else {
        cout << "Dialog closed - No data available" << Qt::endl;
    }
}

void CustView::readList()
{
    // Create list to hold customer objects
    QList<Customer*> list;
    ListReader lr;
    list = lr.read();

    // Clear model before adding customers
    model->clear();

    foreach (Customer* cust, list) {
        model->addCustomer(cust);
    }

    view->resizeColumnsToContents();

    QTextStream cout(stdout);
    cout << "Customer list read from file" << Qt::endl;
}

void CustView::writeList()
{
    QString prompt("Customer list written to file");

    ListWriter lw(model);
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
    layout->addWidget(view);
    layout->addWidget(btnAddCust);
    layout->addWidget(btnRead);
    layout->addWidget(btnWrite);
    layout->addWidget(btnExit);

    // Initialize widgets
    view->resizeColumnsToContents();
    view->setModel(model);

    // Set delegates
    ComboboxDelegate *cmbDel(new ComboboxDelegate(this));
    view->setItemDelegateForColumn(5, cmbDel);

    DoubleSpinBoxDelegate *spnDel(new DoubleSpinBoxDelegate(this));
    view->setItemDelegateForColumn(8, spnDel);
}
