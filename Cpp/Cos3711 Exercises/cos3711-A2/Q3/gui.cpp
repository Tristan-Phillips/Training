#include "gui.h"
#include "operation.h"
#include <math.h>
#include <QLCDNumber>
#include <QGridLayout>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QMessageBox>
#include <QToolTip>

GUI::GUI(QWidget *parent)
    : QWidget(parent),
      pushButton_addition{new QPushButton("+")},
      pushButton_subtraction{new QPushButton("-")},
      pushButton_multiplication{new QPushButton("*")},
      pushButton_division{new QPushButton("/")},
      pushButton_clear{new QPushButton("Clear")},
      dSpinBox_first{new QDoubleSpinBox(this)},
      dSpinBox_second{new QDoubleSpinBox(this)},
      lcdNumber_result{new QLCDNumber(this)}
{
    setObjectNames();
    setupUI();
    //Handle all signals under one slot
    //Using obj->sender to determine the signal sender
    this->connect(pushButton_addition, &QPushButton::clicked, this, &GUI::slots_handleClickEvents);
    this->connect(pushButton_subtraction, &QPushButton::clicked, this, &GUI::slots_handleClickEvents);
    this->connect(pushButton_multiplication, &QPushButton::clicked, this, &GUI::slots_handleClickEvents);
    this->connect(pushButton_division, &QPushButton::clicked, this, &GUI::slots_handleClickEvents);

    this->connect(pushButton_clear, &QPushButton::clicked, this, &GUI::resetUI);
}

void GUI::setupUI()
{
    this->setWindowTitle("Calculator");

    QGridLayout *gridLayout_main = new QGridLayout(this);

    gridLayout_main->addWidget(dSpinBox_first, 0, 0, Qt::AlignVCenter);
    gridLayout_main->addWidget(dSpinBox_second, 1, 0, Qt::AlignVCenter);
    gridLayout_main->addWidget(lcdNumber_result, 2, 0, Qt::AlignVCenter);
    gridLayout_main->addWidget(pushButton_clear, 3, 0, Qt::AlignVCenter);

    gridLayout_main->addWidget(pushButton_addition, 0, 1, Qt::AlignVCenter);
    gridLayout_main->addWidget(pushButton_subtraction, 1, 1, Qt::AlignVCenter);
    gridLayout_main->addWidget(pushButton_multiplication, 2, 1, Qt::AlignVCenter);
    gridLayout_main->addWidget(pushButton_division, 3, 1, Qt::AlignVCenter);

    //ToolTips
    pushButton_addition->setToolTip("Addition");
    pushButton_subtraction->setToolTip("Subtraction");
    pushButton_multiplication->setToolTip("Multiplication");
    pushButton_division->setToolTip("Division");
    pushButton_clear->setToolTip("Clear Result");
    dSpinBox_first->setToolTip("First value for equation");
    dSpinBox_second->setToolTip("Second value for equation");
    lcdNumber_result->setToolTip("Result");

    this->setLayout(gridLayout_main);
    this->show();
}

void GUI::resetUI()
{
    dSpinBox_first->setValue(0);
    dSpinBox_second->setValue(0);
    lcdNumber_result->display(0);
}

void GUI::setObjectNames()
{
    pushButton_addition->setObjectName("Addition");
    pushButton_subtraction->setObjectName("Subtraction");
    pushButton_multiplication->setObjectName("Multiplication");
    pushButton_division->setObjectName("Division");
}

GUI::~GUI()
{
}

void GUI::slots_handleClickEvents()
{
    char operationalCharacter = NULL;
    QString senderName = QObject::sender()->objectName();
    if(senderName == pushButton_addition->objectName()){
        operationalCharacter = '+';
    }else if(senderName == pushButton_subtraction->objectName()){
        operationalCharacter = '-';
    }else if(senderName == pushButton_multiplication->objectName()){
        operationalCharacter = '*';
    }else if(senderName == pushButton_division->objectName()){
        operationalCharacter = '/';
    }else{
        QMessageBox::critical(this, "Slot Failure", "An invalid signal has called the slots_handleClickEvents slot", QMessageBox::Ok);
    }

    Operation *tempObj;
    tempObj = m_operationFactory->createOperation(operationalCharacter);
    if(tempObj != NULL){
        double result = tempObj->compute(dSpinBox_first->value(), dSpinBox_second->value());
        if(isnan(result) ||
                (QString::number(result).size() > lcdNumber_result->digitCount())){
            lcdNumber_result->display("ERROR");
        }else{
            lcdNumber_result->display(result);
        }
    }else{
        lcdNumber_result->display(1);
    }
    delete tempObj;
}

