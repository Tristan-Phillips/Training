#ifndef CUSTOMERCLIENT_H
#define CUSTOMERCLIENT_H

#include <QMainWindow>
class CustView;
class QAction;
class QMenu;
class QToolBar;
class Viewer;

class CustomerClient : public QMainWindow
{
    Q_OBJECT
public:
    explicit CustomerClient(QWidget *parent = nullptr);
    void closeEvent(QCloseEvent *event);

signals:

public slots:
    void showStatus(QString);

private slots:
    void openFile();
    void saveFile();
    void saveAs();
    void viewXML();
    void showAbout();
    void showHelp();

private:
    CustView *view;

    void setupActions();
    void setupMenus();
    void setupToolbar();

    QAction *actNew;
    QAction *actOpen;
    QAction *actSave;
    QAction *actSaveAs;
    QAction *actAdd;
    QAction *actView;
    QAction *actAbout;
    QAction *actHelp;
    QAction *actExit;

    QMenu *mnuFile;
    QMenu *mnuEdit;
    QMenu *mnuView;
    QMenu *mnuReport;
    QMenu *mnuHelp;

    QToolBar *toolbar;
};

#endif // CUSTOMERCLIENT_H
