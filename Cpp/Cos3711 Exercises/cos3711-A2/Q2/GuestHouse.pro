QT       += core \
    widgets \
    xml

QT       -= gui

TARGET = GuestHouse
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    filewriter.cpp \
    gui.cpp \
    person.cpp \
    booking.cpp \
    readfromxml.cpp \
    single.cpp \
    sharing.cpp \
    bookinglist.cpp \
    writetoxml.cpp

HEADERS += \
    filewriter.h \
    gui.h \
    person.h \
    booking.h \
    readfromxml.h \
    single.h \
    sharing.h \
    bookinglist.h \
    writetoxml.h
