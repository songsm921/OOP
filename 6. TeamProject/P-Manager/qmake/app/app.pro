include(../P-Manager.pri)

TEMPLATE = app
CONFIG += debug c++14
TARGET = P-Manager
WARNINGS += -Wall

SOURCES += \
        $$mySRC_DIR/main.cpp \
        $$mySRC_DIR/widgets/mainwindow.cpp \
        $$mySRC_DIR/committee.cpp \
        $$mySRC_DIR/courses.cpp \
        $$mySRC_DIR/coursewindow.cpp \
        $$mySRC_DIR/member.cpp \
        $$mySRC_DIR/access.cpp \
        $$mySRC_DIR/login.cpp \
        $$mySRC_DIR/extra.cpp \
        $$mySRC_DIR/municipality.cpp \
        $$mySRC_DIR/extra_widget.cpp \
        $$mySRC_DIR/club.cpp \
        $$mySRC_DIR/portfolio.cpp \



HEADERS += \
        $$myINCLUDE_DIR/widgets/mainwindow.h \
        $$myINCLUDE_DIR/committee.h \
        $$myINCLUDE_DIR/courses.h \
        $$myINCLUDE_DIR/coursewindow.h \
        $$myINCLUDE_DIR/member.h \
        $$myINCLUDE_DIR/access.h\
        $$myINCLUDE_DIR/login.h\
        $$myINCLUDE_DIR/extra.h \
        $$myINCLUDE_DIR/municipality.h \
        $$myINCLUDE_DIR/extra_widget.h \
        $$myINCLUDE_DIR/club.h \
        $$myINCLUDE_DIR/portfolio.h \


QT += widgets core

DESTDIR = $$myDEST_ROOT

FORMS += mainwindow.ui \
    club.ui \
    committee.ui \
    course.ui \
    extra.ui \
    municipality.ui \
    club.ui \
    extra.ui \
    course.ui \
    portfolio.ui \
    access.ui \
    login.ui \

RESOURCES += \
    image.qrc
