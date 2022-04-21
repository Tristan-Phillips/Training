#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //UI
    void setupUI();

signals:
    void signal_buttonPressed_process();

private slots:
    void slot_buttonPressed_process();

private:
    QTextEdit *m_textEdit;
    QPushButton *m_pushButton_process;
    QPushButton *m_pushButton_quit;
};
#endif // WIDGET_H
