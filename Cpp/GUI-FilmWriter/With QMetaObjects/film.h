#ifndef FILM_H
#define FILM_H
#include <QString>
#include <QDate>
#include <QObject>

class Film : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString m_title READ get_title WRITE set_title)
    Q_PROPERTY(QString m_director READ get_title WRITE set_director)
    Q_PROPERTY(int m_duration READ get_duration WRITE set_duration)
    Q_PROPERTY(QDate m_releaseDate READ get_releaseDate WRITE set_releaseDate)

public:
    Film(QString title, QString director, int duration, QDate releaseDate);
    QString toString();

    //getters
    QString get_title() const;
    QString get_director() const;
    int get_duration() const;
    QDate get_releaseDate() const;
    //setters
    void set_title(QString title);
    void set_director(QString director);
    void set_duration(int duration);
    void set_releaseDate(QDate releaseDate);

private:
    QString m_title;
    QString m_director;
    int m_duration;
    QDate m_releaseDate;
};

#endif // FILM_H
