#ifndef C_MAINWINDOW_H
#define C_MAINWINDOW_H

#include <QObject>
#include <QApplication>

#include "../VIEW/mainwindow.h"
#include "../CONTROLLER/c_add_rivista.h"
#include "../CONTROLLER/c_add_libro.h"
#include "../CONTROLLER/c_add_utentebasic.h"
#include "../CONTROLLER/c_add_utentepro.h"

class C_mainWindow : public QObject
{
    Q_OBJECT
public:
    explicit C_mainWindow(database* ,database_utente*,database_utente_opere*, mainWindow* , QObject *parent=0);

private slots:
    void rimuovi_operaDB(int);
    void rimuovi_utenteDB(int);
    void aggiorna_prestitoDB(int);
    void inserisci_rivistaDB();
    void inserisci_libroDB();
    void inserisci_utentebasicDB();
    void inserisci_utenteproDB();
    void cerca_operaDB(const QString&);
    void cerca_utenteDB(const QString&);

private:
    database* model;
    database_utente* modelutenti;
    database_utente_opere* modelutenteopere;
    mainWindow* view;
};

#endif // C_MAINWINDOW_H
