#include "gui.h"
#include <QTimer>
#include <QThread>
#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>

GUI::GUI(QWidget *parent)
    : QWidget(parent),
      m_thread{new QThread(this)},
      pushButton_start{new QPushButton("Start")}
{
    setupUI();
    this->connect(pushButton_start, &QPushButton::clicked, this, &GUI::slot_pushButtonStart);
    qDebug() << "UI Main Thread: " << QThread::currentThread();

    //You cant run asyncrounous code within QThread::create()
    //Anything that requires an event loop cant run inside
    m_thread = QThread::create([this](){
        QTimer *timer{new QTimer()};
        this->connect(timer, &QTimer::timeout,[](){
            qDebug() << "Timed Out : Thread: " << QThread::currentThread();
        });
        timer->start(1000);
    });

    this->connect(m_thread, &QThread::started,[](){
        qDebug() << "Thread Started";
    });

    this->connect(m_thread, &QThread::finished,[](){
        qDebug() << "Thread Finished";
    });

    //m_thread->start();
}

GUI::~GUI()
{
}

void GUI::setupUI()
{
    QVBoxLayout *vbox_main{new QVBoxLayout};
    vbox_main->addWidget(pushButton_start);

    this->setLayout(vbox_main);
    this->show();
}

void GUI::slot_pushButtonStart()
{
    m_thread->start();
}

