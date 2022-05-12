#include "cd.h"
#include <QString>

CD::CD(QString composer, QString name, float cost, int rating) :
    m_composer(composer),
    m_albumName(name),
    m_cost(cost),
    m_rating(rating)
{}

QString CD::get_name() const
{
    return m_albumName;
}

QString CD::get_composer() const
{
    return m_composer;
}

float CD::get_cost() const
{
    return m_cost;
}

int CD::get_rating() const
{
    return m_rating;
}

QString CD::toString() const
{
    return QString("%0, %1 R%2, %3/100")
            .arg(get_name())
            .arg(get_composer())
            .arg(QString::number(static_cast<double>(get_cost()), 'f', 2)
                 .arg(get_rating()));
}

void CD::set_name(QString name)
{
    m_albumName = name;
}

void CD::set_composer(QString composer)
{
    m_composer = composer;
}

void CD::set_cost(float cost)
{
    m_cost = cost;
}

void CD::set_rating(int rating)
{
    m_rating = rating;
}


