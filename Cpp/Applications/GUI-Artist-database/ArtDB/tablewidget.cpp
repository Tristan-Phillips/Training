#include "tablewidget.h"
#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QAbstractItemView>
#include <QHeaderView>

tableWidget::tableWidget(QMainWindow *obj, QTableWidget *widget)
    : QObject{obj}
{
    //Setup
    widget->setColumnCount(m_tableWidget_columnCount);
    widget->setRowCount(m_tableWidget_rowCount);
    widget->setHorizontalHeaderLabels(m_tableWidget_columHeaders);
    populate_tableWidget(widget);

    //Styling
    widget->setStyleSheet("QTableWidget{"
                          "backgoround-color: #C0C0C0;"
                          "alternate-background-color: #606060;"
                          "selection-background-color: #282828;"
                          "}");
    widget->setAlternatingRowColors(true);

    //Full row selection and highlighting
    widget->setSelectionMode(QAbstractItemView::SingleSelection);
    widget->setSelectionBehavior(QAbstractItemView::SelectRows);
    widget->setTextElideMode(Qt::ElideRight);

    //Table Properties
    widget->setShowGrid(true);
    widget->setGridStyle(Qt::DotLine);
    widget->setSortingEnabled(true);
    widget->setCornerButtonEnabled(true);

    //Header Properties
    widget->horizontalHeader()->setVisible(true);
    widget->horizontalHeader()->setDefaultSectionSize(150);
    widget->horizontalHeader()->setStretchLastSection(true);
}

void tableWidget::populate_tableWidget(QTableWidget *widget)
{
    //To be replaced with pulling data from JSON
    int rows = m_tableWidget_rowCount, columns = m_tableWidget_columnCount;
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < columns ; j++){
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText("TEMP DATA" + QString::number(i));
            widget->setItem(i,j,item);
        }
    }


}
