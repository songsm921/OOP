#
# QMake build configuration for assignment4 main application
#
#   Executable will be located at ./build/assignment4 after build

include(../assignment4.pri)

TEMPLATE = app
CONFIG += debug c++14
TARGET = assignment4
WARNINGS += -Wall

SOURCES += $$mySRC_DIR/main.cpp \
    mainwindow.cpp \
    player.cpp

QT += widgets
QT += multimedia
QT += core
QT += gui
DESTDIR = $$myDEST_ROOT
LIBS += -L$$DESTDIR/as4 -las4

RESOURCES += \
    image.qrc \
    meldoy.qrc

HEADERS += \
    mainwindow.h \
    player.h

FORMS += \
    mainwindow.ui
