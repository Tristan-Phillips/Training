#include "gui.h"
#include "worker.h"
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
      m_thread{new QThread(this)}
{
    qDebug() << "Main Thread: " << QThread::currentThread();

    setupUI();
    this->connect(pushButton_start, &QPushButton::clicked, this, &GUI::slot_startClicked);
    this->connect(pushButton_info, &QPushButton::clicked, this, &GUI::slot_infoClicked);
    this->connect(m_thread, &QThread::finished, this, &GUI::slot_threadFinished);
}

GUI::~GUI()
{
}

void GUI::setupUI()
{
    QGridLayout *gridLayout_main{new QGridLayout(this)};
    gridLayout_main->addWidget(pushButton_start, 0, 0, Qt::AlignVCenter);
    gridLayout_main->addWidget(pushButton_info, 0, 1, Qt::AlignVCenter);
    gridLayout_main->addWidget(progressBar_main, 1, 0, 1, 2, Qt::AlignVCenter);

    this->setLayout(gridLayout_main);
    this->show();
}

void GUI::slot_startClicked()
{
    Worker *worker = new Worker; //Lives in main thread
    worker->moveToThread(m_thread); //The code is going to run in another thread
    this->connect(m_thread, &QThread::started, worker, &Worker::doCounting);//Runs once the thread starts
    this->connect(worker, &Worker::currentCount, this, &GUI::slot_currentCount);
    this->connect(worker, &Worker::countDone, this, &GUI::slot_countDone);
    this->connect(m_thread, &QThread::finished, worker, &GUI::deleteLater);

    m_thread->start();
}

void GUI::slot_infoClicked()
{
    qDebug() << "Thread Running: " << m_thread->isRunning();
}

void GUI::slot_countDone()
{
    qDebug() << "GUI, count Done";
    //To stop the event loop
    m_thread->exit();
}

void GUI::slot_currentCount(int value)
{
    progressBar_main->setValue(value);
    this->setWindowTitle(QString::number(value));
}

void GUI::slot_threadFinished()
{
    qDebug() << "Thread Finished. Thread: " << QThread::currentThread();
    qDebug() << "Thread Finished. Current Thread: " << QThread::currentThread();
}

