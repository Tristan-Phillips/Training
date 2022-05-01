#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//Forward Declerations
class QGraphicsView;
class QTableWidget;
class QLineEdit;
class QPushButton;

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
    void slot_pushButton_viewFull();

private:
    //Remove QListView *m_mainWindow_listView;
    QTableWidget *m_mainWindow_tableWidget;
    QGraphicsView *m_mainWindow_graphicsView;
    QLineEdit *m_mainWindow_lineEdit;
    QPushButton *m_mainWindow_pushButtonViewFull;

    //Table active row column
    int m_tableWidget_activeRow;
    int m_tableWidget_activeColumn;
};
#endif // MAINWINDOW_H
