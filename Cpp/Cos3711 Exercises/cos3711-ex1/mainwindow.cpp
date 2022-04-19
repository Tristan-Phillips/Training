#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Hello Qt");

    //Window Size
    this->setFixedWidth(280);
    this->setFixedHeight(332);

    pushButton = new QPushButton;
}

MainWindow::~MainWindow()
{
    delete ui;
}

