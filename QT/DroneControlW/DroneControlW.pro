#-------------------------------------------------
#
# Project created by QtCreator 2016-11-22T09:14:42
#
#-------------------------------------------------

QT       += core network gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TEMPLATE = app
QMAKE_CFLAGS_WARN_OFF -= -Wunused-parameter


SOURCES += main.cpp\
        mainwindow.cpp

FORMS    += mainwindow.ui

HEADERS += \
    mainwindow.h \

INCLUDEPATH +=  ../cv-drone/logic \
                ../cv-drone/logic/command \
                ../cv-drone/logic/navdata

LIBS += -L"../cv-drone/logic" \
        -L"../cv-drone/logic/command" \
        -L"../cv-drone/logic/navdata"



TARGET = DroneControlW
