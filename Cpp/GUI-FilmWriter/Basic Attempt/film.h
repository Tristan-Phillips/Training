#ifndef FILM_H
#define FILM_H
#include <QString>
#include <QDate>

class Film
{
public:
    Film(QString title, QString director, int duration, QDate releaseDate);
    QString toString();

private:
    QString m_title;
    QString m_director;
    int m_duration;
    QDate m_releaseDate;
};

#endif // FILM_H
