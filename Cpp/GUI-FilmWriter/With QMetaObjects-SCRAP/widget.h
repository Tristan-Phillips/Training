#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "film.h"
#include "filmwriter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class FilmInput : public QWidget
{
    Q_OBJECT

public:
    FilmInput(QWidget *parent = nullptr);
    ~FilmInput();

private slots:
    void on_pushButton_writeToFile_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
