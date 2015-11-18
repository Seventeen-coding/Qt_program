#-------------------------------------------------
#
# Project created by QtCreator 2015-11-12T10:34:37
#
#-------------------------------------------------


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = helloworld
TEMPLATE = lib

DEFINES += HELLOWORLD_LIBRARY

SOURCES += helloworld.cpp \
    dialog.cpp

HEADERS += helloworld.h\
        helloworld_global.h \
    dialog.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    dialog.ui
