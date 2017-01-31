#ifndef C_LISTAOP_H
#define C_LISTAOP_H

#include <QObject>

#include "../MODEL/database.h"
#include "../VIEW/listaop.h"
#include "../VIEW/dettagli_rivista.h"
#include "../VIEW/dettagli_libro.h"

class C_listaop : public QObject
{
    Q_OBJECT
public:
    explicit C_listaop(database*,database_utente*,database_utente_opere*, listaOp*, QObject *parent = 0);

public slots:
    void visualizza_info(int);
    void modificaL(QString,QString,int);
    void modificaR(QString,QString,int);
    void chiudi_dettagli_libro();
    void chiudi_dettagli_rivista();
private:
    database* model;
    database_utente* modelutente;
    database_utente_opere* modelopere;
    listaOp* view;
    dettagli_Libro* dett_libro;
    dettagli_Rivista* dett_rivista;
};

#endif // C_LISTAOP_H
