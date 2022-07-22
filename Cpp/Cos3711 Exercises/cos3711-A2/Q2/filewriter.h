#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <QString>

class FileWriter
{
public:
    FileWriter(QString fileName);
    void writeToFile(QString string) const;
private:
    QString m_fileName;
};

#endif // FILEWRITER_H
