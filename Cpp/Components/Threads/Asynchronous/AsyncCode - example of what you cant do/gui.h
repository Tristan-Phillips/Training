#ifndef GUI_H
#define GUI_H

#include <QWidget>

//Forward Declerations
class QThread;
class QPushButton;

class GUI : public QWidget
{
    Q_OBJECT

public:
    GUI(QWidget *parent = nullptr);
    ~GUI();
    void setupUI();
public slots:
    void slot_pushButtonStart();
private:
    QThread *m_thread;
    QPushButton *pushButton_start;
};
#endif // GUI_H
