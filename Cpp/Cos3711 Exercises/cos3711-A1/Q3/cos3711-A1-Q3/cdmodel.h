#ifndef CDMODEL_H
#define CDMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include <QModelIndex>
#include <QSharedPointer>
#include <QString>
#include <QVariant>

#include "cd.h"

class CDModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit CDModel(QObject *parent = 0);
    int rowCount(const QModelIndex& = QModelIndex()) const;
    int columnCount(const QModelIndex& = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex& index) const;

    void addCD(QString composer, QString name, float value, int rating);
private:
    QList<QSharedPointer<CD> > m_CDList;
    QStringList m_columnHeader;
};

#endif // CDMODEL_H
