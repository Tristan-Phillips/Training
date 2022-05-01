#ifndef CUSTINPUT_H
#define CUSTINPUT_H

#include <QDialog>
#include <QObject>
#include "customer.h"

class QPushButton;
class QLineEdit;
class QTextEdit;
class QComboBox;

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

    QComboBox *m_cmbTitle;
    QLineEdit *m_edtName;
    QTextEdit *m_txtAddress;
    QLineEdit *m_edtPostCode;
    QLineEdit *m_edtCode;

    QPushButton *m_btnSubmit;
    QPushButton *m_btnClose;
};

#endif // CUSTINPUT_H
