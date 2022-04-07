#include "widget.h"
#include "ui_widget.h"
#include "api.h"
#include <QDebug>

Address::Address(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Address::~Address()
{
    delete ui;
}

QString Address::get_address() const
{
    return mq_address;
}

void Address::set_address(QString address)
{
    //TODO VALIDATION USING REGEX
    property(mq_address) = address;
}

void Address::on_pushButton_view_clicked()
{
    API apiKey(ui->lineEdit_api->text());
    this->set_address(ui->lineEdit_address->text());
    qDebug() << "Button Pressed";
}
