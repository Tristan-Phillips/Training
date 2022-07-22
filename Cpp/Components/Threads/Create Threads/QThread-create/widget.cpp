#include "widget.h"
#include <QPushButton>
#include <QGridLayout>
#include <QDebug>

#include <QThread>

/*We are going to run this function in
a seperate thread*/
void counting(int variable)
{
    for(int i{0}; i < variable; i++){
        //This thread will be different from the memory location for the ui
        qDebug() << "Counting: " << i
                 << "Thread: " << QThread::currentThread();
    }
}

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      pushButton_start{new QPushButton("Start")}
{
    setupUI();
    //Output the main thread the program is running in
    //Memory location for this thread
    qDebug() << "Main thread: " << QThread::currentThread();

    this->connect(pushButton_start, &QPushButton::clicked, this, &Widget::slot_startClicked);
}

Widget::~Widget()
{
}

void Widget::setupUI()
{
    this->setWindowTitle("QThread::create()");
    QGridLayout *gridLayout_main{new QGridLayout};
    this->setMinimumWidth(m_minWidth);

    gridLayout_main->addWidget(pushButton_start);

    this->setLayout(gridLayout_main);
    this->show();
}

void Widget::count()
{
    for(int i{0}; i < 1000; i++){
        qDebug() << "Countlambda counting";
        qDebug() << "Counting: " << i
                 << " Thread: " << QThread::currentThread()
                 << " ID: " << QThread::currentThreadId();
    }
}



void Widget::slot_startClicked()
{
    qDebug() << "Button Clicked";

    //0-Freeze UI
    //    for(int i{0}; i < 1000000; i++){
    //        qDebug() << "Counting in UI thread";
    //        qDebug() << "Counting: " << i << " Thread: "
    //                 << QThread::currentThread() << " id: "
    //                 << QThread::currentThreadId();
    //    }



    /*1- Global Function
    //Initialize thread
    m_thread = QThread::create(counting, 100);
    */

    /*
    //2- Named Lambda Function
    auto countlambda = [](int count){
        for(int i{0}; i < count; i++){
            qDebug() << "Countlambda counting";
            qDebug() << "Counting: " << i
                     << " Thread: " << QThread::currentThread()
                     << " ID: " << QThread::currentThreadId();
        }
    };
    m_thread = QThread::create(countlambda, 1000);
    */

    /*
    //3- Non named lambda function
    m_thread = QThread::create([](){
        for(int i{0}; i < 1000; i++){
            qDebug() << "Counting: " << i
                     << " Thread: " << QThread::currentThread()
                     << " ID: " << QThread::currentThreadId();
        }
    });
    */

    /*
    //4- Member function, call from lambda function
    m_thread = QThread::create([=](){
        count();
    });
    */

    //To know when your thread starts
    connect(m_thread, &QThread::started,[](){
        qDebug() << "Thread Started";
    });
    //To know when your thread finishes
    connect(m_thread, &QThread::finished,[](){
        qDebug() << "Thread Finished";
    });
    /*You must manage your thread,
    Release your thread*/
    connect(m_thread, &QThread::finished, m_thread, &QThread::deleteLater);

    //To run the thread you must call the start method
    m_thread->start();
}

