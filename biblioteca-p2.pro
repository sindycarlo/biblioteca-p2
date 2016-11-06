#-------------------------------------------------
#
# Project created by QtCreator 2016-11-05T11:42:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = biblioteca-p2
TEMPLATE = app


SOURCES += main.cpp \
    MODEL/opera.cpp \
    MODEL/contenitore.cpp \
    MODEL/libro.cpp \
    MODEL/rivista.cpp

HEADERS  += \
    MODEL/opera.h \
    MODEL/contenitore.h \
    MODEL/libro.h \
    MODEL/rivista.h

FORMS    += biblioteca.ui
