#ifndef C_HOMEWINDOW_H
#define C_HOMEWINDOW_H

#include <QObject>
#include <QApplication>

#include "../VIEW/homewindow.h"
#include "../CONTROLLER/c_mainwindow.h"
#include "../CONTROLLER/c_utentewindow.h"
#include "../MODEL/amministratore.h"
class c_homewindow : public QObject
{
    Q_OBJECT
public:
    explicit c_homewindow(database*,database_utente*,database_utente_opere*,homewindow* ,amministratore*, QObject *parent=0);

private slots:
    void accedi_admin();
    void accedi_utente(QString,QString);


private:

    database* model;
    database_utente* modelutenti;
    database_utente_opere* modelop;
    homewindow* view;
    mainWindow* viewmain;
    amministratore* admin;
    utenteWindow* viewutente;
    C_mainWindow* c_main;
    c_utentewindow* c_utente;
};




#endif // C_HOMEWINDOW_H
