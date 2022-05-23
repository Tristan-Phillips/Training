#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <QString>
#include <QObject>

class FileWriter
{
public:
    FileWriter(QString fName);
    bool write(QString str) const;
    bool objWrite(QObject &object);

private:
    QString m_fileName;
};

#endif // FILEWRITER_H
