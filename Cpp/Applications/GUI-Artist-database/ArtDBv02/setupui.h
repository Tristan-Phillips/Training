#ifndef SETUPUI_H
#define SETUPUI_H

#include <QObject>
#include <QString>

//Forward Declerations
class QMainWindow;
class QWidget;
class QTableWidget;
class QMainWindow;
class QToolBar;

class SetupUI : public QObject
{
    Q_OBJECT
public:
    explicit SetupUI(QWidget *widget, QMainWindow *mainWindow);
    void setupToolbar();
    void setupTableWidget();

signals:


public slots:
    void addUI();
private:
    QString m_applicationName = "Artist Database";
    QTableWidget *m_databaseTableWidget;

    QWidget *m_widget;
    QMainWindow *m_mainWindow;
    QToolBar *m_mainToolbar;
};

#endif // SETUPUI_H
