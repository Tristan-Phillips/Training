#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QObject>
#include <QString>
#include <QStringList>

class Customer : QObject
{
    Q_OBJECT
    Q_PROPERTY(QString p_title READ getTitle WRITE setTitle)
    Q_PROPERTY(QString p_name READ getName WRITE setName)
    Q_PROPERTY(QString p_address READ getAddress WRITE setAddress)
    Q_PROPERTY(QString p_postCode READ getPostCode WRITE setPostCode)
    Q_PROPERTY(QString p_code READ getCode WRITE setCode)

public:
    Customer();
    Customer(QString t, QString n, QStringList a, QString pc, QString c);

    QString getTitle() const;
    void setTitle(QString t);

    QString getName() const;
    void setName(QString n);

    QStringList getAddress() const;
    void setAddress(QStringList a);

    QString getPostCode() const;
    void setPostCode(QString pc);

    QString getCode() const;
    void setCode(QString c);

    QString toString() const;

private:
    QString m_title;
    QString m_name;
    QStringList m_address;
    QString m_postCode;
    QString m_code;
};

#endif // CUSTOMER_H
