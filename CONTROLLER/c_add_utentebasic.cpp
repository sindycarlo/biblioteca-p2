#include "c_add_utentebasic.h"

c_add_utentebasic::c_add_utentebasic(amministratore* a,inserisci_utentebasic* ub ,mainWindow* mv, QObject *parent):QObject(parent),admin(a),
                                                                                           view(ub),
                                                                                           mainW(mv)

{
    mainW->disabilita_view();
    connect(view,SIGNAL(submitub(const info_utente&)),this,SLOT(add_utentebasic(const info_utente&)));
    connect(view,SIGNAL(chiudi_aggiungi_utentebasic()),this,SLOT(chiudi_add_utentebasic()));
}


void c_add_utentebasic::add_utentebasic(const info_utente& ub){
    admin->add_utente_basic(ub);
    mainW->aggiorna_vista();
}

void c_add_utentebasic::chiudi_add_utentebasic(){mainW->abilita_view(); delete view; }
