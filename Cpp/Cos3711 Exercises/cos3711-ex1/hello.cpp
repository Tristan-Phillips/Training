#include "hello.h"
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QtGlobal>

Hello::Hello(QWidget *parent)
    : QWidget(parent),
      txtInput(new QTextEdit),
      btnProcess(new QPushButton("Process")),
      btnQuit(new QPushButton("Quit"))
{
    // Set up GUI
    setupGUI();

    // Connect Signals and Slots
    // Old method
    //connect(btnProcess, SIGNAL(clicked()), this, SLOT(processInput()));
    //connect(btnQuit, SIGNAL(clicked()), this, SLOT(close()));

    // New method
    connect(btnProcess, &QPushButton::clicked, this, &Hello::processInput);
    connect(btnQuit, &QPushButton::clicked, this, &QWidget::close);

    // Setup window
    setWindowTitle("Hello Qt");
    setMinimumSize(250, 300);
}

void Hello::processInput()
{
    txtInput->append("Hello Qt");
    txtInput->append(QString("Version: %1").arg(qVersion()));
}

void Hello::setupGUI()
{
    QVBoxLayout *layout(new QVBoxLayout(this));

    layout->addWidget(txtInput);
    layout->addWidget(btnProcess);
    layout->addWidget(btnQuit);
}
