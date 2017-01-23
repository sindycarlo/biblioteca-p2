#include "c_listalibri.h"

C_listalibri::C_listalibri(database* db,database_utente* udb, database_utente_opere* uodb, listalibri* v,QObject *parent) : model(db),modelutenti(udb),modelutenteopere(uodb), view(v), QObject(parent) {
    connect(view,SIGNAL(richiesta_info(int)),this,SLOT(visualizza_info_libro(int)));
}

void C_listalibri::visualizza_info_libro(int id){

    view->disabilita_doppio_click();
    dettagliolibro=new dettagli_Libro(id,model,modelutenti,modelutenteopere);
    connect(dettagliolibro,SIGNAL(chiudi_dettagli_opera()),this,SLOT(chiudi_dettagli_libro()));
    connect(dettagliolibro,SIGNAL(modifica(QString,QString,int)),this,SLOT(modificaL(QString,QString,int)));
    dettagliolibro->show();

}


void C_listalibri::chiudi_dettagli_libro(){
    view->abilita_doppio_click();
    dettagliolibro->close();
    delete dettagliolibro;
}

void C_listalibri::modificaL(QString t, QString a, int id) {
    opera* op=model->trova_opera(id);
    libro* l=dynamic_cast<libro*>(op);
    rivista* r=dynamic_cast<rivista*>(op);
    if(l)
    {
        l->SetTitolo(t);
        l->SetAutore(a);
    }
    else if(r)
    {
        r->SetTitolo(t);
        r->SetAnnouscita(a.toInt());
    }
    view->aggiorna_vista();
}
