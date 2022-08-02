#ifndef CUSTOMERTABLEMODEL_H
#define CUSTOMERTABLEMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include "customer.h"

class CustomerTableModel : public QAbstractTableModel
{
public:
    static CustomerTableModel* getInstance();
    ~CustomerTableModel();
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    void addCustomer(Customer *cust);
    bool removeRow(int row);
    void clear();
    QList<Customer*>& getList();
    void setList(QList<Customer*> list);

private:
    CustomerTableModel();
    QList<Customer*> customerList;
};

#endif // CUSTOMERTABLEMODEL_H
