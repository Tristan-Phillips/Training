#include "custview.h"
#include "custinput.h"
#include "listxmlwriter.h"
#include "listxmlreader.h"
#include "customertablemodel.h"
#include "comboboxdelegate.h"
#include "doublespinboxdelegate.h"
#include <QTableView>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QThread>
#include <QProcess>
#include <QDate>
#include <QMap>

#include "customermemento.h"

CustView::CustView(QWidget *parent)
    : QWidget(parent),
      model(CustomerTableModel::getInstance()),
      tview(new QTableView)
{
    // SetupGUI
    setupGUI();
}

CustView::~CustView()
{
    delete model;
    delete tview;
}

CustomerMemento* CustView::createMemento()
{
    // Get model state, and set state to memento
    CustomerMemento *memento = new CustomerMemento;
    memento->setState(model->getList());

    return memento;
}

void CustView::setMemento(CustomerMemento* memento)
{
    // Get state from memento, and set model state
    // Check for null pointer
    if (memento != 0) {
        model->setList(memento->getState());
    }
}

void CustView::addCustomer()
{
    CustInput newCust;
    QTextStream cout(stdout);

    newCust.exec();

    if (newCust.result() == QDialog::Accepted) {

        model->addCustomer(newCust.getCustomer());
        tview->resizeColumnsToContents();
    }
    else {
        emit displayMessage("Dialog closed - No data available");
    }
}

void CustView::deleteCustomer()
{
    if (tview->selectionModel()->hasSelection()) {

        int response;
        response = QMessageBox::warning(this, "Delete Customer",
                                     "Are you sure you want to delete Customer ?",
                                     QMessageBox::Yes | QMessageBox::Cancel);
        if (response == QMessageBox::Yes) {

            // Delete customer
            int row = tview->currentIndex().row();
            model->removeRow(row);

            emit displayMessage("Customer deleted");
        }
    }
}

void CustView::clearModel()
{
    int response;
    response = QMessageBox::question(this, "Clear model",
                                     "Are you sure you want to clear the model ?",
                                     QMessageBox::Yes | QMessageBox::Cancel);
    if (response == QMessageBox::Yes) {
        model->clear();
        emit displayMessage("All data cleared from model");
    }
}

void CustView::readListXml(QString fileName)
{
    // Create list to hold customer objects
    QList<Customer*> list;
    ListXmlReader lxr;
    list = lxr.read(fileName);

    // Clear model before adding customers
    model->clear();

    foreach (Customer* cust, list) {
        model->addCustomer(cust);
    }

    tview->resizeColumnsToContents();

    emit displayMessage("Customer XML list read from file");
}

void CustView::writeListXml(QString fileName)
{
    QString prompt("Customer list written to XML file");

    // Declare ListXmlWriter
    ListXmlWriter lxw(model);
    if (!lxw.write(fileName)) {
       prompt = "Error: Customer list not written to XML file";
    }

    emit displayMessage(prompt);
}

void CustView::setupGUI()
{
    // Setup layout
    QVBoxLayout *layout(new QVBoxLayout(this));
    layout->addWidget(tview);

    // Initialize widgets
    tview->resizeColumnsToContents();
    tview->setModel(model);
    tview->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Set delegates
    ComboboxDelegate *cmbDel(new ComboboxDelegate(this));
    tview->setItemDelegateForColumn(5, cmbDel);

    DoubleSpinBoxDelegate *spnDel(new DoubleSpinBoxDelegate(this));
    tview->setItemDelegateForColumn(8, spnDel);
}
