#ifndef JSONTOTEXT_H
#define JSONTOTEXT_H

#include <QObject>
#include <QString>
class JsonToText : public QObject
{
    Q_OBJECT
public:
    explicit JsonToText(QObject *parent = nullptr);
    QString get_columnName() const;

signals:

private:
        QString m_columnName = QString("name");
};

#endif // JSONTOTEXT_H
