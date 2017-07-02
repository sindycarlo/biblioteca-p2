#ifndef C_LISTARIVISTE_H
#define C_LISTARIVISTE_H
#include <QObject>
#include "../MODEL/amministratore.h"
#include "../MODEL/database.h"
#include "../VIEW/dettagli_rivista.h"
#include "../VIEW/listariviste.h"

class mainWindow;

class C_listariviste : public QObject
{
    Q_OBJECT
public:
    explicit C_listariviste(database*,database_utente*, listariviste*,amministratore*,mainWindow*, QObject *parent = 0);

public slots:
    void visualizza_info_rivista(int);
    void modificaR(QString,QString,int);
    void chiudi_dettaglio_rivista();

private:
    database* model;
    database_utente* modelutenti;
    listariviste* view;
    amministratore* admin;
    dettagli_Rivista* dettagliorivista;
    mainWindow* mainview;

};

#endif // C_LISTARIVISTE_H

