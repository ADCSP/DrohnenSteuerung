TEMPLATE = app

QMAKE_CFLAGS_WARN_OFF -= -Wunused-parameter

QT += core network gui widgets
CONFIG += c++11

CONFIG += link_pkgconfig

SOURCES += main.cpp \ 
           provision.cpp

INCLUDEPATH +=  ../logic \
                ../logic/command \
                ../logic/navdata \
                ../gui

LIBS += -L"../logic" \
        -L"../logic/command" \
        -L"../logic/navdata" \
        -L"../gui" \
        -llogic -lcommand -lnavdata -lgui


TARGET = ../myo-drone
