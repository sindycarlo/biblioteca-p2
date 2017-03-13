#include "c_add_utentepro.h"

c_add_utentepro::c_add_utentepro(amministratore* a,inserisci_utentepro* up ,mainWindow* mv, QObject *parent):QObject(parent),admin(a),
                                                                                           view(up),
                                                                                           mainW(mv)

{
    mainW->disabilita_view();
    connect(view,SIGNAL(submitup(const info_utente&)),this,SLOT(add_utentepro(const info_utente&)));
    connect(view,SIGNAL(chiudi_aggiungi_utentepro()),this,SLOT(chiudi_add_utentepro()));
}


void c_add_utentepro::add_utentepro(const info_utente& up){
    admin->add_utente_pro(up);
    mainW->aggiorna_vista();
}

void c_add_utentepro::chiudi_add_utentepro(){mainW->abilita_view(); delete view; }
