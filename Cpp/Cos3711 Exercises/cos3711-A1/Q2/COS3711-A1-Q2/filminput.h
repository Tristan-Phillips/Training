#ifndef FILMINPUT_H
#define FILMINPUT_H

#include "film.h"
#include <QWidget>

//Forward Declerations
class QLineEdit;
class QPushButton;
class QDateEdit;
class QSpinBox;

class FilmInput : public QWidget
{
    Q_OBJECT

public:
    FilmInput(QWidget *parent = nullptr);
    ~FilmInput();
    void setupUI();

public slots:
    void slot_clearInput();
    void slot_saveInput();

private:
    Film m_film;
    //Dynamic Inputs
    QLineEdit *m_pullTitle;
    QLineEdit *m_pullDirector;
    QSpinBox *m_pullDurationHours;
    QSpinBox *m_pullDurationMinutes;
    QDateEdit *m_pullReleaseDate;
    //Static Inputs
    QPushButton *m_submitSave;
    QPushButton *m_submitCancel;
    //Text Formatting
    int m_maxLabelTextHeight = 10;
    int m_maxLabelCharWidth = 10;
    int m_maxLabelTextWidth = 80;
    //Constraints
    int m_maximumMinutes = 59;
    //Non-magic Numbers
    QString m_fileName = "Films.txt";
};
#endif // FILMINPUT_H
