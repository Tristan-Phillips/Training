#include "oclass.h"

OClass::OClass(QObject *parent)
    : QObject{parent}
{

}

void OClass::fill()
{
    m_name = "Test object";
    for(int i = 0; i < 10; i++){
        QString num = QString::number(i);
        QString key = "Key: " + num;
        QString value = "This is item number " + num;
        m_map.insert(key,value);
    }
}

QString OClass::get_name() const
{
    return m_name;
}

void OClass::set_name(QString value)
{
    m_name = value;
}

QMap<QString, QString> OClass::get_map()
{
    return m_map;
}

void OClass::set_map(QMap<QString, QString> value)
{
    m_map = value;
}
