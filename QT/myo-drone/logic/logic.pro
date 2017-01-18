! include( ../common.pri ) {
    error("Couldn't find the common.pri file!")
}

HEADERS +=  \
	CuteService.h \
	CommandService.h \
        NavdataService.h \
        VideoService.h \
        ConfigFile.h \
    CVDrone.h

SOURCES +=  \
    	CuteService.cpp \
	CommandService.cpp \
        NavdataService.cpp \
        VideoService.cpp \
        ConfigFile.cpp \
    CVDrone.cpp





win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/command/release/ -lcommand
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/command/debug/ -lcommand

INCLUDEPATH += $$PWD/command
DEPENDPATH += $$PWD/command

win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/command/release/command.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/command/debug/command.lib



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/navdata/release/ -lnavdata
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/navdata/debug/ -lnavdata

INCLUDEPATH += $$PWD/navdata
DEPENDPATH += $$PWD/navdata

win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/navdata/release/navdata.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/navdata/debug/navdata.lib

