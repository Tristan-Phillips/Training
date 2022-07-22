#include "gui.h"
#include "bookinglist.h"
#include "person.h"
#include "writetoxml.h"
#include "readfromxml.h"

#include <filewriter.h>
#include <QMessageBox>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QDateEdit>
#include <QFileDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QCloseEvent>
#include <QXmlSimpleReader>
#include <QXmlInputSource>
#include <QXmlContentHandler>

GUI::GUI(QWidget *parent)
    : QWidget{parent},
      pushButton_addBooking{new QPushButton("Add Booking")},
      lineEdit_contactName{new QLineEdit(this)},
      lineEdit_contactContactNumber{new QLineEdit(this)},
      lineEdit_contactEmail{new QLineEdit(this)},
      lineEdit_guestOneName{new QLineEdit(this)},
      lineEdit_guestOneContactNumber{new QLineEdit(this)},
      lineEdit_guestOneEmail{new QLineEdit(this)},
      lineEdit_guestTwoName{new QLineEdit(this)},
      lineEdit_guestTwoContactNumber{new QLineEdit(this)},
      lineEdit_guestTwoEmail{new QLineEdit(this)},
      dateEdit_bookingArrival{new QDateEdit(this)},
      dateEdit_bookingDeparture{new QDateEdit(this)},
      dateEdit_vacancyArrival{new QDateEdit(this)},
      dateEdit_vacancyDeparture{new QDateEdit(this)},
      textEdit_vacancyStatus{new QTextEdit(this)},
      dateEdit_roomDate{new QDateEdit(this)},
      lineEdit_roomAvailable{new QLineEdit(this)},
      m_bookingList{new BookingList}
{
    if(QMessageBox::Yes == QMessageBox::question(this, "Load File", "Would you like to select an xml file to load?", QMessageBox::Yes | QMessageBox::No)){
        slot_loadXML();
    }
    setupUI();
    this->connect(pushButton_addBooking, &QPushButton::clicked, this, &GUI::slot_addBooking);
    this->connect(dateEdit_vacancyArrival, &QDateEdit::dateChanged, this, &GUI::slot_checkVacancy);
    this->connect(dateEdit_vacancyDeparture, &QDateEdit::dateChanged, this, &GUI::slot_checkVacancy);
    this->connect(dateEdit_roomDate, &QDateEdit::dateChanged, this, &GUI::slot_checkRooms);
}

void GUI::setupUI()
{
    this->setWindowTitle("Guest House");
    this->setMinimumWidth(constant_windowMinWidth);

    QGridLayout *gridLayout_addBooking = setupUI_addBooking();
    QGridLayout *gridLayout_addVacancy = setupUI_checkVacancy();
    QGridLayout *gridLayout_roomAvailability = setupUI_roomAvailability();

    QVBoxLayout *vBox_main = new QVBoxLayout(this);
    vBox_main->addLayout(gridLayout_addBooking);
    vBox_main->addLayout(gridLayout_addVacancy);
    vBox_main->addLayout(gridLayout_roomAvailability);

    this->setLayout(vBox_main);
    this->show();
}

QGridLayout *GUI::setupUI_addBooking()
{
    //Add Booking
    QGridLayout *gridLayout_addBooking = new QGridLayout;
    //Contact Person
    QLabel *label_contactPerson = new QLabel("Contact Person");
    gridLayout_addBooking->addWidget(label_contactPerson, 0, 0);
    gridLayout_addBooking->addWidget(lineEdit_contactName, 1, 0);
    gridLayout_addBooking->addWidget(lineEdit_contactContactNumber, 2, 0);
    gridLayout_addBooking->addWidget(lineEdit_contactEmail, 3, 0);
    //Guest One
    QLabel *label_guestOne = new QLabel("Guest One");
    gridLayout_addBooking->addWidget(label_guestOne, 0, 1);
    gridLayout_addBooking->addWidget(lineEdit_guestOneName, 1, 1);
    gridLayout_addBooking->addWidget(lineEdit_guestOneContactNumber, 2, 1);
    gridLayout_addBooking->addWidget(lineEdit_guestOneEmail, 3, 1);
    //Guest Two
    QLabel *label_guestTwo = new QLabel("Guest Two");
    gridLayout_addBooking->addWidget(label_guestTwo, 0, 2);
    gridLayout_addBooking->addWidget(lineEdit_guestTwoName, 1, 2);
    gridLayout_addBooking->addWidget(lineEdit_guestTwoContactNumber, 2, 2);
    gridLayout_addBooking->addWidget(lineEdit_guestTwoEmail, 3, 2);
    //Arrival and Departure Dates
    QLabel *label_arrivalDate = new QLabel("Arrival Date");
    QLabel *label_departureDate = new QLabel("Departure Date");
    gridLayout_addBooking->addWidget(label_arrivalDate, 0, 3);
    gridLayout_addBooking->addWidget(label_departureDate, 2, 3);
    gridLayout_addBooking->addWidget(dateEdit_bookingArrival, 1, 3);
    gridLayout_addBooking->addWidget(dateEdit_bookingDeparture, 3, 3);
    //Add Booking Button
    gridLayout_addBooking->addWidget(pushButton_addBooking, 4, 0, 1, 4, Qt::AlignHCenter);

    //Setting up widgets defaults
    lineEdit_contactName->setPlaceholderText(constant_placeholderTextName);
    lineEdit_contactContactNumber->setPlaceholderText(constant_placeholderTextPhone);
    lineEdit_contactEmail->setPlaceholderText(constant_placeholderTextEmail);
    lineEdit_guestOneName->setPlaceholderText(constant_placeholderTextName);
    lineEdit_guestOneContactNumber->setPlaceholderText(constant_placeholderTextPhone);
    lineEdit_guestOneEmail->setPlaceholderText(constant_placeholderTextEmail);
    lineEdit_guestTwoName->setPlaceholderText(constant_placeholderTextName);
    lineEdit_guestTwoContactNumber->setPlaceholderText(constant_placeholderTextPhone);
    lineEdit_guestTwoEmail->setPlaceholderText(constant_placeholderTextEmail);
    dateEdit_bookingArrival->setDate(constant_currentDate);
    dateEdit_bookingDeparture->setDate(constant_currentDate.addDays(1));

    return gridLayout_addBooking;
}

