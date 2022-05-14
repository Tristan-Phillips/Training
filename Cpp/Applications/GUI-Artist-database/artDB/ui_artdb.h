#ifndef UI_ARTDB_H
#define UI_ARTDB_H

#include <QMainWindow>

class QLineEdit;
class QPushButton;

class ui_ArtDB : public QMainWindow
{
    Q_OBJECT

public:
    ui_ArtDB(QWidget *parent = nullptr);
    ~ui_ArtDB();

    void setupUi();

private:

};
#endif // UI_ARTDB_H
