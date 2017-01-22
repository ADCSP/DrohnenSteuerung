! include( ../common.pri ) {
    error("Couldn't find the common.pri file!")
}

QMAKE_CFLAGS_WARN_OFF -= -Wunused-parameter

QT += gui widgets


INCLUDEPATH += "../logic"
INCLUDEPATH += "../logic/navdata"
INCLUDEPATH += "../logic/command"




win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../gui/MyoLibrary/lib/ -lmyo32
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../gui/MyoLibrary/lib/ -lmyo32

INCLUDEPATH += $$PWD/../gui/MyoLibrary/include
DEPENDPATH += $$PWD/../gui/MyoLibrary/include


SOURCES +=\
        CommandDebugWindow.cpp \
        MainWindow.cpp \
        NavdataDebugWindow.cpp \
        myodevicelistener.cpp \
        ControlWindow.cpp \
    myothraed.cpp \
    threadhandler.cpp \
    MyoSignalBridge.cpp

HEADERS  += \
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
        CommandDebugWindow.h \
        MainWindow.h \
        NavdataDebugWindow.h \
        ControlWindow.h \
    myothraed.h \
    threadhandler.h \
    MyoSignalBridge.h


FORMS    += \
    CommandDebugWindow.ui \
    MainWindow.ui \
    NavdataDebugWindow.ui \
    ControlWindow.ui

RESOURCES += \
    icons.qrc
