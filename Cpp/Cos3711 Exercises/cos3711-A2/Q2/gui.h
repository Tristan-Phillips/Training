#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QDate>
#include <QString>

#include "person.h"
#include "bookinglist.h"
#include "readfromxml.h"

//Forward Decleration
class QPushButton;
class QDateEdit;
class QDate;
class QLineEdit;
class QGridLayout;
class QDateEdit;
class QTextEdit;

class GUI : public QWidget
{
    Q_OBJECT
public:
    explicit GUI(QWidget *parent = nullptr);
    void setupUI();
    QGridLayout *setupUI_addBooking();
    QGridLayout *setupUI_checkVacancy();
    QGridLayout *setupUI_roomAvailability();
    bool addBookingValidation();
public slots:
    void closeEvent(QCloseEvent *event);
    void slot_addBooking();
    void slot_writeXML();
    void slot_loadXML();
    void slot_checkVacancy();
    void slot_checkRooms();
    void slot_clearBookingUI();
private:
    //UI Elements
    QPushButton *pushButton_addBooking;
    //Contact Person
    QLineEdit *lineEdit_contactName;
    QLineEdit *lineEdit_contactContactNumber;
    QLineEdit *lineEdit_contactEmail;
    //Guest One
    QLineEdit *lineEdit_guestOneName;
    QLineEdit *lineEdit_guestOneContactNumber;
    QLineEdit *lineEdit_guestOneEmail;
    //Guest Two
    QLineEdit *lineEdit_guestTwoName;
    QLineEdit *lineEdit_guestTwoContactNumber;
    QLineEdit *lineEdit_guestTwoEmail;
    //Add Booking Dates
    QDateEdit *dateEdit_bookingArrival;
    QDateEdit *dateEdit_bookingDeparture;
    //Vacancy
    QDateEdit *dateEdit_vacancyArrival;
    QDateEdit *dateEdit_vacancyDeparture;
    QTextEdit *textEdit_vacancyStatus;
    //Room Availability
    QDateEdit *dateEdit_roomDate;
    QLineEdit *lineEdit_roomAvailable;
    //Classes
    BookingList *m_bookingList;
    //Constants
    int constant_windowMinWidth = 600;
    QDate constant_currentDate = QDate::currentDate();
    QString constant_placeholderTextName = "Full Name";
    QString constant_placeholderTextPhone = "Contact Number";
    QString constant_placeholderTextEmail = "Email";
    QString constant_emptyString = "";
};

#endif // GUI_H
