#ifndef C_ADD_UTENTEBASIC_H
#define C_ADD_UTENTEBASIC_H

#include <QObject>
#include<QApplication>
#include "../VIEW/inserisci_utentebasic.h"
#include "../VIEW/mainwindow.h"
#include "../MODEL/database_utente.h"

class c_add_utentebasic : public QObject
{
    Q_OBJECT
public:
    explicit c_add_utentebasic(database_utente* , inserisci_utentebasic* ,mainWindow* , QObject *parent = 0);

public slots:
    void add_utentebasic(const info_utente&);
    void chiudi_add_utentebasic();

private:
    database_utente* model;
    inserisci_utentebasic* view;
    mainWindow* mainW;
};

#endif // C_ADD_UTENTEBASIC_H
