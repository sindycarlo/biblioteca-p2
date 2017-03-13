#include "c_add_libro.h"

c_add_libro::c_add_libro(amministratore* a,inserisci_Libro* v ,mainWindow* mv, QObject *parent):
                                                                                           QObject(parent),admin(a),
                                                                                           view(v),mainW(mv)
{
    mainW->disabilita_view();
    connect(view,SIGNAL(submitL(const info_opera&)),this,SLOT(add(const info_opera&)));
    connect(view,SIGNAL(chiudi_aggiungi_Libro()),this,SLOT(chiudi_add_libro()));
}


void c_add_libro::add(const info_opera& op){
    admin->add_libro(op);
    mainW->aggiorna_vista();
}

void c_add_libro::chiudi_add_libro(){mainW->abilita_view(); delete view;}
