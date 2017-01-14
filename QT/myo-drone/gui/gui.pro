! include( ../common.pri ) {
    error("Couldn't find the common.pri file!")
}

QMAKE_CFLAGS_WARN_OFF -= -Wunused-parameter

QT += gui widgets


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


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../logic/release/ -llogic
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../logic/debug/ -llogic

INCLUDEPATH += $$PWD/../logic
DEPENDPATH += $$PWD/../logic

win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../logic/release/logic.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../logic/debug/logic.lib



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../logic/command/release/ -lcommand
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../logic/command/debug/ -lcommand

INCLUDEPATH += $$PWD/../logic/command
DEPENDPATH += $$PWD/../logic/command

win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../logic/command/release/command.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../logic/command/debug/command.lib



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../logic/navdata/release/ -lnavdata
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../logic/navdata/debug/ -lnavdata

INCLUDEPATH += $$PWD/../logic/navdata
DEPENDPATH += $$PWD/../logic/navdata

win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../logic/navdata/release/navdata.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../logic/navdata/debug/navdata.lib

