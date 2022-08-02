#ifndef CUSTINPUT_H
#define CUSTINPUT_H

#include "addressvalidator.h"
#include <QDialog>
#include <QObject>

class QPushButton;
class QLineEdit;
class QTextEdit;
class QComboBox;
class QDoubleSpinBox;
class Customer;

class CustInput : public QDialog
{
    Q_OBJECT
public:
    CustInput();
    ~CustInput();
    Customer* getCustomer() const;

private slots:
    void processInput();
    void checkInputs();

private:
    void setupGUI();
    Customer *customer;

    QComboBox *cmbType;
    QComboBox *cmbTitle;
    QLineEdit *edtName;
    QTextEdit *txtAddress;
    QLineEdit *edtPostCode;
    QLineEdit *edtCode;
    QDoubleSpinBox *spnBalance;
    AddressValidator *valAddress;

    QPushButton *btnSubmit;
    QPushButton *btnClose;
};

#endif // CUSTINPUT_H
