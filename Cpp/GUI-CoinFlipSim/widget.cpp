#include "widget.h"
#include "ui_widget.h"

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

void Widget::updateImage(int headOrTailResult)
{
    QGraphicsScene *sceneCoin = new QGraphicsScene;
    QString workingPath = QApplication::applicationDirPath();

    if(headOrTailResult == 0){
        workingPath = workingPath.append("/head.jpg");
    }else{
        workingPath = workingPath.append("/tail.jpg");
    }
    QPixmap pixmap(workingPath);
    sceneCoin->addPixmap(pixmap);
    this->ui->graphicsView_coin->setScene(sceneCoin);
    this->ui->graphicsView_coin->show();
}


void Widget::on_pushButton_clickToFlip_clicked()
{
    updateClickCount();
    //0 = Heads ; 1 = Tails
    int generatedInt = generateOneOrZero();
    if(generatedInt == 0){
        this->ui->label_lastResult->setText("Last Result: Heads");
    }else{
        this->ui->label_lastResult->setText("Last Result: Tails");
    }
    updateImage(generatedInt);
}

