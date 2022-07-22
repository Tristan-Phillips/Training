#include "worker.h"
#include <QVariant>
#include <QThread>
#include <QDebug>

Worker::Worker(QObject *parent)
    : QObject{parent}
{
    qDebug() << "Worker constructor running in thread: " << QThread::currentThread();
}

Worker::~Worker()
{
    qDebug() << "Worker destructor called, running in thread: " << QThread::currentThread();
}

void Worker::doCounting()
{
    qDebug() << "Worker doCounting is running in thread: " << QThread::currentThread();

    //This will run in background thread
    for(int i{0}; i < 1000000000; i++){
        double percentage = (i/1000000000.0) * 100.00;
        //qDebug() << "Percentage: " << percentage;

        //We dont want to be sending too much information from the background thread to the GUI thread
        if((i%100000) == 0){
            emit currentCount(QVariant::fromValue(percentage).toInt());
        }
    }
    emit countDone();
}
