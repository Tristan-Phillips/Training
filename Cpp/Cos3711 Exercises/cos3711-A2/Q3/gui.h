#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include "operationfactory.h"

//Forward Declerations
class QPushButton;
class QDoubleSpinBox;
class QLCDNumber;

class GUI : public QWidget
{
    Q_OBJECT

public:
    GUI(QWidget *parent = nullptr);
    void setupUI();
    void resetUI();
    void setObjectNames();
    ~GUI();
private slots:
    void slots_handleClickEvents();
private:
    QPushButton *pushButton_addition;
    QPushButton *pushButton_subtraction;
    QPushButton *pushButton_multiplication;
    QPushButton *pushButton_division;
    QPushButton *pushButton_clear;
    QDoubleSpinBox *dSpinBox_first;
    QDoubleSpinBox *dSpinBox_second;
    QLCDNumber *lcdNumber_result;
//
    OperationFactory *m_operationFactory;
};
#endif // GUI_H
