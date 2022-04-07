#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

FilmInput::FilmInput(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

FilmInput::~FilmInput()
{
    delete ui;
}


void FilmInput::on_pushButton_writeToFile_clicked()
{
    QString title = ui->lineEdit_title->text(), director = ui->lineEdit_director->text();
    int duration = (ui->spinBox_durationHours->value() * 10) + ui->spinBox_durationMinutes->value();
    QDate releaseDate = QDate::currentDate();//ui->dateEdit_releaseDate->text();

    Film film(title, director, duration, releaseDate);
    FilmWriter writer("filmFile.txt");
    bool successfulWrite = writer.saveFilm(film);
    if(successfulWrite){
        QMessageBox::information(0, "Success", "File written");
    }else{
        QMessageBox::critical(0, "Failed", "The file failed to write");
    }
}

