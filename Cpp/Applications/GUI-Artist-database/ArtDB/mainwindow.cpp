#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QPushButton>
#include <QGraphicsView>
#include <QLineEdit>
#include <QTextBrowser>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include "tablewidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI_mainWindow();
    setup_mainWindow_tableWidget();
    QObject::connect(this->m_mainWindow_tableWidget, SIGNAL(cellClicked(int,int)), this, SLOT(slot_rowSelected_displayName(int, int)));
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUI_mainWindow()
{
    this->setWindowTitle("Artist Personal Database");
    this->setMinimumSize(1000,600);

    //Setup MenuBar
    //TODO

    //Set Member Variables to New NULL
    m_mainWindow_tableWidget = new QTableWidget;
    /*->*/m_mainWindow_tableWidget->setMinimumWidth(700);

    m_mainWindow_graphicsView = new QGraphicsView;

    m_mainWindow_lineEdit = new QLineEdit;
    /*->*/m_mainWindow_lineEdit->setReadOnly(true);

    QTextBrowser *textBrowser_listViewSelected_shortHandMetaInfo = new QTextBrowser;
    QPushButton *pushButton_viewFull = new QPushButton("Open Full View");
    QHBoxLayout *firstLayer_hLayout = new QHBoxLayout;
    QVBoxLayout *firstLayer_vLayout = new QVBoxLayout;

    //Rightside VLayout
    firstLayer_vLayout->addWidget(m_mainWindow_graphicsView);
    firstLayer_vLayout->addWidget(m_mainWindow_lineEdit);
    firstLayer_vLayout->addWidget(textBrowser_listViewSelected_shortHandMetaInfo);
    firstLayer_vLayout->addWidget(pushButton_viewFull);


    //Leftside HLayout
    firstLayer_hLayout->addWidget(m_mainWindow_tableWidget);

    //Add VLayout to HLayout
    firstLayer_hLayout->addLayout(firstLayer_vLayout);

    //Create the widget that contains all the main window widgets
    QWidget *mainWindow = new QWidget();
    mainWindow->setLayout(firstLayer_hLayout);

    //Set mainWindow as the active widget to display
    setCentralWidget(mainWindow);
}

void MainWindow::setup_mainWindow_tableWidget()
{
    QTableWidget *widget = m_mainWindow_tableWidget;
    tableWidget obj(this, widget);
}

void MainWindow::slot_rowSelected_displayName(int row, int column)
{
    //0 = column because location of Name text
    QTableWidgetItem *item = this->m_mainWindow_tableWidget->item(row,0);
    this->m_mainWindow_lineEdit->setText(item->text());
}
