#include "filewriter.h"

#include <QFile>
#include <QTextStream>
#include <QMetaObject>
#include <QMetaProperty>

FileWriter::FileWriter(QString fName)
    : m_fileName(fName)
{
}

bool FileWriter::write(QString str) const
{
    QFile outFile(m_fileName);
    if (!outFile.open(QIODevice::WriteOnly)) {
            return false;
    }

    QTextStream out(&outFile);
    out << str;
    out.flush();  // Flush buffer to ensure all data written to file

    outFile.close();

    return true;
}

bool FileWriter::objWrite(QObject &object)
{
    QFile file(m_fileName);
    if(file.open(QIODevice::ReadWrite | QIODevice::Append)){
            QTextStream out(&file);
            const QMetaObject *metaObject = object.metaObject();
            for(int i = 1; i < metaObject->propertyCount(); i++){
                QString propertyName = QString(metaObject->property(i).name());
                QVariant propertyValue = metaObject->property(i).read(&object);
                out << QString("\n%1 : %2\n").arg(propertyName, propertyValue.toString());
            }
            file.flush();
            file.close();
            return true;
    }else{
        return false;
    }
}

