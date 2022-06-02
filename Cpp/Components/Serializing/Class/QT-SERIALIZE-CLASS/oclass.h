#ifndef OCLASS_H
#define OCLASS_H

#include <QObject>
#include <QDebug>
#include <QMap>
#include <QDataStream>

class OClass : public QObject
{
    Q_OBJECT
public:
    explicit OClass(QObject *parent = nullptr);

    void fill();
    QString get_name() const;
    void set_name(QString value);
    QMap<QString, QString> get_map();

    //Overload Operators
    friend QDataStream &operator <<(QDataStream &stream, const OClass &obj){
        qInfo() << "Overload << ";
        stream << obj.m_name;
        stream << obj.m_map;
        return stream;
    }

    friend QDataStream &operator >>(QDataStream &stream, OClass &obj){
        qInfo() << "Overload >> ";
        stream >> obj.m_name;
        stream >> obj.m_map;
        return stream;
    }

private:
    QString m_name;
    QMap<QString, QString> m_map;
};

#endif // OCLASS_H
