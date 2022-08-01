#ifndef GUI_H
#define GUI_H

#include <QDialog>

class GUI : public QDialog
{
    Q_OBJECT

public:
    GUI(QWidget *parent = nullptr);
    ~GUI();
};
#endif // GUI_H
