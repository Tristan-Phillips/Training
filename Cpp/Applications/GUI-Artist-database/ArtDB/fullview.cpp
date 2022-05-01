#include "fullview.h"
#include "jsontotext.h"
#include <QMainWindow>

FullView::FullView(QMainWindow *obj, QTableWidget *widget, int row, int column) //: QObject{parent}
{
    //this->setWindowTitle("Pressed");
    obj->setWindowTitle("Full View Pressed");

    //Create full view widget
    m_fullView_widget = new QWidget;
    m_fullView_widget->setWindowTitle(get_activeSelection_name());
    m_fullView_widget->show();
}

QString FullView::get_activeSelection_name() const
{
    JsonToText obj;
    return obj.get_columnName();
}
