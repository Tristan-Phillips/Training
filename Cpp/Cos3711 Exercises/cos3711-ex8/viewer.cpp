#include "viewer.h"
#include "filereader.h"

#include <QPlainTextEdit>
#include <QPushButton>
#include <QVBoxLayout>

Viewer::Viewer(QWidget *parent)
    : QDialog(parent),
      txtDisplay(new QPlainTextEdit),
      btnClose(new QPushButton("Close"))
{
    setupGUI();

    connect(btnClose, &QPushButton::clicked, this, &QWidget::close);

    setWindowTitle("Viewer");
    setMinimumSize(300, 500);
}

bool Viewer::displayInput(QString fileName, bool html)
{
    FileReader fr(fileName);
    QString inStr = fr.read();

    if (inStr.length() > 0) {
        if (html) {
            txtDisplay->appendHtml(inStr);
        }
        else {
            txtDisplay->appendPlainText(inStr);
        }

        return true;
    }

    return false;
}

void Viewer::setupGUI()
{
    QVBoxLayout *layout(new QVBoxLayout(this));

    layout->addWidget(txtDisplay);
    layout->addWidget(btnClose);

    txtDisplay->setReadOnly(true);
}
