#include "calculator.h"
#include "ui_calculator.h"

//Global Variables
double calcValue = 0.0;
bool divisionTriggered = false;
bool multiplicationTriggered = false;
bool additionTriggered = false;
bool subtractionTriggered = false;

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    ui->lineEdit_display->setText(QString::number(calcValue));
    QPushButton *numButtons[10];

    for(int i = 0; i < 10; ++i){
        QString butName = "pushButton_" + QString::number(i);
        //Seach for specific widget by name
        numButtons[i] = Calculator::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()), this, SLOT(slot_numberPressed()));
    }

    connect(ui->pushButton_addition, SIGNAL(released()), this, SLOT(slot_mathButtonPressed()));
    connect(ui->pushButton_subtraction, SIGNAL(released()), this, SLOT(slot_mathButtonPressed()));
    connect(ui->pushButton_multiplication, SIGNAL(released()), this, SLOT(slot_mathButtonPressed()));
    connect(ui->pushButton_subtraction, SIGNAL(released()), this, SLOT(slot_mathButtonPressed()));

    connect(ui->pushButton_equals, SIGNAL(released()), this, SLOT(slot_equalButtonPressed()));
    connect(ui->pushButton_sign, SIGNAL(released()), this, SLOT(slot_changeSignPressed()));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::slot_numberPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    QString displayVal = ui->lineEdit_display->text();

    if((displayVal.toDouble() == 0) || (displayVal.toDouble() == 0.0)){
        ui->lineEdit_display->setText(butVal);
    }else{
        QString newVal = displayVal + butVal;
        double dblNewVal = newVal.toDouble();
        ui->lineEdit_display->setText(QString::number(dblNewVal, 'g', 16));
    }
}

void Calculator::slot_mathButtonPressed()
{
    divisionTriggered = false;
    multiplicationTriggered = false;
    additionTriggered = false;
    subtractionTriggered = false;

    QString displayValue = ui->lineEdit_display->text();
    calcValue = displayValue.toDouble();
    QPushButton *buttonSender = (QPushButton *)sender();
    QString butVal = buttonSender->text();

    if(QString::compare(butVal, "/", Qt::CaseInsensitive) == 0){
        divisionTriggered = true;
    }else if(QString::compare(butVal, "*", Qt::CaseInsensitive) == 0){
        multiplicationTriggered = true;
    }else if(QString::compare(butVal, "+", Qt::CaseInsensitive) == 0){
        additionTriggered = true;
    }else if(QString::compare(butVal, "-", Qt::CaseInsensitive) == 0){
        subtractionTriggered = true;
    }

    ui->lineEdit_display->setText("");
}

void Calculator::slot_equalButtonPressed()
{
    double solution = 0.0;
    QString displayVal = ui->lineEdit_display->text();
    double dblDisplayVal = displayVal.toDouble();
    if(additionTriggered || subtractionTriggered || multiplicationTriggered || divisionTriggered){
        if(additionTriggered){
            solution = calcValue + dblDisplayVal;
        }else if(subtractionTriggered){
            solution = calcValue - dblDisplayVal;
        }else if(multiplicationTriggered){
            solution = calcValue * dblDisplayVal;
        }else if(divisionTriggered){
            solution = calcValue / dblDisplayVal;
        }
    }

    ui->lineEdit_display->setText(QString::number(solution));
}

void Calculator::slot_changeSignPressed()
{
    QString displayValue = ui->lineEdit_display->text();
    QRegExp reg("[-]?[0-9.]*");
    if(reg.exactMatch(displayValue)){
        double dblDisplayValue = displayValue.toDouble();
        double dblDisplayValSign = -1 * dblDisplayValue;
        ui->lineEdit_display->setText(QString::number(dblDisplayValSign));
    }
}
