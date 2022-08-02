#include "customerclient.h"
#include "custview.h"
#include "viewer.h"
#include "filereader.h"

#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QLayout>
#include <QStatusBar>
#include <QMessageBox>
#include <QFileDialog>
#include <QCloseEvent>

CustomerClient::CustomerClient(QWidget *parent)
    : QMainWindow(parent),
      view(new CustView)
{
    // Setup actions
    setupActions();

    // Setup menu
    setupMenus();

    // Setup tool bar
    setupToolbar();

    // Connect Signals and Slots
    connect(view, &CustView::displayMessage, this, &CustomerClient::showStatus);
    connect(actOpen, &QAction::triggered, this, &CustomerClient::openFile);
    connect(actSave, &QAction::triggered, this, &CustomerClient::saveFile);
    connect(actSaveAs, &QAction::triggered, this, &CustomerClient::saveAs);
    connect(actView, &QAction::triggered, this, &CustomerClient::viewXML);
    connect(actAbout, &QAction::triggered, this, &CustomerClient::showAbout);
    connect(actHelp, &QAction::triggered, this, &CustomerClient::showHelp);
    connect(actExit, &QAction::triggered, this, &QMainWindow::close);
    connect(actNew, &QAction::triggered, view, &CustView::clearModel);
    connect(actAdd, &QAction::triggered, view, &CustView::addCustomer);

    // Initialize window
    setCentralWidget(view);
    setWindowTitle("Customer client");
    setWindowState(Qt::WindowMaximized);

    // Read customer list from file
    view->readListXml();

    statusBar()->showMessage("Ready", 3000);
}

void CustomerClient::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open file","" ,"XML files (*.xml)");
    if (!fileName.isNull()) {
        view->readListXml(fileName);
    }
    else {
        showStatus("No file selected");
    }
}

void CustomerClient::saveFile()
{
    view->writeListXml();
}

void CustomerClient::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save As","" ,"XML files (*.xml)");
    if (!fileName.isNull()) {
        view->writeListXml(fileName);
    }
    else {
        showStatus("No file selected");
    }
}

void CustomerClient::viewXML()
{
    Viewer viewer;
    viewer.setWindowTitle("XML Viewer");

    if (viewer.displayInput("customers.xml")) {
        viewer.exec();
    }
    else {
        showStatus("View XML - no data to view");
    }
}

void CustomerClient::showAbout()
{
    QString content = QString("%1\n%2\n%3 %4\n%5").arg("Customer client - v1.00")
                                               .arg("Date: February 2022")
                                               .arg("Written with Qt version:")
                                               .arg(qVersion())
                                               .arg("Author: Ron Barnard");

    QMessageBox::about(this, "About", content);
}

void CustomerClient::showHelp()
{
    Viewer viewer;
    viewer.setWindowTitle("Help");
    viewer.setMinimumSize(600, 500);

    if (viewer.displayInput("help.txt", true)) {
        viewer.exec();
    }
    else {
        showStatus("View Help - no data to view");
    }
}

void CustomerClient::showStatus(QString message)
{
    statusBar()->showMessage(message, 3000);
}

void CustomerClient::setupActions()
{
    actNew = new QAction(QIcon(":/Images/new.png"), "New");
    actOpen = new QAction(QIcon(":/Images/open.png"), "Open");
    actSave = new QAction(QIcon(":/Images/save.png"), "Save");
    actSaveAs = new QAction(QIcon(":/Images/saveas.png"), "Save As");
    actAdd = new QAction(QIcon(":/Images/add.png"), "Add");
    actView = new QAction(QIcon(":/Images/xml.png"), "ViewXML");
    actAbout = new QAction(QIcon(":/Images/info.png"), "About");
    actHelp = new QAction(QIcon(":/Images/help.png"), "Help");
    actExit = new QAction(QIcon(":/Images/exit.png"),"Exit");
}

void CustomerClient::setupMenus()
{
    mnuFile = menuBar()->addMenu("File");
    mnuFile->addAction(actNew);
    mnuFile->addAction(actOpen);
    mnuFile->addAction(actSave);
    mnuFile->addAction(actSaveAs);
    mnuFile->addSeparator();
    mnuFile->addAction(actExit);

    mnuEdit = menuBar()->addMenu("Edit");
    mnuEdit->addAction(actAdd);
    //mnuEdit->addAction();

    mnuView = menuBar()->addMenu("View");
    mnuView->addAction(actView);

    mnuReport = menuBar()->addMenu("Report");
    // mnuReport->addAction();

    mnuHelp = menuBar()->addMenu("Help");
    mnuHelp->addAction(actAbout);
    mnuHelp->addAction(actHelp);
}

void CustomerClient::setupToolbar()
{
    toolbar = addToolBar("Customer");
    toolbar->layout()->setSpacing(20);

    toolbar->addAction(actNew);
    toolbar->addAction(actOpen);
    toolbar->addAction(actSave);
    toolbar->addAction(actSaveAs);
    toolbar->addAction(actAdd);
}

void CustomerClient::closeEvent(QCloseEvent *event)
{
    int response;
    response = QMessageBox::warning(this, "Exit", "Are you sure you want to Exit ?",
                                        QMessageBox::Yes | QMessageBox::No);
    if (response == QMessageBox::Yes) {
        view->writeListXml();
        event->accept();
    }
    else {
         event->ignore();
    }
}
