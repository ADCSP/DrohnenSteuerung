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

LIBS += -llibs/liblogic.a
LIBS += -llibs/libnavdata.a
LIBS += -llibs/libcommand.a

HEADERS += \
    mainwindow.h \
    libs/AdcDataFrameOption.h \
    libs/AltitudeOption.h \
    libs/CALIBCommand.h \
    libs/CksOption.h \
    libs/CommandService.h \
    libs/COMWDGCommand.h \
    libs/CONFIG_IDSCommand.h \
    libs/CONFIGCommand.h \
    libs/ConfigFile.h \
    libs/CuteCommand.h \
    libs/CuteNavdataOption.h \
    libs/CuteService.h \
    libs/CVDrone.h \
    libs/DemoOption.h \
    libs/EulerAnglesOption.h \
    libs/FTRIMCommand.h \
    libs/GamesOption.h \
    libs/GyrosOffsetsOption.h \
    libs/HdvideoStreamOption.h \
    libs/KalmanPressureOption.h \
    libs/MagnetoOption.h \
    libs/NavdataService.h \
    libs/PCMD_MAGCommand.h \
    libs/PCMDCommand.h \
    libs/PhysMeasuresOption.h \
    libs/PMODECommand.h \
    libs/PressureRawOption.h \
    libs/PwmOption.h \
    libs/RawMeasuresOption.h \
    libs/RcReferencesOption.h \
    libs/REFCommand.h \
    libs/ReferencesOption.h \
    libs/TimeOption.h \
    libs/TrackersSendOption.h \
    libs/TrimsOption.h \
    libs/VideoService.h \
    libs/VideoStreamOption.h \
    libs/VisionDetectOption.h \
    libs/VisionOfOption.h \
    libs/VisionOption.h \
    libs/VisionPerfOption.h \
    libs/VisionRawOption.h \
    libs/WatchdogOption.h \
    libs/WifiOption.h \
    libs/WindOption.h \
    libs/Zimmu3000Option.h
