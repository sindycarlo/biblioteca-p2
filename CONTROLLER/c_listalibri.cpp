#include "c_listalibri.h"
#include "../VIEW/mainwindow.h"

C_listalibri::C_listalibri(database* db,database_utente* udb, listalibri* v,amministratore* a,mainWindow*m,QObject *parent) :  QObject(parent),model(db),modelutenti(udb), view(v),admin(a), mainview(m) {
    connect(view,SIGNAL(richiesta_info(int)),this,SLOT(visualizza_info_libro(int)));
}

void C_listalibri::visualizza_info_libro(int id){

    view->disabilita_doppio_click();
    mainview->disabilita_view();
    dettagliolibro=new dettagli_Libro(id,model,modelutenti);
    connect(dettagliolibro,SIGNAL(chiudi_dettagli_opera()),this,SLOT(chiudi_dettagli_libro()));
    connect(dettagliolibro,SIGNAL(modifica(QString,QString,int)),this,SLOT(modificaL(QString,QString,int)));
    dettagliolibro->show();

}


void C_listalibri::chiudi_dettagli_libro(){
    view->abilita_doppio_click();
    mainview->abilita_view();
    delete dettagliolibro;
}

void C_listalibri::modificaL(QString t, QString a, int id) {
    admin->modifica_libro(t,a,id);
    view->aggiorna_vista();
}


