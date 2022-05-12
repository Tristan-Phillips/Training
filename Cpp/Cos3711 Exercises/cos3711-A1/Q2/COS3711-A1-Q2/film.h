#ifndef FILM_H
#define FILM_H

#include <QWidget>
#include <QString>
#include <QDate>

class Film : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString p_title READ get_title WRITE set_title)
    Q_PROPERTY(QString p_director READ get_director WRITE set_director)
    Q_PROPERTY(int p_duration READ get_length WRITE set_length)
    Q_PROPERTY(QDate p_releaseDate READ get_releaseDate WRITE set_releaseDate)

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

    void obtainFilmData();
    void saveFilm(Film &film);

private:
    QString m_title;
    QString m_director;
    int m_length; //Minutes
    QDate m_releaseDate;
};

#endif // FILM_H
