#ifndef GUI_H
#define GUI_H

#include <QWidget>
class QPushButton;
class QLineEdit;
class QLabel;

class GUI : public QWidget
{
    Q_OBJECT

public:
    GUI(QWidget *parent = nullptr);
    ~GUI();
    void setupUI();
public slots:
    void slot_check();
private:
    QPushButton *pushButton_check;
    QLineEdit *lineEdit_expression;
    QLabel *label_result;
};
#endif // GUI_H
