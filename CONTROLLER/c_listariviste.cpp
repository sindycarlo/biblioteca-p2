#include "c_listariviste.h"
#include "../VIEW/mainwindow.h"

C_listariviste::C_listariviste(database* db,database_utente*udb, listariviste* v,amministratore* a,mainWindow* m,QObject *parent) : QObject(parent),model(db),modelutenti(udb), view(v), admin(a), mainview(m) {
    connect(view,SIGNAL(richiesta_info(int)),this,SLOT(visualizza_info_rivista(int)));

}


void C_listariviste::visualizza_info_rivista(int id){

    view->disabilita_doppio_click();
    mainview->disabilita_view();
    dettagliorivista=new dettagli_Rivista(id,model,modelutenti);
    connect(dettagliorivista,SIGNAL(chiudi_dettagli_opera()),this,SLOT(chiudi_dettaglio_rivista()));
    connect(dettagliorivista,SIGNAL(modifica(QString,QString,int)),this,SLOT(modificaR(QString,QString,int)));
    dettagliorivista->show();


}


void C_listariviste::chiudi_dettaglio_rivista(){

    mainview->abilita_view();
    view->abilita_doppio_click();
    delete dettagliorivista;
}

void C_listariviste::modificaR(QString t, QString a, int id) {
    admin->modifica_rivista(t,a,id);
    view->aggiorna_vista();

}



