#ifndef FILMWRITER_H
#define FILMWRITER_H
#include <QFile>
#include <QTextStream>
#include <QMetaProperty>
#include "film.h"

class FilmWriter
{
public:
    FilmWriter(QString filePath);
    bool saveFilm(Film &film);
private:
    QString m_filePath;
};

#endif // FILMWRITER_H
