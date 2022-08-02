#include "custview.h"
#include "custinput.h"
#include "listwriter.h"
#include "listreader.h"

#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QCloseEvent>
#include <QMessageBox>
#include <QTextStream>

CustView::CustView(QWidget *parent)
    : QWidget(parent),
      m_txtDisplay(new QTextEdit),
      m_btnAddCust(new QPushButton("Add customer")),
      m_btnRead(new QPushButton("Read")),
      m_btnWrite(new QPushButton("Write")),
      m_btnExit(new QPushButton("Exit"))
{
    // SetupGUI
    setupGUI();

    // Connect Signals and Slots
    connect(m_btnAddCust, SIGNAL(clicked()), this, SLOT(addCustomer()));
    connect(m_btnRead, &QPushButton::clicked, this, &CustView::readList);
    connect(m_btnWrite, &QPushButton::clicked, this, &CustView::writeList);
    connect(m_btnExit, SIGNAL(clicked()), this, SLOT(close()));

    // Set up window
    setWindowTitle("Customers");
}

void CustView::addCustomer()
{
    CustInput newCust;
    QTextStream cout(stdout);

    newCust.exec();

    if (newCust.result() == QDialog::Accepted) {

        list.append(newCust.getCustomer());
        m_txtDisplay->append(newCust.getCustomer().toString());
        cout << list.toString() << Qt::endl;
    }
}

void CustView::readList()
{
    // Clear list before reading from file
    list.clear();
    ListReader lr;
    list = lr.read();

    m_txtDisplay->clear();
    m_txtDisplay->append(list.toString());

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
    layout->addWidget(m_txtDisplay);
    layout->addWidget(m_btnAddCust);
    layout->addWidget(m_btnRead);
    layout->addWidget(m_btnWrite);
    layout->addWidget(m_btnExit);

    // Initialize widgets
    m_txtDisplay->setReadOnly(true);
}
