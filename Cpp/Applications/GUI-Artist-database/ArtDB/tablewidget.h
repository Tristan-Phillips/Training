#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QObject>
#include <QStringList>

//Forward Decleration
class QMainWindow;
class QTableWidget;

class tableWidget : public QObject
{
    Q_OBJECT
public:
    explicit tableWidget(QMainWindow *obj, QTableWidget *widget);

    void populate_tableWidget(QTableWidget *widget);

signals:

private:
    int m_tableWidget_columnCount = 4;
    int m_tableWidget_rowCount = 4;
    QStringList m_tableWidget_columHeaders = {"Name", "Dimensions", "Paint Type", "Sold"};
};

#endif // TABLEWIDGET_H
