#include "mainwindow.h"
#include "setupui.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    SetupUI objUI(this, this);
}

MainWindow::~MainWindow()
{
}

