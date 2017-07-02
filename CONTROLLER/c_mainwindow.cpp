#include "c_mainwindow.h"

C_mainWindow::C_mainWindow(mainWindow* v,amministratore* a, QObject *parent) :  QObject(parent),view(v),admin(a) {
    connect(view,SIGNAL(rimuovi(int)),this,SLOT(rimuovi_operaDB(int)));
    connect(view,SIGNAL(rimuovi_utente(int)),this,SLOT(rimuovi_utenteDB(int)));
    connect(view,SIGNAL(show_inserisci_rivista()),this,SLOT(inserisci_rivistaDB()));
    connect(view,SIGNAL(show_inserisci_libro()),this,SLOT(inserisci_libroDB()));
    connect(view,SIGNAL(show_inserisci_utente()),this,SLOT(inserisci_utenteDB()));
    //chiudi
    connect(view,SIGNAL(chiudi_app()),this,SLOT(chiudi_mainwindow()));
}

void C_mainWindow::rimuovi_operaDB(int ID){
    admin->rimuovi_opera(ID);
    view->aggiorna_vista();
}
void C_mainWindow::rimuovi_utenteDB(int ID){
    admin->rimuovi_utente(ID);
    view->aggiorna_vista();
}

void C_mainWindow::inserisci_rivistaDB(){
    insR=new inserisci_Rivista();
    c_R=new c_add_rivista(admin,insR,view);
    insR->show();


}
void C_mainWindow::inserisci_libroDB(){
    insL=new inserisci_Libro();
    c_L=new c_add_libro(admin,insL,view);
    insL->show();
}

void C_mainWindow::inserisci_utenteDB(){
    insU=new inserisci_utente();
    c_U=new c_add_utente(admin,insU,view);
    insU->show();
}

void C_mainWindow::chiudi_mainwindow() {
    delete view;
}
