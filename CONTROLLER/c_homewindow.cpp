#include "CONTROLLER/c_homewindow.h"

c_homewindow::c_homewindow(database* db, database_utente* dbu, database_utente_opere* dbuop, homewindow* v,amministratore*a, QObject *parent) :  QObject(parent),model(db),modelutenti(dbu),modelop(dbuop), view(v),admin(a){
    connect(view,SIGNAL(show_accedi()),this,SLOT(accedi_admin()));
    connect(view,SIGNAL(show_accediutente(QString,QString)),this,SLOT(accedi_utente(QString,QString)));
    //chiudi
    connect(view,SIGNAL(chiudi_app()),qApp,SLOT(quit()));
}


void c_homewindow::accedi_admin() {

        viewmain= new mainWindow(model,modelutenti,modelop,view,admin);
        c_main=new C_mainWindow(viewmain,admin);
        viewmain->show();
        view->disabilita_pulsanti_home();

}

void c_homewindow::accedi_utente(QString u, QString p) {

    //cerco utente nel database degli utenti con quel nome e quella password:
    contenitore<utente>::iteratore it;
    bool trovato=false;
    int id=-1;
    for(it=modelutenti->dbutenti_begin();it!=modelutenti->dbutenti_end() && !trovato;it++)
    {
        if((*it)->GetNome()==u && (*it)->GetPassword()==p)
        {
            trovato=true;
            id=(*it)->GetID();
        }
    }
    if(trovato==true)
    {
        //apro la finestra utente:
        viewutente=new utenteWindow(id,model,modelutenti,modelop,view);
        c_utente=new c_utentewindow(id,model,modelutenti,modelop,viewutente);
        viewutente->show();
        view->disabilita_pulsanti_home();
    }

}
