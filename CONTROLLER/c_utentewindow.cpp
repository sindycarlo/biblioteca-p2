#include "c_utentewindow.h"

c_utentewindow::c_utentewindow(unsigned int id,database* db,database_utente* udb,database_utente_opere* uodb,utenteWindow* v, QObject *parent) :idutente(id),model(db),modelutenti(udb),modelutenteopere(uodb),view(v),  QObject(parent) {
    connect(view,SIGNAL(show_ricevi_libro(unsigned int)),this,SLOT(ricevilibroDB(unsigned int)));
    connect(view,SIGNAL(show_ricevi_rivista(unsigned int)),this,SLOT(ricevirivistaDB(unsigned int)));
    connect(view,SIGNAL(show_restituisci_libro(unsigned int)),this,SLOT(restituiscilibroDB(unsigned int)));
    connect(view,SIGNAL(show_restituisci_rivista(unsigned int)),this,SLOT(restituiscirivistaDB(unsigned int)));

    //chiudi
    connect(view,SIGNAL(chiudi_app()),this,SLOT(chiudi_utentewindow()));
}

unsigned int c_utentewindow::Getidutente() const {return idutente;}


void c_utentewindow::ricevilibroDB(unsigned int id) {
    utente* user=modelutenti->trova_utente(Getidutente());
    user->ricevi_libro(id);
    view->aggiorna_vista();
}

void c_utentewindow::ricevirivistaDB(unsigned int id) {
    utente* user=modelutenti->trova_utente(Getidutente());     
      user->ricevi_rivista(id);
      view->aggiorna_vista();

}

void c_utentewindow::restituiscilibroDB(unsigned int id) {
    utente* user=modelutenti->trova_utente(Getidutente());
    user->restituisci_libro(id);
    view->aggiorna_vista();
}

void c_utentewindow::restituiscirivistaDB(unsigned int id) {
    utente* user=modelutenti->trova_utente(Getidutente());
    user->restituisci_rivista(id);
    view->aggiorna_vista();
}

void c_utentewindow::chiudi_utentewindow() {
    delete view;
}
