#include "filewriter.h"

#include <QFile>
#include <QTextStream>

FileWriter::FileWriter(QString fileName): m_fileName{fileName}
{}

void FileWriter::writeToFile(QString string) const
{
    QFile file(m_fileName);
    file.open(QIODevice::WriteOnly);
    QTextStream fout(&file);
    fout << string;
    file.close();
}
