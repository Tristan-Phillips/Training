#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void slot_numberPressed();
    void slot_mathButtonPressed();
    void slot_equalButtonPressed();
    void slot_changeSignPressed();

private:
    Ui::Calculator *ui;
};
#endif // CALCULATOR_H
