#include "custinput.h"
#include "customer.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QLabel>

CustInput::CustInput()
    : customer(new Customer),
      cmbTitle(new QComboBox),
      edtName(new QLineEdit),
      txtAddress(new QTextEdit),
      edtPostCode(new QLineEdit),
      edtCode(new QLineEdit),
      spnBalance(new QDoubleSpinBox),
      btnSubmit(new QPushButton("Submit")),
      btnClose(new QPushButton("Close"))
{
    // Setup GUI
    setupGUI();

    // Connect Signals and Slots
    connect(btnSubmit, &QPushButton::clicked, this, &CustInput::processInput);
    connect(btnSubmit, &QPushButton::clicked, this, &CustInput::accept);
    connect(btnClose, &QPushButton::clicked, this, &CustInput::reject);
    connect(btnClose, &QPushButton::clicked, this, &QWidget::close);

    // Setup window
    setWindowTitle("Add customer");
}

CustInput::~CustInput()
{
}

void CustInput::processInput()
{
    customer->setTitle(cmbTitle->currentText());
    customer->setName(edtName->text());
    customer->setAddress(txtAddress->toPlainText().split("\n"));
    customer->setPostCode(edtPostCode->text());
    customer->setCode(edtCode->text());
    customer->setBalance(spnBalance->value());

    txtAddress->append(customer->toString());
}

Customer* CustInput::getCustomer() const
{
    return customer;
}

void CustInput::setupGUI()
{
    // Declare widgets
    QVBoxLayout *layout(new QVBoxLayout(this));
    QLabel *lblTitle(new QLabel("Title"));
    QLabel *lblName(new QLabel("Name"));
    QLabel *lblAddress(new QLabel("Address"));
    QLabel *lblPostCode(new QLabel("Postcode"));
    QLabel *lblCode(new QLabel("Customer code"));
    QLabel *lblBalance(new QLabel("Balance"));

    // Setup layout
    layout->addWidget(lblTitle);
    layout->addWidget(cmbTitle);
    layout->addWidget(lblName);
    layout->addWidget(edtName);
    layout->addWidget(lblAddress);
    layout->addWidget(txtAddress);
    layout->addWidget(lblPostCode);
    layout->addWidget(edtPostCode);
    layout->addWidget(lblCode);
    layout->addWidget(edtCode);
    layout->addWidget(lblBalance);
    layout->addWidget(spnBalance);
    layout->addSpacing(10);
    layout->addWidget(btnSubmit);
    layout->addWidget(btnClose);

    // Initialize widgets
    QStringList list = QStringList() << "Mr" << "Mrs" << "Ms" << "Dr" << "Hon" << "Rev";
    cmbTitle->addItems(list);

    spnBalance->setMaximum(9999.99);
    spnBalance->setMinimum(0.00);
    spnBalance->setDecimals(2);
    spnBalance->setAlignment(Qt::AlignRight);
    spnBalance->setButtonSymbols(QAbstractSpinBox::NoButtons);
}
