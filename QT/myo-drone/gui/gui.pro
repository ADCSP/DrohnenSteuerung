! include( ../common.pri ) {
    error("Couldn't find the common.pri file!")
}

QMAKE_CFLAGS_WARN_OFF -= -Wunused-parameter

QT += gui widgets

INCLUDEPATH += "../logic"
INCLUDEPATH += "../logic/navdata"
INCLUDEPATH += "../logic/command"

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
