#ifndef LISTALIBRI_H
#define LISTALIBRI_H
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

class listalibri : public listaOp
{
    Q_OBJECT
public:
    explicit listalibri(unsigned int,database*,database_utente*,amministratore*);
    void aggiorna_vista();
    void ricerca(const QString);
    void aggiorna_vista_prestito_libri();
    void costruisci_contenuto();
    unsigned int Getidutente() const;
    amministratore* getadmin() const;
    virtual libro* visualizzaopera(opera*) const;
private:
    unsigned int idutente;
    amministratore* admin;
};
#endif // LISTALIBRI_H
