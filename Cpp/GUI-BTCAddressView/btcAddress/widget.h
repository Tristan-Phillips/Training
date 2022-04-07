#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>

namespace Ui {
class Widget;
}

class Address : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString mq_address READ get_address WRITE set_address)
    Q_PROPERTY(int mq_balance READ get_balance WRITE set_balance)

public:
    explicit Address(QWidget *parent = 0);
    ~Address();

    //Getter
    QString get_address() const;
    int get_balance() const;
    //Setter
    void set_address(QString address);
    void set_balance(int balance);

private slots:
    void on_pushButton_view_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
