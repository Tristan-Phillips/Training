#include "gui.h"
#include "regex.h"
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>

GUI::GUI(QWidget *parent)
    : QWidget(parent),
    pushButton_check(new QPushButton("Check")),
    lineEdit_expression(new QLineEdit(this)),
    label_result(new QLabel("Result"))
{
    setupUI();
    this->connect(pushButton_check, &QPushButton::clicked, this, &GUI::slot_check);
}

GUI::~GUI()
{}

void GUI::setupUI(){
    this->setWindowTitle("Regex Tester");
    QVBoxLayout *vbox_main = new QVBoxLayout(this);

    vbox_main->addWidget(lineEdit_expression);
    vbox_main->addWidget(pushButton_check);
    vbox_main->addWidget(label_result);

    this->setLayout(vbox_main);
    this->show();
}

void GUI::slot_check()
{
    regex tempObj;
    if(tempObj.checkMatch(lineEdit_expression->text())){
        label_result->setText("Match");
    }else{
        label_result->setText("No Match");
    }
}
