#ifndef CDVIEW_H
#define CDVIEW_H

#include <QWidget>

class QDoubleSpinBox;
class QLineEdit;
class QPushButton;
class QSpinBox;
class QAbstractTableModel;

class CDView : public QWidget
{
    Q_OBJECT
public:
    explicit CDView(QWidget *parent = 0);
    void setupUI();

public slots:
    void slot_addCDClicked();
    void slot_deleteCDClicked();
private:
    QLineEdit *m_pullComposer;
    QLineEdit *m_pullAlbumName;
    QDoubleSpinBox *m_pullCost;
    QSpinBox *m_pullRating;
    QPushButton *m_submitAdd;
    QPushButton *m_submitDelete;
    QAbstractTableModel *m_CDModel;

    //Constraints
    int m_maxLabelWidth = 80;
    int m_minimumTableLabelWidth = 500;
};

#endif // CDVIEW_H
