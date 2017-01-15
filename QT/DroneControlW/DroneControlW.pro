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
    myodevicelistener.cpp

FORMS    += mainwindow.ui

HEADERS += \
    mainwindow.h \
    myodevicelistener.h \
    MyoLibrary/include/myo/cxx/detail/ThrowOnError.hpp \
    MyoLibrary/include/myo/cxx/impl/Hub_impl.hpp \
    MyoLibrary/include/myo/cxx/impl/Myo_impl.hpp \
    MyoLibrary/include/myo/cxx/impl/Pose_impl.hpp \
    MyoLibrary/include/myo/cxx/DeviceListener.hpp \
    MyoLibrary/include/myo/cxx/Hub.hpp \
    MyoLibrary/include/myo/cxx/Myo.hpp \
    MyoLibrary/include/myo/cxx/Pose.hpp \
    MyoLibrary/include/myo/cxx/Quaternion.hpp \
    MyoLibrary/include/myo/cxx/Vector3.hpp \
    MyoLibrary/include/myo/libmyo/detail/visibility.h \
    MyoLibrary/include/myo/libmyo.h \
    MyoLibrary/include/myo/myo.hpp

RESOURCES += \
    resource.qrc


INCLUDEPATH += "MyoLibrary/include/"
DEPENDPATH += "MyoLibrary/bin/myo32.dll"

win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/MyoLibrary/lib/ -lmyo32
else:unix: LIBS += -L$$PWD/MyoLibrary/lib/ -lmyo32

INCLUDEPATH += $$PWD/MyoLibrary/include
DEPENDPATH += $$PWD/MyoLibrary/include
