#ifndef CUSTINPUT_H
#define CUSTINPUT_H

#include <QDialog>
#include <QObject>
#include "customer.h"

class QPushButton;
class QLineEdit;
class QTextEdit;
class QComboBox;
class QDoubleSpinBox;

class CustInput : public QDialog
{
    Q_OBJECT
public:
    CustInput();
    ~CustInput();
    Customer getCustomer() const;

private slots:
    void processInput();

private:
    void setupGUI();
    Customer customer;

    QComboBox *cmbTitle;
    QLineEdit *edtName;
    QTextEdit *txtAddress;
    QLineEdit *edtPostCode;
    QLineEdit *edtCode;
    QDoubleSpinBox *spnBalance;

    QPushButton *btnSubmit;
    QPushButton *btnClose;
};

#endif // CUSTINPUT_H
