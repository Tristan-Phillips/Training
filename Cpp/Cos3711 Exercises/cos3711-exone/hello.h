#ifndef HELLO_H
#define HELLO_H

#include <QWidget>
class QTextEdit;
class QPushButton;

class Hello : public QWidget
{
    Q_OBJECT
public:
    explicit Hello(QWidget *parent = nullptr);

private slots:
    void processInput();

private:
    void setupGUI();
    QTextEdit *txtInput;
    QPushButton *btnProcess;
    QPushButton *btnQuit;
};

#endif // HELLO_H
