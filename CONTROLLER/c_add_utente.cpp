#include "c_add_utente.h"

c_add_utente::c_add_utente(amministratore* a,inserisci_utente* up ,mainWindow* mv, QObject *parent):QObject(parent),admin(a),
                                                                                           view(up),
                                                                                           mainW(mv)

{
    mainW->disabilita_view();
    connect(view,SIGNAL(submitu(const info_utente&)),this,SLOT(add_utente(const info_utente&)));
    connect(view,SIGNAL(chiudi_aggiungi_utente()),this,SLOT(chiudi_add_utente()));
}


void c_add_utente::add_utente(const info_utente& up){
    admin->add_utente(up);
    mainW->aggiorna_vista();
}

void c_add_utente::chiudi_add_utente(){mainW->abilita_view(); delete view; }
