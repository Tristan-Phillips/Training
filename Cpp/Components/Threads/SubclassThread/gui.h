#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include "workerthread.h"

//Forward Declerations
class QPushButton;
class QProgressBar;
class QThread;

class GUI : public QWidget
{
    Q_OBJECT

public:
    GUI(QWidget *parent = nullptr);
    ~GUI();
    void setupUI();
public slots:
    void slot_pushButtonStartClicked();
    void slot_pushButtonInfoClicked();
    void currentCount(int value);
private:
    QPushButton *pushButton_start;
    QPushButton *pushButton_info;
    QProgressBar *progressBar_main;
    WorkerThread *m_thread;

};
#endif // GUI_H
