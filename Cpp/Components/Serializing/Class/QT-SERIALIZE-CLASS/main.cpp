#include <QCoreApplication>
#include <QDataStream>
#include <QDebug>
#include <QDir>
#include <QFile>
#include "oclass.h"

bool saveFile(OClass *obj, QString path){
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)){
        return false;
    }

    QDataStream ds(&file);
    ds.setVersion(QDataStream::Qt_5_15);
    ds << *obj;

    file.close();
    return true;
}

bool loadFile(QString path){
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }

    QDataStream ds(&file);
    OClass obj;
    ds >> obj;

    file.close();

    qInfo() << "Name: " << obj.get_name();
    foreach(QString key, obj.get_map().keys()){
        qInfo() << key << " : " << obj.get_map().value(key);
    }

    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = "test.txt";
    OClass obj;
    obj.fill();

    if(saveFile(&obj,path)){
        loadFile(path);
    }

    return a.exec();
}
