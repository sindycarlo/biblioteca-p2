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
    virtual void aggiorna_vista();
    virtual void ricerca(const QString);
    void aggiornalibri();
    virtual void costruisci_contenuto();
    virtual libro* visualizzaopera(opera*) const;
private:
    unsigned int identificativo;
    amministratore* admin;
};
#endif // LISTALIBRI_H
