#include "filmwriter.h"

#include <QTextStream>
#include <QFile>
#include <QMetaObject>
#include <QMetaProperty>


FilmWriter::FilmWriter(QString fileName)
    : m_fileName(fileName)
{}

bool FilmWriter::outputToFile(QObject &object)
{
    //Tests file and outputs to file if valid
    QFile file(m_fileName);
    if(file.open(QIODevice::ReadWrite | QIODevice::Append)){

        QTextStream out(&file);
        const QMetaObject *metaObject = object.metaObject();
        for(int i = 1; i < metaObject->propertyCount(); i++){
            QString propertyName = QString(metaObject->property(i).name());
            QVariant propertyValue = metaObject->property(i).read(&object);
            out << QString("\n%1: %2\n").arg(propertyName, propertyValue.toString());
        }
        file.flush();
        file.close();
        return true;
    }else{
        return false;
    }
}
