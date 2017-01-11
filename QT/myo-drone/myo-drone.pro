TEMPLATE = subdirs

SUBDIRS +=  logic \
            logic/command \
            logic/navdata \
            logic/video \
            gui

SUBDIRS += build

CONFIG += ordered
