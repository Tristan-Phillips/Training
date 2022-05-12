#include "filmwriter.h"
#include <QTextStream>
#include <QFile>

FilmWriter::FilmWriter(QString fileName)
    : m_fileName(fileName)
{}

bool FilmWriter::outputToFile(QString string)
{
    QFile file(m_fileName);
    if(file.open(QIODevice::ReadWrite | QIODevice::Append)){
        QTextStream out(&file);
        out << string;
        file.flush();
        file.close();
        return true;
    }else{
        return false;
    }
}
