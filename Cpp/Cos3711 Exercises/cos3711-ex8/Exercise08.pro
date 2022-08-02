QT -= gui
QT += widgets
QT += xml

RC_ICONS = customers.ico

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        accountcustomer.cpp \
        addressvalidator.cpp \
        cashcustomer.cpp \
        comboboxdelegate.cpp \
        corpcustomer.cpp \
        custinput.cpp \
        customer.cpp \
        customercaretaker.cpp \
        customerclient.cpp \
        customerfactory.cpp \
        customermemento.cpp \
        customertablemodel.cpp \
        custview.cpp \
        doublespinboxdelegate.cpp \
        filereader.cpp \
        filewriter.cpp \
        listxmlreader.cpp \
        listxmlwriter.cpp \
        main.cpp \
        viewer.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    accountcustomer.h \
    addressvalidator.h \
    cashcustomer.h \
    comboboxdelegate.h \
    corpcustomer.h \
    custinput.h \
    customer.h \
    customercaretaker.h \
    customerclient.h \
    customerfactory.h \
    customermemento.h \
    customertablemodel.h \
    custview.h \
    doublespinboxdelegate.h \
    filereader.h \
    filewriter.h \
    listxmlreader.h \
    listxmlwriter.h \
    viewer.h

RESOURCES += \
    customers.qrc

DISTFILES += \
    Images/delete.png
