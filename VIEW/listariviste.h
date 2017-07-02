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
#include"../MODEL/contenitore.h"
#include"../MODEL/amministratore.h"

class listariviste : public listaOp
{
    Q_OBJECT
public:
    explicit listariviste(unsigned int,database*,database_utente*,amministratore*);
    void aggiorna_vista();
    void ricerca(const QString);
    void aggiorna_vista_prestito_riviste();
    void costruisci_contenuto();
    virtual rivista* visualizzaopera(opera*) const;
private:
    unsigned int idutente;
    amministratore* admin;
};
#endif // LISTARIVISTE_H
