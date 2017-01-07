#include "c_listautenti.h"

C_listautenti::C_listautenti(database_utente* udb, listautenti* lu,QObject *parent) : model(udb), view(lu), QObject(parent) {
    connect(view,SIGNAL(richiesta_info_utenti(int)),this,SLOT(visualizza_info_utenti(int)));


}

void C_listautenti::visualizza_info_utenti(int id){


}


