#include "filminput.h"

#include "filmwriter.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QDateEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>

FilmInput::FilmInput(QWidget *parent)
    : QWidget(parent),
      m_pullTitle(new QLineEdit),
      m_pullDirector(new QLineEdit),
      m_pullDurationHours(new QSpinBox),
      m_pullDurationMinutes(new QSpinBox),
      m_pullReleaseDate(new QDateEdit),
      m_submitSave(new QPushButton("Save")),
      m_submitCancel(new QPushButton("Cancel"))
{
    setupUI();
    connect(m_submitCancel, &QPushButton::clicked, this, &FilmInput::slot_clearInput);
    connect(m_submitSave, &QPushButton::clicked, this, &FilmInput::slot_saveInput);
}

void FilmInput::setupUI(){

    this->setWindowTitle("Films");

    //Layout
    QVBoxLayout *vBoxLayout = new QVBoxLayout;
    QHBoxLayout *hBoxLayout_top = new QHBoxLayout,
            *hBoxLayout_topLeft = new QHBoxLayout,
            *hBoxLayout_topRight = new QHBoxLayout,
            *hBoxLayout_mid = new QHBoxLayout,
            *hBoxLayout_midLeft = new QHBoxLayout,
            *hBoxLayout_midRight = new QHBoxLayout,
            *hBoxLayout_bottom = new QHBoxLayout;

    m_pullTitle->setPlaceholderText("Title");
    m_pullDirector->setPlaceholderText("Director");

    QLabel *labelDuration(new QLabel("Duration: ")),
           *labelDurationHours(new QLabel("H")),
           *labelDurationMinutes(new QLabel("M"));

    labelDuration->setMaximumSize(m_maxLabelTextWidth,m_maxLabelTextHeight);
    labelDurationHours->setMaximumSize(m_maxLabelCharWidth,m_maxLabelTextHeight);
    labelDurationMinutes->setMaximumSize(m_maxLabelCharWidth,m_maxLabelTextHeight);

    //Duration - TOP Left
    hBoxLayout_topLeft->addWidget(labelDuration);
    hBoxLayout_top->addLayout(hBoxLayout_topLeft);
    //Duration - TOP Right
    hBoxLayout_topRight->addWidget(m_pullDurationHours);
    hBoxLayout_topRight->addWidget(labelDurationHours);
    /**/m_pullDurationMinutes->setMaximum(m_maximumMinutes);
    hBoxLayout_topRight->addWidget(m_pullDurationMinutes);
    hBoxLayout_topRight->addWidget(labelDurationMinutes);
    hBoxLayout_top->addLayout(hBoxLayout_topRight);
    hBoxLayout_topLeft->addLayout(hBoxLayout_topRight);

    QLabel *labelReleaseDate(new QLabel("Release Date: "));
    labelReleaseDate->setMaximumSize(m_maxLabelTextWidth,m_maxLabelTextHeight);

    //Release Date - Mid Left
    hBoxLayout_midLeft->addWidget(labelReleaseDate);
    hBoxLayout_mid->addLayout(hBoxLayout_midLeft);
    //Release Date - Mid Right
    hBoxLayout_midRight->addWidget(m_pullReleaseDate);
    hBoxLayout_mid->addLayout(hBoxLayout_midRight);

    //PushButton - Bottom
    hBoxLayout_bottom->addWidget(m_submitCancel);
    hBoxLayout_bottom->addWidget(m_submitSave);

    //Add Widgets to layout
    vBoxLayout->addWidget(m_pullTitle);
    vBoxLayout->addWidget(m_pullDirector);
    vBoxLayout->addLayout(hBoxLayout_top);
    vBoxLayout->addLayout(hBoxLayout_mid);
    vBoxLayout->addLayout(hBoxLayout_bottom);

    //SetPrimaryLayout
    /*m_widget->setLayout(vBoxLayout);*/
    this->setLayout(vBoxLayout);
}

void FilmInput::slot_clearInput()
{
    m_pullTitle->clear();
    m_pullDirector->clear();
    m_pullDurationHours->setValue(0);
    m_pullDurationMinutes->setValue(0);
    m_pullReleaseDate->setDate(QDate::currentDate());
}

void FilmInput::slot_saveInput()
{
    bool universalBool = true;

    //Pull UI values
    QString title = this->m_pullTitle->text();
    QString director = this->m_pullDirector->text();
    int duration = (this->m_pullDurationHours->value()*60)+(this->m_pullDurationMinutes->value());
    QDate releaseDate = this->m_pullReleaseDate->date();

    if(title == ""){
        QMessageBox::warning(0,"Error","You need to enter the title");
        universalBool = false;
    }else if(director == ""){
        QMessageBox::warning(0,"Error","You need to enter the director");
        universalBool = false;
    }else if(duration == 0){
        QMessageBox::warning(0,"Error","You need to enter the duration");
        universalBool = false;
    }else if(releaseDate > QDate::currentDate()){
        QMessageBox::warning(0,"Error","The release date can not be in the future");
        universalBool = false;
    }

    if(universalBool){

        m_film.setProperty("p_title",title);
        m_film.setProperty("p_director",director);
        m_film.setProperty("p_duration",duration);
        m_film.setProperty("p_releaseDate",releaseDate);

        FilmWriter writer(m_fileName);
        if(writer.outputToFile(m_film)){
            QMessageBox::information(0, "Saved", "The file has been saved");
            slot_clearInput();
        }else{
            QMessageBox::critical(0, "Critical", "The file was unable to write");
        }
    }
}

FilmInput::~FilmInput()
{
    delete m_pullTitle;
    delete m_pullDirector;
    delete m_pullDurationHours;
    delete m_pullDurationMinutes;
    delete m_pullReleaseDate;
    delete m_submitSave;
    delete m_submitCancel;
}

