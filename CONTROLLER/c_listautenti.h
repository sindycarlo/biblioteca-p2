#ifndef C_LISTAUTENTI_H
#define C_LISTAUTENTI_H

#include <QObject>

#include "../MODEL/database_utente.h"
#include "../VIEW/listautenti.h"
#include "../MODEL/amministratore.h"
#include "../VIEW/dettagli_utente.h"

class mainWindow;

class C_listautenti : public QObject
{
    Q_OBJECT
public:
    explicit C_listautenti(database*,database_utente*, listautenti*,amministratore*,mainWindow*, QObject *parent = 0);

public slots:
    void visualizza_info_utenti(int);
    void modifica_utente(QString,QString,int);
    void chiudi_dettagli_utente();


private:
    database* model;
    database_utente* modelutenti;
    listautenti* view;
    amministratore* admin;
    dettagli_utente* dett_utente;
    mainWindow* mainview;

};


#endif // C_LISTAUTENTI_H
