#include "widget.h"
#include "ui_widget.h"
#include <QTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

int Widget::generateOneOrZero()
{
#include<stdlib.h>
#include<time.h>
    int min=0, max=1;
    srand(time(NULL));
    int result = rand()%(max+1-min)+min;
    return result;
}

void Widget::updateClickCount()
{
    int currentCount = this->ui->lcdNumber_totalClicks->intValue();
    currentCount = currentCount + 1;
    this->ui->lcdNumber_totalClicks->display(currentCount);
}

void Widget::setupTextEdit(int headOrTail)
{
    this->ui->textEdit_image->clear();
    //Add blink effect
    QTime blinkTime = QTime::currentTime().addMSecs(200); //Magic Number
    while(QTime::currentTime() < blinkTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    //Fancy Text Setup
    this->ui->textEdit_image->setFont(QFont("Black body", 74));
    //this->ui->textEdit_image->setAlignment(Qt::AlignCenter);

    //0 = head ; 1 = tails
    if(headOrTail == 0){
        this->ui->textEdit_image->setText("HEADS");
    }else{
        this->ui->textEdit_image->setText("TAILS");
    }
}

void Widget::on_pushButton_clickToFlip_clicked()
{
    updateClickCount();
    //0 = Heads ; 1 = Tails
    int generatedInt = generateOneOrZero();
    setupTextEdit(generatedInt);
}

