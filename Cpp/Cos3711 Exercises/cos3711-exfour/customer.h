#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>
#include <QStringList>

class Customer
{
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
