#-------------------------------------------------
#
# Project created by QtCreator 2016-11-22T09:14:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DroneControlW
TEMPLATE = app
QMAKE_CFLAGS_WARN_OFF -= -Wunused-parameter


SOURCES += main.cpp\
        mainwindow.cpp

FORMS    += mainwindow.ui

HEADERS += \
    mainwindow.h \
    libs/header/command/CALIBCommand.h \
    libs/header/command/COMWDGCommand.h \
    libs/header/command/CONFIG_IDSCommand.h \
    libs/header/command/CONFIGCommand.h \
    libs/header/command/CuteCommand.h \
    libs/header/command/FTRIMCommand.h \
    libs/header/command/PCMD_MAGCommand.h \
    libs/header/command/PCMDCommand.h \
    libs/header/command/PMODECommand.h \
    libs/header/command/REFCommand.h \
    libs/header/logic/CommandService.h \
    libs/header/logic/ConfigFile.h \
    libs/header/logic/CuteService.h \
    libs/header/logic/CVDrone.h \
    libs/header/logic/NavdataService.h \
    libs/header/logic/VideoService.h \
    libs/header/navdata/AdcDataFrameOption.h \
    libs/header/navdata/AltitudeOption.h \
    libs/header/navdata/CksOption.h \
    libs/header/navdata/CuteNavdataOption.h \
    libs/header/navdata/DemoOption.h \
    libs/header/navdata/EulerAnglesOption.h \
    libs/header/navdata/GamesOption.h \
    libs/header/navdata/GyrosOffsetsOption.h \
    libs/header/navdata/HdvideoStreamOption.h \
    libs/header/navdata/KalmanPressureOption.h \
    libs/header/navdata/MagnetoOption.h \
    libs/header/navdata/PhysMeasuresOption.h \
    libs/header/navdata/PressureRawOption.h \
    libs/header/navdata/PwmOption.h \
    libs/header/navdata/RawMeasuresOption.h \
    libs/header/navdata/RcReferencesOption.h \
    libs/header/navdata/ReferencesOption.h \
    libs/header/navdata/TimeOption.h \
    libs/header/navdata/TrackersSendOption.h \
    libs/header/navdata/TrimsOption.h \
    libs/header/navdata/VideoStreamOption.h \
    libs/header/navdata/VisionDetectOption.h \
    libs/header/navdata/VisionOfOption.h \
    libs/header/navdata/VisionOption.h \
    libs/header/navdata/VisionPerfOption.h \
    libs/header/navdata/VisionRawOption.h \
    libs/header/navdata/WatchdogOption.h \
    libs/header/navdata/WifiOption.h \
    libs/header/navdata/WindOption.h \
    libs/header/navdata/Zimmu3000Option.h

INCLUDEPATH += ../libs/header/command
INCLUDEPATH += ../libs/header/logic
INCLUDEPATH += ../libs/header/navdata



LIBS += -L../libs -llibcommand
LIBS += -L../libs -lliblogic
LIBS += -L../libs -llibnavdata

