#ifndef FILM_H
#define FILM_H
#include <QString>
#include <QDate>
#include <QObject>

class Film : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ get_title WRITE set_title)
    Q_PROPERTY(QString director READ get_director WRITE set_director)
    Q_PROPERTY(int duration READ get_duration WRITE set_duration)
    Q_PROPERTY(QDate releaseDate READ get_releaseDate WRITE set_releaseDate)

public:
    Film(QString t, QString d, int du, QDate rd);
    //Getters
    QString get_title() const;
    QString get_director() const;
    int get_duration() const;
    QDate get_releaseDate() const;
    //Setters
    void set_title(QString title);
    void set_director(QString director);
    void set_duration(int duration);
    void set_releaseDate(QDate releaseDate);

private:
    QString title;
    QString director;
    int duration;
    QDate releaseDate;
};

#endif // FILM_H
