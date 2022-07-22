#include "loadfile.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

LoadFile::LoadFile()
{}

QString LoadFile::readFile(QWidget *parent, QString filePath)
{
    //Loads file exactly as is into QStrinList
    QString fileContent;
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::critical(parent, "ERROR", "Could not open the selected file: " + filePath, QMessageBox::Ok);
        return nullptr;
    }
    QTextStream fin(&file);
    while(!fin.atEnd()){
        QString line = fin.readLine();
        fileContent.append(line);
    }
    file.close();
    return fileContent;
}
