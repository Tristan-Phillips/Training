#include "musicmodel.h"

MusicModel::MusicModel(QObject *parent)
    : QStandardItemModel{parent}
{
}

QVariant MusicModel::data(const QModelIndex &index, int role) const
{
    // Return cell contents, format column 2 to 2 decimal places
    if (role == Qt::DisplayRole || role == Qt::EditRole) {

        int col = index.column();
        QStandardItem *item(itemFromIndex(index));

        // Format double to 2 decimal places for column 2
        if (col == 2) {
            return QVariant(QString::number(item->data(Qt::DisplayRole).toDouble(), 'f', 2));
        }

        return item->data(Qt::DisplayRole);
    }

    // Red background for cost value greater than 250.00
    if (role == Qt::BackgroundRole) {

        int row = index.row();
        QStandardItem *item(itemFromIndex(this->index(row, 2)));

        if (item->data(Qt::DisplayRole).toDouble() >= 250.00) {

           return QBrush(Qt::red);
        }
    }

    // Right justify numeric cells
    // Not required for question, but looks better
    if ((role == Qt::TextAlignmentRole) && (index.column() == 2 || index.column() == 3)) {

        return int(Qt::AlignRight | Qt::AlignVCenter);
    }

    return QVariant();
}
