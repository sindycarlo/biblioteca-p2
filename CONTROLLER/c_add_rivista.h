#ifndef C_ADD_RIVISTA_H
#define C_ADD_RIVISTA_H

#include <QObject>
#include <QWidget>
#include "../MODEL/database.h"
#include "../VIEW/inserisci_rivista.h"
#include "../VIEW/mainwindow.h"

class c_add_rivista : public QObject
{
    Q_OBJECT
public:
    explicit c_add_rivista(amministratore*, inserisci_Rivista*,mainWindow*,QObject* parent =0);

private slots:
    void add(const info_opera&);
    void chiudi_add_rivista();

private:
    amministratore* admin;
    inserisci_Rivista* view;
    mainWindow* mainW;
};

#endif // C_ADD_RIVISTA_H
