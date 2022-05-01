#include "custinput.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>

CustInput::CustInput()
    : m_cmbTitle(new QComboBox),
      m_edtName(new QLineEdit),
      m_txtAddress(new QTextEdit),
      m_edtPostCode(new QLineEdit),
      m_edtCode(new QLineEdit),
      m_btnSubmit(new QPushButton("Submit")),
      m_btnClose(new QPushButton("Close"))
{
    // Setup GUI
    setupGUI();

    // Connect Signals and Slots
    connect(m_btnSubmit, &QPushButton::clicked, this, &CustInput::processInput);
    connect(m_btnSubmit, &QPushButton::clicked, this, &CustInput::accept);
    connect(m_btnClose, &QPushButton::clicked, this, &CustInput::reject);
    connect(m_btnClose, &QPushButton::clicked, this, &QWidget::close);

    // Setup window
    setWindowTitle("Add customer");
}

CustInput::~CustInput()
{
}

void CustInput::processInput()
{
    customer.setTitle(m_cmbTitle->currentText());
    customer.setName(m_edtName->text());
    customer.setAddress(m_txtAddress->toPlainText().split("\n"));
    customer.setPostCode(m_edtPostCode->text());
    customer.setCode(m_edtCode->text());

    m_txtAddress->append(customer.toString());
}

Customer CustInput::getCustomer() const
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

    // Setup layout
    layout->addWidget(lblTitle);
    layout->addWidget(m_cmbTitle);
    layout->addWidget(lblName);
    layout->addWidget(m_edtName);
    layout->addWidget(lblAddress);
    layout->addWidget(m_txtAddress);
    layout->addWidget(lblPostCode);
    layout->addWidget(m_edtPostCode);
    layout->addWidget(lblCode);
    layout->addWidget(m_edtCode);
    layout->addSpacing(10);
    layout->addWidget(m_btnSubmit);
    layout->addWidget(m_btnClose);

    // Initialize widgets
    QStringList list = QStringList() << "Mr" << "Mrs" << "Ms" << "Dr" << "Hon" << "Rev";
    m_cmbTitle->addItems(list);
}
