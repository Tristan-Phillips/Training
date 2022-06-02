#include <QCoreApplication>
#include <QDebug>
#include "oclass.h"
#include "converter.h"

void writeXML(QString path){
    OClass obj;
    obj.fill();
    Converter::writeXML(&obj,path);
}

void readXML(QString path){
    OClass *obj;
    obj = Converter::readXML(path);

    if(!obj){
        qInfo() << "Object not loaded";
        return;
    }

    qInfo() << "Name: " << obj->get_name();
    foreach(QString key, obj->get_map().keys()){
        qInfo() << key << " : " << obj->get_map().value(key);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = "text.txt";

    writeXML(path);
    readXML(path);

    return a.exec();
}
