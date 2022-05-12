#include "film.h"

Film::Film()
{

}

Film::Film(QString title, int length, QString director, QDate releaseDate)
    : m_title(title),
      m_director(director),
      m_length(length),
      m_releaseDate(releaseDate)
{
}

QString Film::get_title() const
{
    return m_title;
}

QString Film::get_director() const
{
    return m_director;
}

int Film::get_length() const
{
    return m_length;
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

void Film::set_length(int length)
{
    m_length = length;
}

void Film::set_releaseDate(QDate releaseDate)
{
    m_releaseDate = releaseDate;
}

void Film::obtainFilmData()
{

}

void Film::saveFilm(Film &film)
{

}
