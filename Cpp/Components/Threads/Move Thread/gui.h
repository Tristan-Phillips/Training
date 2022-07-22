#ifndef GUI_H
#define GUI_H

#include <QWidget>

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
    void slot_startClicked();
    void slot_infoClicked();
    void slot_countDone();
    void slot_currentCount(int value);
    void slot_threadFinished();
private:
    QPushButton *pushButton_start;
    QPushButton *pushButton_info;
    QProgressBar *progressBar_main;
    QThread *m_thread;
};
#endif // GUI_H
