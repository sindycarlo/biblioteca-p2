#ifndef C_MAINWINDOW_H
#define C_MAINWINDOW_H

#include <QObject>
#include <QApplication>

#include "../VIEW/mainwindow.h"
#include "../CONTROLLER/c_add_rivista.h"
#include "../CONTROLLER/c_add_libro.h"
#include "../CONTROLLER/c_add_utentebasic.h"
#include "../CONTROLLER/c_add_utentepro.h"
#include "../MODEL/amministratore.h"

class C_mainWindow : public QObject
{
    Q_OBJECT
public:
    explicit C_mainWindow(mainWindow* ,amministratore*, QObject *parent=0);

private slots:
    void rimuovi_operaDB(int);
    void rimuovi_utenteDB(int);
    void inserisci_rivistaDB();
    void inserisci_libroDB();
    void inserisci_utentebasicDB();
    void inserisci_utenteproDB();
    void chiudi_mainwindow();

private:


    mainWindow* view;
    amministratore* admin;

    inserisci_Rivista* insR;
    c_add_rivista * c_R;
    inserisci_Libro* insL;
    c_add_libro* c_L;
    inserisci_utentebasic* insUB;
    c_add_utentebasic* c_UB;
    inserisci_utentepro* insUP;
    c_add_utentepro* c_UP;


};

#endif // C_MAINWINDOW_H
