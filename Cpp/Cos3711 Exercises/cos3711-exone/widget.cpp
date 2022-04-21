#include "widget.h"
#include <QCoreApplication>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setupUI();
    QWidget::connect(m_pushButton_quit, SIGNAL(clicked()), this, SLOT(quit()));
}

Widget::~Widget()
{
}

void Widget::setupUI()
{
    //Set Small Details
    this->setWindowTitle("Hello Qt");

    //Window Size
    this->setFixedWidth(280);
    this->setFixedHeight(332);

    m_textEdit = new QTextEdit;

    m_pushButton_process = new QPushButton("Process");
    m_pushButton_quit = new QPushButton("Quit");

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(m_textEdit);
    vbox->addWidget(m_pushButton_process);
    vbox->addWidget(m_pushButton_quit);

    this->setLayout(vbox);
}

void Widget::slot_buttonPressed_process()
{
    QString result;
    result += "Hello Qt";
    result += qVersion();

    this->m_textEdit->setText(result);
}

