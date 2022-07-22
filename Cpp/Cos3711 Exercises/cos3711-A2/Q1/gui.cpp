#include "gui.h"
#include "loadfile.h"
#include "regexvalidation.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QToolTip>
#include <QMessageBox>
#include <QCloseEvent>
#include <QLabel>
#include <QDir>
#include <QTreeView>
#include <QLineEdit>
#include <QList>
#include <QFileSystemModel>
#include <QPushButton>

GUI::GUI(QWidget *parent)
    : QWidget(parent),
      textEdit_outputWidget{new QTextEdit(this)},
      treeView_directories{new QTreeView(this)},
      pushButton_loadFile{new QPushButton("Load File")},
      pushButton_calculate{new QPushButton("Generate output")},
      fileSystemModel_directory{new QFileSystemModel(this)},
      lineEdit_logProgression{new QLineEdit(this)}
{
    setupUI();
    this->connect(pushButton_loadFile, &QPushButton::clicked, this, &GUI::slot_pushButtonLoad);
    this->connect(treeView_directories, &QTreeView::clicked, this, &GUI::slot_directorySelection);
    this->connect(pushButton_calculate, &QPushButton::clicked, this, &GUI::slot_pushButtonCalculate);
}

void GUI::setupUI()
{
    this->setWindowTitle("XML File Checker");
    this->setMinimumWidth(minimumWindowWidth);

    //Only two layouts for GUI
    QVBoxLayout *vBox_fullLayout = new QVBoxLayout(this);
    QHBoxLayout *hBox_topTwoButtons = new QHBoxLayout(this);
    //Load toolTip text set in header file
    pushButton_loadFile->setToolTip(toolTip_pushButton_loadFile);
    pushButton_calculate->setToolTip(toolTip_pushButton_calculate);
    //Add pushButtons to the horizontal layout
    hBox_topTwoButtons->addWidget(pushButton_loadFile);
    hBox_topTwoButtons->addWidget(pushButton_calculate);
    //Setup Directory View for simple file selection
    setupDirectoryView(vBox_fullLayout, treeView_directories);

    vBox_fullLayout->addWidget(treeView_directories);
    vBox_fullLayout->addLayout(hBox_topTwoButtons);
    vBox_fullLayout->addWidget(textEdit_outputWidget);

    //TextEdit parameters
    textEdit_outputWidget->setReadOnly(true);

    //Setup line edit progression log
    lineEdit_logProgression->setReadOnly(true);
    lineEdit_logProgression->setAlignment(Qt::AlignRight);
    lineEdit_logProgression->setStyleSheet("color: #808080;");
    lineEdit_logProgression->setText(logProgressDefaultText);
    lineEdit_logProgression->setToolTip(toolTip_lineEdit_directories);
    vBox_fullLayout->addWidget(lineEdit_logProgression);

    //Display GUI
    this->setLayout(vBox_fullLayout);
    this->show();
}

void GUI::setupDirectoryView(QVBoxLayout *vBox, QTreeView *treeView)
{
    QLabel *label_title = new QLabel("Directory View : Select a file to load");
    vBox->addWidget(label_title);

    //Get current path and set root path
    QString currentDir = QDir::currentPath();
    fileSystemModel_directory->setRootPath(currentDir);
    treeView->setModel(fileSystemModel_directory);
}

void GUI::clearOutput()
{
    lineEdit_logProgression->setText(logProgressDefaultText);
    textEdit_outputWidget->setText("");
}

GUI::~GUI()
{}

//Override close event to ask user if confident
void GUI::closeEvent(QCloseEvent *event)
{
    event->ignore();
    if(QMessageBox::Yes == QMessageBox::question(this, "Quit", "Do you want to quit the application?", QMessageBox::Yes | QMessageBox::No)){
        event->accept();
    }
}

void GUI::slot_pushButtonLoad()
{
    LoadFile loadObj;
    fileContent = loadObj.readFile(this, selectedFilePath);
    if(!fileContent.isEmpty()){
        QMessageBox::information(this, "File Loaded", "The selected file has been loaded", QMessageBox::Ok);
    }
    lineEdit_logProgression->setText("The selected file has been successfully loaded");
}

void GUI::slot_pushButtonCalculate()
{
    clearOutput();
    RegExValidation regexObj(&fileContent);
    QString output = regexObj.regexSort();

    if(selectedFilePath != "C:/" || selectedFilePath.isEmpty()){
        if(!output.isEmpty()){
            textEdit_outputWidget->append(output);
        }else{
            textEdit_outputWidget->append("The selected file has produced no output");
        }
    }else{
        QMessageBox::information(this, "Select a file", "Please select an appropriate XML file", QMessageBox::Ok);
    }
}

void GUI::slot_directorySelection()
{
    selectedFilePath = fileSystemModel_directory->fileInfo(treeView_directories->currentIndex()).absoluteFilePath();
    lineEdit_logProgression->setText(selectedFilePath);
}

