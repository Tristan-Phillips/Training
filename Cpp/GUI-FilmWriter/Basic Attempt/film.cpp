#include "film.h"

Film::Film(QString title, QString director, int duration, QDate releaseDate)
{
    m_title = title;
    m_director = director;
    m_duration = duration;
    m_releaseDate = releaseDate;
}

QString Film::toString()
{
    return QString("Title: %1, Director: %2, Duration: %3, Release Date: %4")
            .arg(m_title)
            .arg(m_director)
            .arg(m_duration)
            .arg(m_releaseDate.toString("dd-MM-yyyy"));
}
