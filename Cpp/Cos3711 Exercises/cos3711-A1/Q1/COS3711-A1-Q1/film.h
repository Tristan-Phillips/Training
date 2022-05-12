#ifndef FILM_H
#define FILM_H

#include <QWidget>
#include <QString>
#include <QDate>

class Film
{
public:
    Film();
    Film(QString title, int length, QString director, QDate releaseDate);

    //Getters
    QString get_title() const;
    QString get_director() const;
    int get_length() const;
    QDate get_releaseDate() const;
    //Setters
    void set_title(QString title);
    void set_director(QString director);
    void set_length(int length);
    void set_releaseDate(QDate releaseDate);

    //Two Null functions
    //Replaced with serializer
    void obtainFilmData();
    void saveFilm(Film &film);

private:
    QString m_title;
    QString m_director;
    int m_length; //Minutes
    QDate m_releaseDate;
};

#endif // FILM_H
