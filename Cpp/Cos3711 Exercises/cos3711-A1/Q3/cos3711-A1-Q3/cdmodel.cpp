#include "cd.h"
#include "cdmodel.h"

CDModel::CDModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    m_columnHeader
            << "Composer"
            << "Album Name"
            << "Cost (R)"
            << "Rating";
}

int CDModel::columnCount(const QModelIndex&) const
{
    return m_columnHeader.count();
}

QVariant CDModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            return m_columnHeader[section];
        }
    }

    return QVariant();
}

Qt::ItemFlags CDModel::flags(const QModelIndex &index) const
{
    if (index.isValid()) {
        return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
    }

    return  Qt::ItemIsEnabled;
}

void CDModel::addCD(QString composer, QString name, float value, int rating)
{
    beginInsertRows(QModelIndex(), 0, 0);
    m_CDList.append(QSharedPointer<CD>(new CD(composer, name, value, rating)));
    endInsertRows();
}


QVariant CDModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid()) {
        int row = index.row();
        int col = index.column();

        if (row >= rowCount() || row < 0 || col >= columnCount() || col < 0) {
            return QVariant();
        }

        QSharedPointer<CD> album = m_CDList[row];

        if (role == Qt::DisplayRole || role == Qt::EditRole) {
            switch (col) {
            case 0: return album->get_composer();
            case 1: return album->get_name();
            case 2:
            {
                double val = static_cast<double>(album->get_cost());
                if (role == Qt::DisplayRole) {
                    return QString::number(val, 'f', 2);
                }
                else {
                      return val;
                }
            }
            case 3: return album->get_rating();
            }
        }
    }

    return QVariant();
}

bool CDModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole || !index.isValid()) {
        return false;
    }

    int row = index.row();
    int col = index.column();

    if (row < 0 || row >= rowCount()) {
        return false;
    }

    QSharedPointer<CD> album = m_CDList[row];

    switch (col) {
    case 0: album->set_composer(value.toString()); break;
    case 1: album->set_name(value.toString()); break;
    case 2:
    {
        float val = value.toFloat();
        if (val < 0) {
            return false;
        }
        album->set_cost(val);
        break;
    }
    case 3:
    {
        int val = value.toInt();
        if(val < 0 || val > 100) {
            return false;
        }
        album->set_rating(value.toInt());
        break;
    }
    default: return false;
    }

    emit dataChanged(index, index);

    return true;
}

int CDModel::rowCount(const QModelIndex&) const
{
    return m_CDList.size();
}
