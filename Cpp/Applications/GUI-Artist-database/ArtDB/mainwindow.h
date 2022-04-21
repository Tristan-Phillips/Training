#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//Forward Declerations
class QGraphicsView;
class QTableWidget;
class QLineEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setupUI_mainWindow();
    void setup_mainWindow_tableWidget();

signals:
    //void signal_rowSelected_displayName();

public slots:
    void slot_rowSelected_displayName(int row, int column);

private:
    //Remove QListView *m_mainWindow_listView;
    QTableWidget *m_mainWindow_tableWidget;
    QGraphicsView *m_mainWindow_graphicsView;
    QLineEdit *m_mainWindow_lineEdit;
};
#endif // MAINWINDOW_H
