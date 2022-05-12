#ifndef CD_H
#define CD_H

#include <QString>

class CD
{
public:
    CD(QString composer, QString name, float cost, int rating);

    QString get_composer() const;
    QString get_name() const;
    float get_cost() const;
    int get_rating() const;
    QString toString() const;

    void set_composer(QString composer);
    void set_name(QString name);
    void set_cost(float cost);
    void set_rating(int rating);
private:
    QString m_composer;
    QString m_albumName;
    float m_cost;
    int m_rating;
};

#endif // CD_H
