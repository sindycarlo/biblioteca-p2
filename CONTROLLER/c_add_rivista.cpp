#include "c_add_rivista.h"
#include<QApplication>
c_add_rivista::c_add_rivista(amministratore* a,inserisci_Rivista* v ,mainWindow* mv, QObject *parent):QObject(parent),admin(a),
                                                                                                 view(v),
                                                                                                 mainW(mv)

{
    mainW->disabilita_view();
    connect(view,SIGNAL(submitR(const info_opera&)),this,SLOT(add(const info_opera&)));
    connect(view,SIGNAL(chiudi_aggiungi_rivista()),this,SLOT(chiudi_add_rivista()));
}


void c_add_rivista::add(const info_opera& op){
    admin->add_rivista(op);
    mainW->aggiorna_vista();
}

void c_add_rivista::chiudi_add_rivista(){mainW->abilita_view(); delete view;}


