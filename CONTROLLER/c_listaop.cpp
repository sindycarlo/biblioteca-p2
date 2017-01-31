#include "c_listaop.h"

C_listaop::C_listaop(database* db,database_utente* udb,database_utente_opere* uodb, listaOp* v,QObject *parent) : model(db),modelutente(udb),modelopere(uodb), view(v), QObject(parent) {
    connect(view,SIGNAL(richiesta_info(int)),this,SLOT(visualizza_info(int)));


}

void C_listaop::visualizza_info(int id){

    view->disabilita_doppio_click();

    if(dynamic_cast<rivista*>(model->trova_opera(id)))
    {
        dett_rivista=new dettagli_Rivista(id,model,modelutente,modelopere);
        connect(dett_rivista,SIGNAL(chiudi_dettagli_opera()),this,SLOT(chiudi_dettagli_rivista()));
        connect(dett_rivista,SIGNAL(modifica(QString,QString,int)),this,SLOT(modificaR(QString,QString,int));
        dett_rivista->show();
    }
    else if(dynamic_cast<libro*>(model->trova_opera(id)))
    {
        dett_libro=new Dettagli_Libro(id,model,modelutente,modelopere);
        connect(dett_libro,SIGNAL(chiudi_dettagli_opera()),this,SLOT(chiudi_dettagli_libro()));
        connect(dett_rivista,SIGNAL(modifica(QString,QString,int)),this,SLOT(modificaL(QString,QString,int));
        dett_libro->show();
    }
}

void C_listaop::chiudi_dettagli_libro(){
    view->abilita_doppio_click();
    delete dett_libro;
}

void C_listaop::chiudi_dettagli_rivista(){
    view->abilita_doppio_click();
    delete dett_rivista;
}

void C_listaop::modificaL(QString t, QString a, int id) {
    opera* op=model->trova_opera(id);
    libro* l=dynamic_cast<libro*>(op);
    if(l)
    {
        l->SetTitolo(t);
        l->SetAutore(a);
    }
    view->aggiorna_vista();
}


void C_listaop::modificaR(QString t, QString au, int id) {
    opera* op=model->trova_opera(id);
    rivista* r=dynamic_cast<rivista*>(op);
    if(r)
    {
        r->SetTitolo(t);
        r->SetAutore(au);
    }
    view->aggiorna_vista();
}


