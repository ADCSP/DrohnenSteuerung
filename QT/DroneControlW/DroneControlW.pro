#-------------------------------------------------
#
# Project created by QtCreator 2016-11-22T09:14:42
#
#-------------------------------------------------

QT       += core gui bluetooth

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DroneControlW
TEMPLATE = app
QMAKE_CFLAGS_WARN_OFF -= -Wunused-parameter


SOURCES += main.cpp\
        mainwindow.cpp \
    bluetooth.cpp

FORMS    += mainwindow.ui

HEADERS += \
    mainwindow.h \
    bluetooth.h

RESOURCES += \
    resource.qrc
