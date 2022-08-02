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

CustView::CustView(QWidget *parent)
    : QWidget(parent),
      model(new CustomerTableModel),
      view(new QTableView)
{
    // SetupGUI
    setupGUI();
}

void CustView::addCustomer()
{
    CustInput newCust;
    QTextStream cout(stdout);

    newCust.exec();

    if (newCust.result() == QDialog::Accepted) {

        model->addCustomer(newCust.getCustomer());
        view->resizeColumnsToContents();
    }
    else {
        emit displayMessage("Dialog closed - No data available");
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

    view->resizeColumnsToContents();

    emit displayMessage("Customer XML list read from file");
}

void CustView::writeListXml(QString fileName)
{
    QString prompt("Customer list written to XML file");

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
    layout->addWidget(view);

    // Initialize widgets
    view->resizeColumnsToContents();
    view->setModel(model);

    // Set delegates
    ComboboxDelegate *cmbDel(new ComboboxDelegate(this));
    view->setItemDelegateForColumn(5, cmbDel);

    DoubleSpinBoxDelegate *spnDel(new DoubleSpinBoxDelegate(this));
    view->setItemDelegateForColumn(8, spnDel);
}
