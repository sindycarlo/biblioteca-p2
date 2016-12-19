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
    MODEL/rivista.cpp \
    MODEL/info_opera.cpp \
    MODEL/database.cpp

HEADERS  += \
    MODEL/opera.h \
    MODEL/contenitore.h \
    MODEL/libro.h \
    MODEL/rivista.h \
    MODEL/info_opera.h \
    MODEL/database.h \
    MODEL/utente.h \
    MODEL/utente_basic.h \
    MODEL/utente_pro.h \
    MODEL/database_utente.h \
    MODEL/info_utente.h

FORMS    += biblioteca.ui

DISTFILES += \
    database.xml
