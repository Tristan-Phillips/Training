#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QString>

//Forward Declarations
class QVBoxLayout;
class QTreeView;
class QTextEdit;
class QTreeView;
class QLineEdit;
class QPushButton;
class QFileSystemModel;

class GUI : public QWidget
{
    Q_OBJECT

public:
    GUI(QWidget *parent = nullptr);
    void setupUI();
    void setupDirectoryView(QVBoxLayout *vBox, QTreeView *treeView);
    void clearOutput();
    ~GUI();
public slots:
    void closeEvent(QCloseEvent *event);
    void slot_pushButtonLoad();
    void slot_pushButtonCalculate();
    void slot_directorySelection();

private:
    QTextEdit *textEdit_outputWidget;
    QTreeView *treeView_directories;
    QPushButton *pushButton_loadFile;
    QPushButton *pushButton_calculate;
    //File Content
    QString fileContent;
    //Directory View
    QFileSystemModel *fileSystemModel_directory;
    QLineEdit *lineEdit_logProgression;
    QString selectedFilePath = "C:/";
    //Constants
    QString logProgressDefaultText = "Select a file to load...";
    int minimumWindowWidth = 500;
    //ToolTip
    QString toolTip_pushButton_loadFile = "Click to load an XML text file";
    QString toolTip_pushButton_calculate = "Click to parse through your XML text file";
    QString toolTip_lineEdit_directories = "Displays current activity";
};
#endif // GUI_H
