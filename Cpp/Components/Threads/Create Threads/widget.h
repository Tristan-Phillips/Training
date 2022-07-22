#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>

//Forward Declerations
class QPushButton;
class QThread;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void setupUI();
    void count();
public slots:
    void slot_startClicked();
private:
    QPushButton *pushButton_start;
    //Thread
    QThread *m_thread;
    //Constraints
    int m_minWidth = 300;
};
#endif // WIDGET_H
