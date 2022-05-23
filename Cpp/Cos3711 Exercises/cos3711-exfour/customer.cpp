#include "customer.h"

Customer::Customer()
{
}

Customer::Customer(QString t, QString n, QStringList a, QString pc, QString c)
    : m_title(t), m_name(n), m_address(a), m_postCode(pc), m_code(c)
{

}

QString Customer::getTitle() const
{
    return m_title;
}

void Customer::setTitle(QString t)
{
    m_title = t;
}

QString Customer::getName() const
{
    return m_name;
}

void Customer::setName(QString n)
{
    m_name = n;
}

QStringList Customer::getAddress() const
{
    return m_address;
}

void Customer::setAddress(QStringList a)
{
    m_address = a;
}

QString Customer::getPostCode() const
{
    return m_postCode;
}

void Customer::setPostCode(QString pc)
{
    m_postCode = pc;
}

QString Customer::getCode() const
{
    return m_code;
}

void Customer::setCode(QString c)
{
    m_code = c;
}

QString Customer::toString() const
{
    return m_code + " " + m_title + " " + m_name + "\n" + m_address.join("\n") + "\n" + m_postCode;
}
