#include "filmwriter.h"

FilmWriter::FilmWriter(QString filePath)
{
    m_filePath = filePath;
}

bool  FilmWriter::saveFilm(Film &film)
{
    QFile file(m_filePath);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);
        out << film.toString();
        return true;
    }
    return false;
}
