#include "c_utentewindow.h"

c_utentewindow::c_utentewindow(database* db,database_utente* udb,database_utente_opere* uodb,utenteWindow* v, QObject *parent) :model(db),modelutenti(udb),modelutenteopere(uodb),view(v),  QObject(parent) {
    connect(view,SIGNAL(ricevilibro(unsigned int)),this,SLOT(ricevilibroDB(unsigned int)));
    connect(view,SIGNAL(ricevirivista(unsigned int)),this,SLOT(ricevirivistaDB(unsigned int)));

    //chiudi
    connect(view,SIGNAL(chiudi_app()),qApp,SLOT(quit()));
}


void c_utentewindow::ricevilibroDB(unsigned int id) {

}

void c_utentewindow::ricevirivistaDB(unsigned int id) {

}

