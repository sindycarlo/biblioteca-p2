#ifndef C_ADD_UTENTEPRO_H
#define C_ADD_UTENTEPRO_H

#include <QObject>
#include<QApplication>
#include "../VIEW/inserisci_utentepro.h"
#include "../VIEW/mainwindow.h"
#include "../MODEL/database_utente.h"

class c_add_utentepro : public QObject
{
    Q_OBJECT
public:
    explicit c_add_utentepro(amministratore* , inserisci_utentepro* ,mainWindow* , QObject *parent = 0);

public slots:
    void add_utentepro(const info_utente&);
    void chiudi_add_utentepro();

private:
    amministratore* admin;
    inserisci_utentepro* view;
    mainWindow* mainW;
};

#endif // C_ADD_UTENTEPRO_H
