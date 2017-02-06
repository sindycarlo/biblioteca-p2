#include "c_listautenti.h"
#include "../VIEW/mainwindow.h"

C_listautenti::C_listautenti(database *db, database_utente* udb, database_utente_opere *uodb, listautenti* lu,mainWindow*m, QObject *parent) : QObject(parent),model(db), modelutenti(udb),modelutenteopere(uodb), view(lu),mainview(m){
    connect(view,SIGNAL(richiesta_info_utenti(int)),this,SLOT(visualizza_info_utenti(int)));


}


void C_listautenti::visualizza_info_utenti(int id){

        view->disabilita_doppio_click_utenti();
        mainview->disabilita_view();
        dett_utente=new dettagli_utente(id,model,modelutenti,modelutenteopere);
        connect(dett_utente,SIGNAL(chiudi_dettagli_utente()),this,SLOT(chiudi_dettagli_utente()));
        connect(dett_utente,SIGNAL(modifica_utente(QString,QString,int)),this,SLOT(modifica_utente(QString,QString,int)));
        dett_utente->show();


}

void C_listautenti::modifica_utente(QString n, QString c, int id) {

    utente* u=modelutenti->trova_utente(id);
    if(u)
     {
        u->Setnome(n);
        u->Setcognome(c);
     }
     view->aggiorna_vista();


}

void C_listautenti::chiudi_dettagli_utente(){
    mainview->abilita_view();
    view->abilita_doppio_click_utenti();
    delete dett_utente;
}

