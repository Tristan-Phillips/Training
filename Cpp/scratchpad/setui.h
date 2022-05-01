#ifndef SETUI_H
#define SETUI_H

#include <QObject>

//Forward Decleration
class QWidget;

class SetUI : public QObject
{
    Q_OBJECT
public:
    explicit SetUI(QObject *parent = nullptr);
    void set_mainWindow(QWidget *obj);

signals:

};

#endif // SETUI_H
