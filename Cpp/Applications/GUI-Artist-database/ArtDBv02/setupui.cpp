#include "setupui.h"
#include <QWidget>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>
#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QToolBar>
#include <QAction>

#include <QTableWidgetItem>
#include <QAbstractItemView>
#include <QHeaderView>

SetupUI::SetupUI(QWidget *widget, QMainWindow *mainWindow)
{
    m_widget = widget;
    m_mainWindow = mainWindow;

    //Start
    widget->setWindowTitle(m_applicationName);

    QHBoxLayout *hboxLayout = new QHBoxLayout;
    setupTableWidget();
    //m_databaseTableWidget = new QTableWidget;
    //m_databaseTableWidget->setMinimumWidth(400);
    hboxLayout->addWidget(m_databaseTableWidget);

    QVBoxLayout *vboxLayout = new QVBoxLayout;
    hboxLayout->addLayout(vboxLayout);

    //Doesnt Work \/
    QGraphicsView *graphicsView = new QGraphicsView;
    graphicsView->setMinimumSize(300,300);
    QGraphicsScene *sceneGraphics = new QGraphicsScene;
    QPixmap pixmapImage;
    pixmapImage.load("resources/image/logo.png");
    sceneGraphics->addPixmap(pixmapImage);
    sceneGraphics->setSceneRect(pixmapImage.rect());
    graphicsView->setScene(sceneGraphics);
    vboxLayout->addWidget(graphicsView);

    QLineEdit *displayName = new QLineEdit;
    displayName->setReadOnly(true);
    vboxLayout->addWidget(displayName);

    QTextEdit *selectionDetails = new QTextEdit;
    selectionDetails->setReadOnly(true);
    vboxLayout->addWidget(selectionDetails);

    QPushButton *viewSelection = new QPushButton;
    viewSelection->setText("View Selection");
    vboxLayout->addWidget(viewSelection);

    QWidget *mainWindowWidget = new QWidget;
    mainWindowWidget->setLayout(hboxLayout);
    mainWindow->setCentralWidget(mainWindowWidget);

    setupToolbar();

    //m_widget->connect(viewSelection, &QPushButton::released, this, &SetupUI::addEditUI);
    //QObject::connect(viewSelection, &QPushButton::released, this, &SetupUI::addEditUI);
    addUI();
}

void SetupUI::setupToolbar()
{
    m_mainToolbar = new QToolBar;

    QAction *addAction = new QAction("Add");
    QAction *editAction = new QAction("Edit");
    QAction *delAction = new QAction("Delete");

    m_mainToolbar->addAction(addAction);
    m_mainToolbar->addAction(editAction);
    m_mainToolbar->addAction(delAction);

    //Connect Action to slot for add edit delete

    m_widget->layout()->setMenuBar(m_mainToolbar);
}

void SetupUI::setupTableWidget()
{
    m_databaseTableWidget = new QTableWidget;

    m_databaseTableWidget->setColumnCount(4);
    m_databaseTableWidget->setRowCount(4);
    m_databaseTableWidget->setMinimumWidth(800);

    m_widget->setStyleSheet("QTableWidget{"
                          "backgoround-color: #C0C0C0;"
                          "alternate-background-color: #606060;"
                          "selection-background-color: #282828;"
                          "}");
    m_databaseTableWidget->setAlternatingRowColors(true);

    //Full row selection and highlighting
    m_databaseTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    m_databaseTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_databaseTableWidget->setTextElideMode(Qt::ElideRight);

    //Table Properties
    m_databaseTableWidget->setShowGrid(true);
    m_databaseTableWidget->setGridStyle(Qt::DotLine);
    m_databaseTableWidget->setSortingEnabled(true);
    m_databaseTableWidget->setCornerButtonEnabled(true);

    //Header Properties
    m_databaseTableWidget->horizontalHeader()->setVisible(true);
    m_databaseTableWidget->horizontalHeader()->setDefaultSectionSize(150);
    m_databaseTableWidget->horizontalHeader()->setStretchLastSection(true);
}

void SetupUI::addUI()
{
    QWidget *addWidget = new QWidget;

    addWidget->setWindowTitle("Add");

    addWidget->show();
}
