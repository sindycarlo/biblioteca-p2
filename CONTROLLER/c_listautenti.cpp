#include "c_listautenti.h"

C_listautenti::C_listautenti(database_utente* udb, listautenti* lu,QObject *parent) : model(udb), view(lu), QObject(parent) {
    connect(view,SIGNAL(richiesta_info_utenti(int)),this,SLOT(visualizza_info_utenti(int)));


}

void C_listautenti::visualizza_info_utenti(int id){

    view->disabilita_doppio_click();

    dettaglio=new dettagli_Rivista(id,model,modelutenti,modelutenteopere);
    connect(dettagliorivista,SIGNAL(chiudi_dettagli_opera()),this,SLOT(chiudi_dettaglio_rivista()));
    connect(dettagliorivista,SIGNAL(modifica(QString,QString,int)),this,SLOT(modificaR(QString,QString,int)));
    dettagliorivista->show();


}


void C_listautenti::chiudi_dettaglio_utente(){
    view->abilita_doppio_click();
    delete dettaglioutente;
}
