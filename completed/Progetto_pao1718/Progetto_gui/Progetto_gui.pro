#-------------------------------------------------
#
# Project created by QtCreator 2018-09-06T17:03:54
#
#-------------------------------------------------

QT       += core gui

QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Progetto_gui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        kalkwidget.cpp \
    component.cpp \
    basecomponent.cpp \
    centralprocessingunit.cpp \
    graphicsprocessingunit.cpp \
    randomaccessmemory.cpp \
    secondarymemory.cpp \
    screen.cpp \
    computer.cpp \
    tower.cpp \
    laptop.cpp \
    smartphone.cpp \
    inputterminal.cpp

HEADERS += \
        kalkwidget.h \
    component.h \
    basecomponent.h \
    centralprocessingunit.h \
    graphicsprocessingunit.h \
    randomaccessmemory.h \
    secondarymemory.h \
    screen.h \
    computer.h \
    tower.h \
    laptop.h \
    smartphone.h \
    inputterminal.h

FORMS += \
        kalkwidget.ui
