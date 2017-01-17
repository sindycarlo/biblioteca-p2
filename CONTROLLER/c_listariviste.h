#ifndef C_LISTARIVISTE_H
#define C_LISTARIVISTE_H
#include <QObject>

#include "../MODEL/database.h"
#include "../VIEW/dettagli_rivista.h"
#include "../VIEW/listariviste.h"


class C_listariviste : public QObject
{
    Q_OBJECT
public:
    explicit C_listariviste(database*,database_utente*,database_utente_opere*, listariviste*, QObject *parent = 0);

public slots:
    void visualizza_info_rivista(int);
    void modificaR(QString,QString,int);
    void chiudi_dettaglio_rivista();

private:
    database* model;
    database_utente* modelutenti;
    database_utente_opere* modelutenteopere;
    dettagli_Rivista* dettagliorivista;
    listariviste* view;

};

#endif // C_LISTARIVISTE_H
