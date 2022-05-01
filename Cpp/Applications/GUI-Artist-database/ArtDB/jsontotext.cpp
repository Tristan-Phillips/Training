#include "jsontotext.h"

JsonToText::JsonToText(QObject *parent)
    : QObject{parent}
{

}

QString JsonToText::get_columnName() const
{
    //toDo get and send
    return m_columnName;
}
