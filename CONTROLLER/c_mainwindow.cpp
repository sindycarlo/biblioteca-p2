#include "c_mainwindow.h"

C_mainWindow::C_mainWindow(mainWindow* v,amministratore* a, QObject *parent) :  QObject(parent),view(v),admin(a) {
    connect(view,SIGNAL(rimuovi(int)),this,SLOT(rimuovi_operaDB(int)));
    connect(view,SIGNAL(rimuovi_utente(int)),this,SLOT(rimuovi_utenteDB(int)));
    connect(view,SIGNAL(show_inserisci_rivista()),this,SLOT(inserisci_rivistaDB()));
    connect(view,SIGNAL(show_inserisci_libro()),this,SLOT(inserisci_libroDB()));
    connect(view,SIGNAL(show_inserisci_utentebasic()),this,SLOT(inserisci_utentebasicDB()));
    connect(view,SIGNAL(show_inserisci_utentepro()),this,SLOT(inserisci_utenteproDB()));
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

void C_mainWindow::inserisci_utentebasicDB(){
    insUB=new inserisci_utentebasic();
    c_UB=new c_add_utentebasic(admin,insUB,view);
    insUB->show();
}
void C_mainWindow::inserisci_utenteproDB(){
    insUP=new inserisci_utentepro();
    c_UP=new c_add_utentepro(admin,insUP,view);
    insUP->show();
}

void C_mainWindow::chiudi_mainwindow() {
    delete view;
}
