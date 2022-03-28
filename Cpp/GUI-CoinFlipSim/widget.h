#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    int generateOneOrZero();
    void updateClickCount();
    void updateImage(int headOrTailResult);

private slots:
    void on_pushButton_clickToFlip_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
