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
    MODEL/database.cpp \
    MODEL/utente.cpp \
    MODEL/utente_basic.cpp \
    MODEL/utente_pro.cpp \
    MODEL/info_utente.cpp \
    MODEL/database_utente.cpp \
    CONTROLLER/c_add_libro.cpp \
    CONTROLLER/c_add_rivista.cpp \
    CONTROLLER/c_mainwindow.cpp \
    VIEW/inserisci_libro.cpp \
    VIEW/inserisci_rivista.cpp \
    VIEW/mainwindow.cpp \
    VIEW/widget_padre.cpp \
    VIEW/listaop.cpp \
    CONTROLLER/c_listautenti.cpp \
    VIEW/lista_utenti.cpp \
    VIEW/homewindow.cpp \
    CONTROLLER/c_homewindow.cpp \
    CONTROLLER/c_utentewindow.cpp \
    VIEW/utentewindow.cpp \
    VIEW/listalibri.cpp \
    VIEW/listariviste.cpp \
    VIEW/dettagli_opera.cpp \
    VIEW/dettagli_libro.cpp \
    VIEW/dettagli_rivista.cpp \
    VIEW/dettagli_utente.cpp \
    CONTROLLER/c_listalibri.cpp \
    CONTROLLER/c_listariviste.cpp \
    MODEL/amministratore.cpp \
    CONTROLLER/c_add_utente.cpp \
    VIEW/inserisci_utente.cpp

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
    MODEL/info_utente.h \
    CONTROLLER/c_add_libro.h \
    CONTROLLER/c_add_rivista.h \
    CONTROLLER/c_mainwindow.h \
    VIEW/inserisci_libro.h \
    VIEW/inserisci_rivista.h \
    VIEW/mainwindow.h \
    VIEW/widget_padre.h \
    VIEW/listaop.h \
    CONTROLLER/c_listautenti.h \
    VIEW/listautenti.h \
    VIEW/homewindow.h \
    CONTROLLER/c_homewindow.h \
    CONTROLLER/c_utentewindow.h \
    VIEW/utentewindow.h \
    VIEW/listalibri.h \
    VIEW/listariviste.h \
    VIEW/dettagli_opera.h \
    VIEW/dettagli_libro.h \
    VIEW/dettagli_rivista.h \
    VIEW/dettagli_utente.h \
    CONTROLLER/c_listalibri.h \
    CONTROLLER/c_listariviste.h \
    MODEL/amministratore.h \
    CONTROLLER/c_add_utente.h \
    VIEW/inserisci_utente.h

FORMS    += biblioteca.ui

DISTFILES += \
    database.xml \
    databaseutenti.xml \
