#ifndef MUSICMODEL_H
#define MUSICMODEL_H

#include <QStandardItemModel>

class MusicModel : public QStandardItemModel
{
public:
    explicit MusicModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};

#endif // MUSICMODEL_H
