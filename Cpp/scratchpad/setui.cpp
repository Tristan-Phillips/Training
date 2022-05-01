#include "setui.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QLineEdit>
#include <QMainWindow>

SetUI::SetUI(QObject *parent)
    : QObject{parent}
{

}

void SetUI::set_mainWindow(QWidget *obj)
{
    obj->setWindowTitle("Qt Core Scratchpad");

    //Layout creation
    QHBoxLayout *layout_hBox(new QHBoxLayout);
    QVBoxLayout *layout_vBox(new QVBoxLayout);

    QTableWidget *widget_table(new QTableWidget);

    //Add widgets to layouts
    layout_hBox->addWidget(widget_table);

    //Create overarching display
    QWidget *mainWindow = new QWidget();
    mainWindow->setLayout(layout_hBox);

    mainWindow->show();
}
