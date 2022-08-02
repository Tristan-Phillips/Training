#ifndef CUSTVIEW_H
#define CUSTVIEW_H

#include <QWidget>
class CustomerList;
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
    CustomerList *list;

    QTextEdit *txtDisplay;
    QPushButton *btnAddCust;
    QPushButton *btnRead;
    QPushButton *btnWrite;
    QPushButton *btnExit;
};

#endif // CUSTVIEW_H
