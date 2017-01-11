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
#include"../MODEL/contenitore.h"

class listalibri : public listaOp
{
    Q_OBJECT
public:
    explicit listalibri(database*,database_utente*,database_utente_opere*);
    void aggiorna_vista();
    void costruisci_contenuto();
    void build_Nuova(const contenitore<opera> &);
};
#endif // LISTALIBRI_H
