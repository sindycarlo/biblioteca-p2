#ifndef LISTARIVISTE_H
#define LISTARIVISTE_H
#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QAbstractItemView>
#include <QVBoxLayout>

#include "listaop.h"
#include"../MODEL/database.h"
#include"../MODEL/database_utente.h"
#include"../MODEL/database_utente_opere.h"
#include"../MODEL/contenitore.h"

class listariviste : public listaOp
{
    Q_OBJECT
public:
    explicit listariviste(unsigned int,database*,database_utente*,database_utente_opere*);
    void aggiorna_vista();
    void aggiorna_vista_prestito_riviste();
    void costruisci_contenuto();
    unsigned int Getidutente() const;
    virtual rivista* visualizzaopera(opera*) const;
private:
    unsigned int idutente;
};
#endif // LISTARIVISTE_H
