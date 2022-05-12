#ifndef FILMWRITER_H
#define FILMWRITER_H

#include <QString>
#include <QObject>

class FilmWriter
{
public:
    FilmWriter(QString fileName);
    bool outputToFile(QObject &object);

private:
    QString m_fileName;
};

#endif // FILMWRITER_H
