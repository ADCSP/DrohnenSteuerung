! include( ../common.pri ) {
    error("Couldn't find the common.pri file!")
}

QMAKE_CFLAGS_WARN_OFF -= -Wunused-parameter

QT += gui widgets

INCLUDEPATH += "../logic"
INCLUDEPATH += "../logic/navdata"
INCLUDEPATH += "../logic/command"
INCLUDEPATH += "../logic/video"

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../logic/MyoLibrary/lib/ -lmyo32

INCLUDEPATH += $$PWD/../logic/MyoLibrary/include
DEPENDPATH += $$PWD/../logic/MyoLibrary/include


SOURCES +=\
    CommandDebugWindow.cpp \
    MainWindow.cpp \
    NavdataDebugWindow.cpp \
    ControlWindow.cpp

HEADERS  += \
    CommandDebugWindow.h \
    MainWindow.h \
    NavdataDebugWindow.h \
    ControlWindow.h

FORMS    += \
    CommandDebugWindow.ui \
    MainWindow.ui \
    NavdataDebugWindow.ui \
    ControlWindow.ui

RESOURCES += \
    icons.qrc
