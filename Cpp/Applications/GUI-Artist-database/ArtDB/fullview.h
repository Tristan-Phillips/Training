#ifndef FULLVIEW_H
#define FULLVIEW_H

#include <QObject>
#include <QString>
//Forward Decleration
class QMainWindow;
class QTableWidget;
class QWidget;

class FullView : public QObject
{
    Q_OBJECT
public:
    explicit FullView(QMainWindow *obj, QTableWidget *widget, int row, int column);

    QString get_activeSelection_name() const;

signals:

private:
    QWidget *m_fullView_widget;
};

#endif // FULLVIEW_H
