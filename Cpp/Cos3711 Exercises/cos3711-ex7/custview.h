#ifndef CUSTVIEW_H
#define CUSTVIEW_H

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

signals:
    void displayMessage(QString);

public slots:
    void readListXml(QString fileName = "customers.xml");
    void writeListXml(QString fileName = "customers.xml");
    void addCustomer();
    void clearModel();

private:
    void setupGUI();
    CustomerTableModel *model;
    QTableView *view;
};

#endif // CUSTVIEW_H
