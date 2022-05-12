#ifndef FILMWRITER_H
#define FILMWRITER_H

#include <QString>

class FilmWriter
{
public:
    FilmWriter(QString fileName);
    bool outputToFile(QString string);

private:
    QString m_fileName;
};

#endif // FILMWRITER_H
