#include "CONTROLLER/c_homewindow.h"

c_homewindow::c_homewindow(database* db, database_utente* dbu, homewindow* v,amministratore*a, QObject *parent) :  QObject(parent),model(db),modelutenti(dbu), view(v),admin(a){
    connect(view,SIGNAL(show_accedi()),this,SLOT(accedi()));
    connect(view,SIGNAL(show_accedi_utente(int)),this,SLOT(accedi_utente(int)));
    //chiudi
    connect(view,SIGNAL(chiudi_app()),qApp,SLOT(quit()));
}


void c_homewindow::accedi() {

        //apro la finestra amministratore:
        viewmain= new mainWindow(model,modelutenti,view,admin);
        c_main=new C_mainWindow(viewmain,admin);
        viewmain->show();
        view->disabilita_pulsanti_home();

}

void c_homewindow::accedi_utente(int idutenteaccettato) {

        //apro la finestra utente:
        viewutente=new utenteWindow(idutenteaccettato,model,modelutenti,view);
        c_utente=new c_utentewindow(idutenteaccettato,model,modelutenti,viewutente);
        viewutente->show();
        view->disabilita_pulsanti_home();


}
