#ifndef VIEWER_H
#define VIEWER_H

#include <QDialog>
class QPlainTextEdit;
class QPushButton;

class Viewer : public QDialog
{
    Q_OBJECT
public:
    explicit Viewer(QWidget *parent = nullptr);
    bool displayInput(QString fileName, bool html = false);

signals:

private:
    void setupGUI();

    QPlainTextEdit *txtDisplay;
    QPushButton *btnClose;

};

#endif // VIEWER_H
