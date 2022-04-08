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

        QString title = film.property("title").toString();
        QString director = film.property("director").toString();
        int duration = film.property("duration").toInt();
        QDate releaseDate = film.property("releaseDate").toDate();

        QString result = QString("Title: %1, Director: %2, Duration: %3, Release Date: %4")
                    .arg(title)
                    .arg(director)
                    .arg(duration)
                    .arg(releaseDate.toString("dd-MM-yyyy"));

        out << result;
        return true;
    }
    return false;
}
