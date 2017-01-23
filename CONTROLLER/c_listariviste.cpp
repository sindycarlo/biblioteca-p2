#include "c_listariviste.h"

C_listariviste::C_listariviste(database* db,database_utente*udb,database_utente_opere* uodb, listariviste* v,QObject *parent) : model(db),modelutenti(udb),modelutenteopere(uodb), view(v), QObject(parent) {
    connect(view,SIGNAL(richiesta_info(int)),this,SLOT(visualizza_info_rivista(int)));

}


void C_listariviste::visualizza_info_rivista(int id){

    view->disabilita_doppio_click();
    dettagliorivista=new dettagli_Rivista(id,model,modelutenti,modelutenteopere);
    connect(dettagliorivista,SIGNAL(chiudi_dettagli_opera()),this,SLOT(chiudi_dettaglio_rivista()));
    connect(dettagliorivista,SIGNAL(modifica(QString,QString,int)),this,SLOT(modificaR(QString,QString,int)));
    dettagliorivista->show();


}


void C_listariviste::chiudi_dettaglio_rivista(){
    view->abilita_doppio_click();
    delete dettagliorivista;
}

void C_listariviste::modificaR(QString t, QString a, int id) {
    //ATTENZIONE!!
    //SONO COSTRETTO A FARE IL DYNAMIC_CAST IN QUANTO HO SOLO UN PUNTATORE AD OPERA E NON SO
    //SE UN LIBRO OPPURE UNA RIVISTA. INOLTRE DEVO FARE UNA MODIFICA A QUELL'OPERA; BEN DIVERSO CHE INSERIRLA.
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



