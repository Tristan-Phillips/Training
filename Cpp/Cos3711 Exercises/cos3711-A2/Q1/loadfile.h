#ifndef LOADFILE_H
#define LOADFILE_H

#include<QString>
#include <QList>
#include <QWidget>

class LoadFile
{
public:
    LoadFile();
    QString readFile(QWidget *parent, QString filePath);
};

#endif // LOADFILE_H
