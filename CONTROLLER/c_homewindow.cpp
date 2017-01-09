#include "CONTROLLER/c_homewindow.h"

c_homewindow::c_homewindow(database * db, database_utente * udb, homewindow* v, QObject *parent) :model(db), modelutenti(udb),view(v),  QObject(parent) {
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

void c_homewindow::accedi_admin() {

    mainWindow* finestraamministratore= new mainWindow(Getmodel(),Getmodelutenti());
    C_mainWindow* controlleramministratore=new C_mainWindow(Getmodel(),Getmodelutenti(),finestraamministratore);
    finestraamministratore->show();
}

void c_homewindow::accedi_utente(QString u,QString p) {

}
