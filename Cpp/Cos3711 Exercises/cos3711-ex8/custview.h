#ifndef CUSTVIEW_H
#define CUSTVIEW_H

#include "customermemento.h"

#include <QWidget>
class CustomerList;
class QPushButton;
class QTableView;
class CustomerTableModel;

class CustView : public QWidget
{
    Q_OBJECT
public:
    explicit CustView(QWidget *parent = nullptr);
    ~CustView();
    CustomerMemento* createMemento();
    void setMemento(CustomerMemento* memento);

signals:
    void displayMessage(QString);

public slots:
    void readListXml(QString fileName = "customers.xml");
    void writeListXml(QString fileName = "customers.xml");
    void addCustomer();
    void deleteCustomer();
    void clearModel();

private:
    void setupGUI();
    CustomerTableModel *model;
public:
    QTableView *tview;
};

#endif // CUSTVIEW_H