QGridLayout *GUI::setupUI_checkVacancy()
{
    QLabel *label_vacancyTitle = new QLabel("Check Vacancy");
    QLabel *label_arrivalDate = new QLabel("Arrival Date");
    QLabel *label_departureDate = new QLabel("Departure Date");
    QGridLayout *gridLayout_addVacancy = new QGridLayout;

    //Labels
    gridLayout_addVacancy->addWidget(label_vacancyTitle, 0, 0);
    gridLayout_addVacancy->addWidget(label_arrivalDate, 1, 0);
    gridLayout_addVacancy->addWidget(label_departureDate, 2, 0);
    //Date Edits
    gridLayout_addVacancy->addWidget(dateEdit_vacancyArrival, 1, 1);
    gridLayout_addVacancy->addWidget(dateEdit_vacancyDeparture, 2, 1);
    //Text Edit To Display Vacancy Status
    gridLayout_addVacancy->addWidget(textEdit_vacancyStatus, 1, 2, 2, 1, Qt::AlignVCenter);

    //Setting up widgets defaults
    dateEdit_vacancyArrival->setDate(constant_currentDate);
    dateEdit_vacancyDeparture->setDate(constant_currentDate);
    textEdit_vacancyStatus->setReadOnly(true);

    return gridLayout_addVacancy;
}

QGridLayout *GUI::setupUI_roomAvailability()
{
    QLabel *label_availabilityTitle = new QLabel("Check Room Availability");
    QLabel *label_date = new QLabel("Date");
    QGridLayout *gridLayout_roomAvailability = new QGridLayout;

    //Labels
    gridLayout_roomAvailability->addWidget(label_availabilityTitle, 0, 0);
    gridLayout_roomAvailability->addWidget(label_date, 1, 0);
    //Date Edit
    gridLayout_roomAvailability->addWidget(dateEdit_roomDate, 1, 1);
    //Text Edit To Display Vacancy Status
    gridLayout_roomAvailability->addWidget(lineEdit_roomAvailable, 1, 2, Qt::AlignVCenter);

    //Setting up widget defaults
    dateEdit_roomDate->setDate(constant_currentDate);
    lineEdit_roomAvailable->setReadOnly(true);

    return gridLayout_roomAvailability;
}

bool GUI::addBookingValidation()
{
    //Arrival Date after or equal to Departure Date
    if(dateEdit_bookingArrival->date() >= dateEdit_bookingDeparture->date()){
        return false;
    }
    //Contact Person
    if(lineEdit_contactName->text() == constant_emptyString){
        return false;
    }
    if(lineEdit_contactContactNumber->text() == constant_emptyString){
        return false;
    }
    if(lineEdit_contactEmail->text() == constant_emptyString){
        return false;
    }
    //Guest One
    if(lineEdit_guestOneName->text() == constant_emptyString){
        return false;
    }
    if(lineEdit_guestOneContactNumber->text() == constant_emptyString){
        return false;
    }
    if(lineEdit_guestOneEmail->text() == constant_emptyString){
        return false;
    }
    //Guest Two
    if(lineEdit_guestTwoName->text() != constant_emptyString ||
            lineEdit_guestTwoContactNumber->text() != constant_emptyString ||
            lineEdit_guestTwoEmail->text() != constant_emptyString){

        if(lineEdit_guestTwoName->text() == constant_emptyString){
            return false;
        }
        if(lineEdit_guestTwoContactNumber->text() == constant_emptyString){
            return false;
        }
        if(lineEdit_guestTwoEmail->text() == constant_emptyString){
            return false;
        }
    }
    return true;
}

