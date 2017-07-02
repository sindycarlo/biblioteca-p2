#ifndef C_ADD_UTENTEPRO_H
#define C_ADD_UTENTEPRO_H

#include <QObject>
#include<QApplication>
#include "../VIEW/inserisci_utente.h"
#include "../VIEW/mainwindow.h"
#include "../MODEL/database_utente.h"

class c_add_utente : public QObject
{
    Q_OBJECT
public:
    explicit c_add_utente(amministratore* , inserisci_utente* ,mainWindow* , QObject *parent = 0);

public slots:
    void add_utente(const info_utente&);
    void chiudi_add_utente();

private:
    amministratore* admin;
    inserisci_utente* view;
    mainWindow* mainW;
};

#endif // C_ADD_UTENTEPRO_H
