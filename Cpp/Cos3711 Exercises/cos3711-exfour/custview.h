#ifndef CUSTVIEW_H
#define CUSTVIEW_H

#include <QWidget>
#include "customerlistI.h"
class QPushButton;
class QTextEdit;

class CustView : public QWidget
{
    Q_OBJECT
public:
    explicit CustView(QWidget *parent = nullptr);
    void closeEvent(QCloseEvent *event);

private slots:
    void addCustomer();
    void readList();
    void writeList();

private:
    void setupGUI();
    CustomerList list;

    QTextEdit *m_txtDisplay;
    QPushButton *m_btnAddCust;
    QPushButton *m_btnRead;
    QPushButton *m_btnWrite;
    QPushButton *m_btnExit;
};

#endif // CUSTVIEW_H
