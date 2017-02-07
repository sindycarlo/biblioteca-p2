#include "c_listalibri.h"
#include "../VIEW/mainwindow.h"

C_listalibri::C_listalibri(database* db,database_utente* udb, database_utente_opere* uodb, listalibri* v,mainWindow*m,QObject *parent) :  QObject(parent),model(db),modelutenti(udb),modelutenteopere(uodb), view(v),mainview(m) {
    connect(view,SIGNAL(richiesta_info(int)),this,SLOT(visualizza_info_libro(int)));
}

void C_listalibri::visualizza_info_libro(int id){

    view->setFocus();
    view->disabilita_doppio_click();
    mainview->disabilita_view();
    dettagliolibro=new dettagli_Libro(id,model,modelutenti,modelutenteopere);
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
    opera* op=model->trova_opera(id);
    libro* l=dynamic_cast<libro*>(op);
    if(l)
    {
        l->SetTitolo(t);
        l->SetAutore(a);
    }
    view->aggiorna_vista();
}


