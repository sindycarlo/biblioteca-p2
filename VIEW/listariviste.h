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
#include"../MODEL/contenitore.h"

class listariviste : public listaOp
{
    Q_OBJECT
public:
    explicit listariviste(database*,database_utente*,database_utente_opere*);
    void aggiorna_vista();
    void costruisci_contenuto();
    void build_Nuova(const contenitore<opera> &);
};
#endif // LISTARIVISTE_H
