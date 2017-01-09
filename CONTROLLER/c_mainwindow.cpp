#include "c_mainwindow.h"

C_mainWindow::C_mainWindow(database* db,database_utente* udb,mainWindow* v, QObject *parent) :model(db),modelutenti(udb),view(v),  QObject(parent) {
    connect(view,SIGNAL(rimuovi(int)),this,SLOT(rimuovi_operaDB(int)));
    connect(view,SIGNAL(rimuovi_utente(int)),this,SLOT(rimuovi_utenteDB(int)));
    connect(view,SIGNAL(aggiorna_prestito(int)),this,SLOT(aggiorna_prestitoDB(int)));
    connect(view,SIGNAL(show_inserisci_rivista()),this,SLOT(inserisci_rivistaDB()));
    connect(view,SIGNAL(show_inserisci_libro()),this,SLOT(inserisci_libroDB()));
    connect(view,SIGNAL(show_inserisci_utentebasic()),this,SLOT(inserisci_utentebasicDB()));
    connect(view,SIGNAL(show_inserisci_utentepro()),this,SLOT(inserisci_utenteproDB()));
   //connessione che permette la ricerca di un'opera o di una serie di opere
    connect(view,SIGNAL(cerca_opera(QString)),this,SLOT(cerca_operaDB(QString)));
    connect(view,SIGNAL(cerca_utente(QString)),this,SLOT(cerca_utenteDB(QString)));
    //chiudi
    connect(view,SIGNAL(chiudi_app()),qApp,SLOT(quit()));
}

void C_mainWindow::cerca_operaDB(const QString& text){
    contenitore<opera> container;
    container=model->trova_opere_insieme(text);
    if(!(container.empty()))
    {
        view->costruisci_Tabella(container);
    }else{std::cout<<"NON TROVATO";view->aggiorna_vista();}
}
void C_mainWindow::cerca_utenteDB(const QString& text){
    contenitore<utente> container;
    container=modelutenti->trova_utenti_insieme(text);
    if(!(container.empty()))
    {

        view->costruisci_Tabellautenti(container);
    }else{view->aggiorna_vista();}
}


void C_mainWindow::rimuovi_operaDB(int ID){
    model->remove_opera(ID);
    view->aggiorna_vista();
}
void C_mainWindow::rimuovi_utenteDB(int ID){
    modelutenti->remove_utente(ID);
    view->aggiorna_vista();
}

void C_mainWindow::aggiorna_prestitoDB(int ID){

}


void C_mainWindow::inserisci_rivistaDB(){
    inserisci_Rivista* inserisci=new inserisci_Rivista();
    c_add_rivista * controller=new c_add_rivista(model,inserisci,view);
    inserisci->show();


}
void C_mainWindow::inserisci_libroDB(){
    inserisci_Libro* inserisci=new inserisci_Libro();
    c_add_libro* controller=new c_add_libro(model,inserisci,view);
    inserisci->show();
}

void C_mainWindow::inserisci_utentebasicDB(){
    inserisci_utentebasic* inserisci=new inserisci_utentebasic();
    c_add_utentebasic* controller=new c_add_utentebasic(modelutenti,inserisci,view);
    inserisci->show();
}
void C_mainWindow::inserisci_utenteproDB(){
    inserisci_utentepro* inserisci=new inserisci_utentepro();
    c_add_utentepro* controller=new c_add_utentepro(modelutenti,inserisci,view);
    inserisci->show();
}
