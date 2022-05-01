#include "mainwindow.h"
#include "setui.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    SetUI *obj;
    obj->set_mainWindow(this);
}

MainWindow::~MainWindow()
{
}

