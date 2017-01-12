#include "CONTROLLER/c_homewindow.h"

c_homewindow::c_homewindow(database * db, database_utente * udb, database_utente_opere* uodb, homewindow* v, QObject *parent) :model(db), modelutenti(udb), modelutenteopere(uodb),view(v),  QObject(parent) {
    connect(view,SIGNAL(show_accedi()),this,SLOT(accedi_admin()));
    connect(view,SIGNAL(show_accediutente(QString,QString)),this,SLOT(accedi_utente(QString,QString)));
    //chiudi
    connect(view,SIGNAL(chiudi_app()),qApp,SLOT(quit()));
}

database* c_homewindow::Getmodel() const {
    return model;
}
database_utente* c_homewindow::Getmodelutenti() const {
    return modelutenti;
}
database_utente_opere* c_homewindow::Getmodelutenteopere() const {
    return modelutenteopere;
}

void c_homewindow::accedi_admin() {

    mainWindow* finestraamministratore= new mainWindow(Getmodel(),Getmodelutenti(),Getmodelutenteopere());
    C_mainWindow* controlleramministratore=new C_mainWindow(Getmodel(),Getmodelutenti(),Getmodelutenteopere(),finestraamministratore);
    finestraamministratore->show();
}

void c_homewindow::accedi_utente(QString u,QString p) {

    //cerco utente nel database degli utenti con quel nome e quella password:
    contenitore<utente>::iteratore it;
    bool trovato=false;
    for(it=Getmodelutenti()->dbutenti_begin();it!=Getmodelutenti()->dbutenti_end() && !trovato;it++)
    {
        if((*it)->GetNome()==u && (*it)->GetPassword()==p)
        {
            trovato=true;
            int id=(*it)->GetID();
            //apro la finestra utente:
            utenteWindow*finestrautente=new utenteWindow(id,Getmodel(),Getmodelutenti(),Getmodelutenteopere());
            c_utentewindow*controllerutente= new c_utentewindow(id,Getmodel(),Getmodelutenti(),Getmodelutenteopere(),finestrautente);
            finestrautente->show();
        }else std::cout<<"errore username e password sbagliati";
    }

}
