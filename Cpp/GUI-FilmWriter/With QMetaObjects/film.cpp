#include "film.h"

Film::Film(QString t, QString d, int du, QDate rd)
{
    title = t;
    director = d;
    duration = du;
    releaseDate = rd;
}

QString Film::get_title() const
{
    return title;
}

QString Film::get_director() const
{
    return director;
}

int Film::get_duration() const
{
    return duration;
}

QDate Film::get_releaseDate() const
{
    return releaseDate;
}

void Film::set_title(QString title)
{
    title = title;
}

void Film::set_director(QString director)
{
    director = director;
}

void Film::set_duration(int duration)
{
    duration = duration;
}

void Film::set_releaseDate(QDate releaseDate)
{
    releaseDate = releaseDate;
}

//QString Film::toString()
//{
//    return QString("Title: %1, Director: %2, Duration: %3, Release Date: %4")
//            .arg(m_title)
//            .arg(m_director)
//            .arg(m_duration)
//            .arg(m_releaseDate.toString("dd-MM-yyyy"));
//}
