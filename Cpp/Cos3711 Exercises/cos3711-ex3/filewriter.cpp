#include "filewriter.h"

#include <QFile>
#include <QTextStream>

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

