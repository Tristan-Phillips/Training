#ifndef CDVIEW_H
#define CDVIEW_H

#include <QWidget>
class QLineEdit;
class QSpinBox;
class QDoubleSpinBox;
class QPushButton;
class MusicModel;
class QTableView;

class CDView : public QWidget
{
    Q_OBJECT
public:
    explicit CDView(QWidget *parent = nullptr);

private slots:
    void addCD();
    void deleteCD();

private:
    void setupGUI();
    void setupView();

    MusicModel *model;
    QTableView *view;

    QLineEdit *edtComposer;
    QLineEdit *edtTitle;
    QDoubleSpinBox *dspCost;
    QSpinBox *spnRating;
    QPushButton *btnAdd;
    QPushButton *btnDelete;
};

#endif // CDVIEW_H
