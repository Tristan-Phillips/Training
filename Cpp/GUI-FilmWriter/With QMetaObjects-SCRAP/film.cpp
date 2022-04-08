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

QString Film::get_title() const
{
    return m_title;
}

QString Film::get_director() const
{
    return m_director;
}

int Film::get_duration() const
{
    return m_duration;
}

QDate Film::get_releaseDate() const
{
    return m_releaseDate;
}

void Film::set_title(QString title)
{
    m_title = title;
}

void Film::set_director(QString director)
{
    m_director = director;
}

void Film::set_duration(int duration)
{
    m_duration = duration;
}

void Film::set_releaseDate(QDate releaseDate)
{
    m_releaseDate = releaseDate;
}
