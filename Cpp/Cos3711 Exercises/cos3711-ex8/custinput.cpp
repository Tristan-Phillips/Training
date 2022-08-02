#include "custinput.h"
#include "customer.h"
#include "customerfactory.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

#include <QDebug>

CustInput::CustInput()
    : cmbType(new QComboBox),
      cmbTitle(new QComboBox),
      edtName(new QLineEdit),
      txtAddress(new QTextEdit),
      edtPostCode(new QLineEdit),
      edtCode(new QLineEdit),
      spnBalance(new QDoubleSpinBox),
      valAddress(new AddressValidator(txtAddress, this)),
      btnSubmit(new QPushButton("Submit")),
      btnClose(new QPushButton("Close"))
{
    // Setup GUI
    setupGUI();

    // Set regular expressions
    valAddress->setRegex2("^([a-zA-Z]+\\s?)+$");
    valAddress->setRegex3("^([a-zA-Z]+\\s?)+$");

    // Connect Signals and Slots
    connect(edtName, &QLineEdit::textChanged, this, &CustInput::checkInputs);
    connect(edtPostCode, &QLineEdit::textChanged, this, &CustInput::checkInputs);
    connect(edtCode, &QLineEdit::textChanged, this, &CustInput::checkInputs);
    connect(txtAddress, &QTextEdit::textChanged, valAddress, &AddressValidator::validate);
    connect(valAddress, &AddressValidator::addressValidated, this, &CustInput::checkInputs);
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
    CustomerFactory cf;
    customer = cf.createCustomer(cmbType->currentData().toString(),
                                 cmbTitle->currentText(),
                                 edtName->text(),
                                 txtAddress->toPlainText().split("\n"),
                                 edtPostCode->text(),
                                 edtCode->text(),
                                 spnBalance->value());
}

void CustInput::checkInputs()
{
    if (edtName->hasAcceptableInput() &&
        edtPostCode->hasAcceptableInput() &&
        edtCode->hasAcceptableInput() &&
        valAddress->hasAcceptableInput()) {

        btnSubmit->setEnabled(true);
    }
    else {
        btnSubmit->setEnabled(false);
    }
/*
    qDebug() << "Name: " << QString(edtName->hasAcceptableInput() ? "Valid" : "Invalid")  << Qt::endl;
    qDebug() << "Address: " << QString(valAddress->hasAcceptableInput() ? "Valid" : "Invalid")  << Qt::endl;
    qDebug() << "Post code: " << QString(edtPostCode->hasAcceptableInput() ? "Valid" : "Invalid")  << Qt::endl;
    qDebug() << "Code: " << QString(edtCode->hasAcceptableInput() ? "Valid" : "Invalid")  << Qt::endl;
*/
}

Customer* CustInput::getCustomer() const
{
    return customer;
}

void CustInput::setupGUI()
{
    // Declare widgets
    QVBoxLayout *layout(new QVBoxLayout(this));
    QLabel *lblType(new QLabel("Customer type"));
    QLabel *lblTitle(new QLabel("Title"));
    QLabel *lblName(new QLabel("Name"));
    QLabel *lblAddress(new QLabel("Address"));
    QLabel *lblPostCode(new QLabel("Postcode"));
    QLabel *lblCode(new QLabel("Customer code"));
    QLabel *lblBalance(new QLabel("Balance"));

    // Setup layout
    layout->addWidget(lblType);
    layout->addWidget(cmbType);
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

    cmbType->addItem("Cash customer", "CashCustomer");
    cmbType->addItem("Account customer", "AccountCustomer");
    cmbType->addItem("Corporate customer", "CorpCustomer");

    spnBalance->setMaximum(9999.99);
    spnBalance->setMinimum(0.00);
    spnBalance->setDecimals(2);
    spnBalance->setAlignment(Qt::AlignRight);
    spnBalance->setButtonSymbols(QAbstractSpinBox::NoButtons);

    // Validation
    // Name
    QRegularExpression name("[a-zA-Z]+\\s?[a-zA-Z]{2,}");
    QRegularExpressionValidator *nameValid(new QRegularExpressionValidator(name));
    edtName->setValidator(nameValid);
    edtName->setMaxLength(25);

    // Post code
    QRegularExpression pc("[1-9][0-9]{3}");
    QRegularExpressionValidator *pcValid(new QRegularExpressionValidator(pc));
    edtPostCode->setValidator(pcValid);

    // Customer code
    QRegularExpression code("[A-Z]{2}20\\d{2}(EC|WC|KZN|GAU)[a-j](0[1-9]|10)");
    QRegularExpressionValidator *codeValid(new QRegularExpressionValidator(code));
    edtCode->setValidator(codeValid);

    // Set placeholders and tooltips
    cmbTitle->setToolTip("Select title from list");

    edtName->setPlaceholderText("First name and surname");
    edtName->setToolTip("Enter first name and surname.");

    txtAddress->setPlaceholderText("Street address\nSuburb\nTown / City\nProvince");
    txtAddress->setToolTip("All four lines are required.");

    edtPostCode->setPlaceholderText("dddd");
    edtPostCode->setToolTip("Enter 4 digit post code.");

    edtCode->setPlaceholderText("Customer code");
    edtCode->setToolTip("Enter customer code.");

    spnBalance->setToolTip("Minimum: 0.00, maximum: 9999.99");

    btnSubmit->setEnabled(false);
}
