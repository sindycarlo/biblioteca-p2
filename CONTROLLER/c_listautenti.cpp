#include "c_listautenti.h"

C_listautenti::C_listautenti(database *db, database_utente* udb, database_utente_opere *uodb, listautenti* lu, QObject *parent) :model(db), modelutenti(udb),modelutenteopere(uodb), view(lu), QObject(parent) {
    connect(view,SIGNAL(richiesta_info_utenti(int)),this,SLOT(visualizza_info_utenti(int)));


}


void C_listautenti::visualizza_info_utenti(int id){



    if(dynamic_cast<utente_basic*>(modelutenti->trova_utente(id)))
    {
        dett_utenteb=new dettagli_utente_basic(id,model,modelutenti,modelutenteopere);
        connect(dett_utenteb,SIGNAL(chiudi_dettagli_utente()),this,SLOT(chiudi_dettagli_utenteb()));
            connect(dett_utenteb,SIGNAL(modifica_utente(QString,QString,int)),this,SLOT(modifica_utente(QString,QString,int)));
        dett_utenteb->show();
    }
    else if(dynamic_cast<utente_pro*>(modelutenti->trova_utente(id)))
    {
        dett_utentep=new dettagli_utente_pro(id,model,modelutenti,modelutenteopere);
        connect(dett_utentep,SIGNAL(chiudi_dettagli_utente()),this,SLOT(chiudi_dettagli_utentep()));
            connect(dett_utentep,SIGNAL(modifica_utente(QString,QString,int)),this,SLOT(modifica_utente(QString,QString,int)));
        dett_utentep->show();
    }
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

void C_listautenti::chiudi_dettagli_utenteb(){
    view->abilita_doppio_click_utenti();
    delete dett_utenteb;
}

void C_listautenti::chiudi_dettagli_utentep(){
    view->abilita_doppio_click_utenti();
    delete dett_utentep;
}

