#include "c_add_utentepro.h"

c_add_utentepro::c_add_utentepro(database_utente* udb,inserisci_utentepro* up ,mainWindow* mv, QObject *parent):QObject(parent),model(udb),
                                                                                           view(up),
                                                                                           mainW(mv)

{
    connect(view,SIGNAL(submitup(const info_utente&)),this,SLOT(add_utentepro(const info_utente&)));
    connect(view,SIGNAL(chiudi_aggiungi_utentepro()),this,SLOT(chiudi_add_utentepro()));
}


void c_add_utentepro::add_utentepro(const info_utente& up){
    model->add_utentepro(up);
    mainW->aggiorna_vista();
}

void c_add_utentepro::chiudi_add_utentepro(){ delete view; }
