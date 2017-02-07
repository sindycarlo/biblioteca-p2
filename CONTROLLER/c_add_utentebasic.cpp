#include "c_add_utentebasic.h"

c_add_utentebasic::c_add_utentebasic(database_utente* udb,inserisci_utentebasic* ub ,mainWindow* mv, QObject *parent):QObject(parent),model(udb),
                                                                                           view(ub),
                                                                                           mainW(mv)

{
    mainW->disabilita_view();
    connect(view,SIGNAL(submitub(const info_utente&)),this,SLOT(add_utentebasic(const info_utente&)));
    connect(view,SIGNAL(chiudi_aggiungi_utentebasic()),this,SLOT(chiudi_add_utentebasic()));
}


void c_add_utentebasic::add_utentebasic(const info_utente& ub){
    model->add_utentebasic(ub);
    mainW->aggiorna_vista();
}

void c_add_utentebasic::chiudi_add_utentebasic(){mainW->abilita_view(); delete view; }