void GUI::closeEvent(QCloseEvent *event){
    event->ignore();
    slot_writeXML();
    QMessageBox::StandardButton isClosing;
    isClosing = QMessageBox::question(this, "Closing Application","Are you sure you want to close the application?", QMessageBox::Yes | QMessageBox::No);
    if(isClosing == QMessageBox::Yes){
        event->accept();
    }
}

void GUI::slot_addBooking()
{
    if(addBookingValidation()){
        Person *contactPerson = new Person(lineEdit_contactName->text(), lineEdit_contactContactNumber->text(), lineEdit_contactEmail->text());
        Person *guestOne = new Person(lineEdit_guestOneName->text(), lineEdit_guestOneContactNumber->text(), lineEdit_guestOneEmail->text());
        Person *guestTwo = nullptr;

        bool bookingIsAdded = false;
        QDate arrivalDate = dateEdit_bookingArrival->date();
        QDate departureDate = dateEdit_bookingDeparture->date();

        if(lineEdit_guestTwoName->text().isEmpty()){
            //Only Contact Person And Guest One
            bookingIsAdded = m_bookingList->addBooking(contactPerson, arrivalDate, departureDate, guestOne);
        }else{
            //Contact Person, Guest One and Guest Two
            guestTwo = new Person(lineEdit_guestTwoName->text(), lineEdit_guestTwoContactNumber->text(), lineEdit_guestTwoEmail->text());
            bookingIsAdded = m_bookingList->addBooking(contactPerson, arrivalDate, departureDate, guestOne, guestTwo);
        }

        if(bookingIsAdded){
            QMessageBox::information(this, "Success", "The booking has been added", QMessageBox::Ok);
            slot_clearBookingUI();
        }else{
            QMessageBox::critical(this, "Critical Error", "The booking has not been added", QMessageBox::Ok);
            slot_clearBookingUI();
            delete contactPerson;
            delete guestOne;
            delete guestTwo;
        }
    }else{
        QMessageBox::information(this, "Information needed", "Make sure that all information under contact person and guest one is filled at minimum", QMessageBox::Ok);
    }
}

void GUI::slot_writeXML()
{
    if(m_bookingList->size() != 0){
        QString fileName = QFileDialog::getSaveFileName(this, "Save as", ".", "XML files (*.xml)");
        if(fileName.size() != 0){
            WriteToXML writer;
            QString xml = writer.writeXML(m_bookingList);
            FileWriter fileWriter(fileName);
            fileWriter.writeToFile(xml);
        }else{
            QMessageBox::information(this, "Invalid", "No file name was selected", QMessageBox::Ok);
        }
    }
}

void GUI::slot_loadXML()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open a file", ".", "XML files (*.xml)");
    if(fileName.size() != 0){
        ReadFromXML readXML;
        m_bookingList = readXML.loadFile(fileName);
    }else{
        QMessageBox::information(this, "Error", "The file name selected is empty", QMessageBox::Ok);
    }
}

void GUI::slot_checkVacancy()
{
    if(dateEdit_vacancyArrival->date() >= dateEdit_vacancyDeparture->date()){
        QMessageBox::warning(this, "Date Mismatch", "Your vacancy arrival date can not be ahead of your vacancy departure date", QMessageBox::Ok);
    }else{
        bool isVacancy = m_bookingList->vacancy(dateEdit_vacancyArrival->date(), dateEdit_vacancyDeparture->date());
        if(isVacancy){
            QString vacancyText = "There is a vacancy available";
            textEdit_vacancyStatus->setText(vacancyText);
        }else{
            QString noVacancyText = "There is no vacancy available";
            textEdit_vacancyStatus->setText(noVacancyText);
        }
    }
}

void GUI::slot_checkRooms()
{
    QString totalRoomsAvailable = QString::number(m_bookingList->roomsAvailable(dateEdit_roomDate->date()));
    lineEdit_roomAvailable->setText(totalRoomsAvailable);
}

void GUI::slot_clearBookingUI()
{
    //Contact Person
    lineEdit_contactName->clear();
    lineEdit_contactContactNumber->clear();
    lineEdit_contactEmail->clear();
    //Guest One
    lineEdit_guestOneName->clear();
    lineEdit_guestOneContactNumber->clear();
    lineEdit_guestOneEmail->clear();
    //Guest Two
    lineEdit_guestTwoName->clear();
    lineEdit_guestTwoContactNumber->clear();
    lineEdit_guestTwoEmail->clear();
    //Arrival and Departure Dates
    dateEdit_bookingArrival->setDate(constant_currentDate);
    dateEdit_bookingDeparture->setDate(constant_currentDate.addDays(1));
}
