#include "gui.h"
#include <QThread>
#include <QPushButton>
#include <QProgressBar>
#include <QGridLayout>
#include <QDebug>

GUI::GUI(QWidget *parent)
    : QWidget(parent),
      pushButton_start{new QPushButton("Start")},
      pushButton_info{new QPushButton("Info")},
      progressBar_main{new QProgressBar},
      m_thread{new WorkerThread(this)}
{
    qDebug() << "GUI Thread: " << QThread::currentThread();
    setupUI();
    this->connect(m_thread, &WorkerThread::currentCount, this, &GUI::currentCount);
    this->connect(pushButton_start, &QPushButton::clicked, this, &GUI::slot_pushButtonStartClicked);
    this->connect(pushButton_info, &QPushButton::clicked, this, &GUI::slot_pushButtonInfoClicked);

    this->connect(m_thread, &QThread::started,[](){
       qDebug() << "Thread started";
    });
    this->connect(m_thread, &QThread::finished,[](){
       qDebug() << "Thread finished";
    });
}

GUI::~GUI()
{
}

void GUI::setupUI(){
    QGridLayout *gridLayout_main{new QGridLayout(this)};
    gridLayout_main->addWidget(pushButton_start, 0, 0, Qt::AlignVCenter);
    gridLayout_main->addWidget(pushButton_info, 0, 1, Qt::AlignVCenter);
    gridLayout_main->addWidget(progressBar_main, 1, 0, 1, 2, Qt::AlignVCenter);

    this->setLayout(gridLayout_main);
    this->show();
}

void GUI::slot_pushButtonStartClicked()
{
    m_thread->start();
}

void GUI::slot_pushButtonInfoClicked()
{
    qDebug() << "Worker Thread Status: " << m_thread->isRunning();
}

void GUI::currentCount(int value)
{
    this->progressBar_main->setValue(value);
    this->setWindowTitle(QString::number(value));
}
