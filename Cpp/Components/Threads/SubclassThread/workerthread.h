#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>

class WorkerThread : public QThread
{
    Q_OBJECT
public:
    explicit WorkerThread(QObject *parent = nullptr);
    ~WorkerThread();
signals:
    void currentCount(int value);

    // QThread interface
protected:
    void run();
};

#endif // WORKERTHREAD_H
