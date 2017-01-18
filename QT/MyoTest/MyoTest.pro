QT += core
QT -= gui

CONFIG += c++11

TARGET = MyoTest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


HEADERS += \
    ../../Desktop/myo-sdk-win-0.9.0/include/myo/libmyo.h \
    ../../Desktop/myo-sdk-win-0.9.0/include/myo/myo.hpp \
    ../../Desktop/myo-sdk-win-0.9.0/include/myo/cxx/DeviceListener.hpp \
    ../../Desktop/myo-sdk-win-0.9.0/include/myo/cxx/Hub.hpp \
    ../../Desktop/myo-sdk-win-0.9.0/include/myo/cxx/Myo.hpp \
    ../../Desktop/myo-sdk-win-0.9.0/include/myo/cxx/Pose.hpp \
    ../../Desktop/myo-sdk-win-0.9.0/include/myo/cxx/Quaternion.hpp \
    ../../Desktop/myo-sdk-win-0.9.0/include/myo/cxx/Vector3.hpp

LIBS += "C:/Users/Andi/Desktop/myo-sdk-win-0.9.0/bin/myo32.dll"
LIBS += "C:/Users/Andi/Desktop/myo-sdk-win-0.9.0/lib/myo32.lib"
INCLUDEPATH +="C:/Users/Andi/Desktop/myo-sdk-win-0.9.0/include/"
