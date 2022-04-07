#-------------------------------------------------
#
# Project created by QtCreator 2022-04-06T16:17:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = btcAddress
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    api.cpp

HEADERS  += widget.h \
    api.h

FORMS    += widget.ui
