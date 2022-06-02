QT -= gui
QT += widgets

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        comboboxdelegate.cpp \
        custinput.cpp \
        customer.cpp \
        customertablemodel.cpp \
        custview.cpp \
        doublespinboxdelegate.cpp \
        filereader.cpp \
        filewriter.cpp \
        listreader.cpp \
        listwriter.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    comboboxdelegate.h \
    custinput.h \
    customer.h \
    customertablemodel.h \
    custview.h \
    doublespinboxdelegate.h \
    filereader.h \
    filewriter.h \
    listreader.h \
    listwriter.h
