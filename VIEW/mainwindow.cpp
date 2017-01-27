#include "mainwindow.h"
#include<QApplication>
#include<QToolTip>
mainWindow::mainWindow(database* db,database_utente* udb,database_utente_opere*uodb,homewindow* hw) : Widget_Padre(db,udb,uodb),finestraprinc(hw) {
    //da correggere
    tablibri=new listalibri(0,get_model(),get_modelutenti(),get_modelutenteopere());   //tabella con l'elenco delle opere
    tabriviste=new listariviste(0,get_model(),get_modelutenti(),get_modelutenteopere());
    tabutenti=new listautenti(get_model(),get_modelutenti(),get_modelutenteopere());
    controllerLP=new C_listalibri(get_model(),get_modelutenti(),get_modelutenteopere(),tablibri);
    controllerRP=new C_listariviste(get_model(),get_modelutenti(),get_modelutenteopere(),tabriviste);
    controllerUTENTI=new C_listautenti(get_model(),get_modelutenti(),get_modelutenteopere(),tabutenti);
  //bottoni
    exit=new QPushButton("ESCI");
    aggiungi_rivista=new QPushButton("AGGIUNGI RIVISTA");
    aggiungi_libro=new QPushButton("AGGIUNGI LIBRO");
    rimuovi_opera=new QPushButton("RIMUOVI OPERA");
    rimuovi_utenti=new QPushButton("RIMUOVI UTENTE");
    aggiungi_utente_basic=new QPushButton("AGGIUNGI UTENTE BASIC");
    aggiungi_utente_pro=new QPushButton("AGGIUNGI UTENTE PRO");
    disabilita_bottoni_tutti();

  //layout
    orizzontale=new QHBoxLayout();
    Prlayout=new QVBoxLayout();
    bottoni=new QVBoxLayout();

    costruisci_contenuto();   
    creaLayout();
    set_style();

    connect(tablibri,SIGNAL(selezione(int)),this,SLOT(modifica_campo(int)));
    connect(tabriviste,SIGNAL(selezione(int)),this,SLOT(modifica_campo(int)));
    connect(tabutenti,SIGNAL(selezione_utenti(int)),this,SLOT(modifica_campo_utenti(int)));
    connect(rimuovi_opera,SIGNAL(clicked()),this,SLOT(rimuovi_segnale()));
    connect(rimuovi_utenti,SIGNAL(clicked()),this,SLOT(rimuovi_segnale_utenti()));
    connect(aggiungi_rivista,SIGNAL(clicked()),this,SLOT(slot_inserisci_rivista()));
    connect(aggiungi_libro,SIGNAL(clicked()),this,SLOT(slot_inserisci_libro()));
    connect(aggiungi_utente_basic,SIGNAL(clicked()),this,SLOT(slot_inserisci_utentebasic()));
    connect(aggiungi_utente_pro,SIGNAL(clicked()),this,SLOT(slot_inserisci_utentepro()));
    connect(exit,SIGNAL(clicked()),this,SLOT(chiudi()));
}

void mainWindow::set_style(){
    Widget_Padre::set_style();
    tablibri->setToolTip("Doppio click per visualizzare i dettagli dell'opera");
    tabutenti->setToolTip("Doppio click per visualizzare i dettagli dell'utente");

}

void mainWindow::costruisci_contenuto(){
     aggiorna_vista();
}

void mainWindow::creaLayout(){

    bottoni->addWidget(aggiungi_libro);
    bottoni->addWidget(aggiungi_rivista);
    bottoni->addWidget(rimuovi_opera);
    bottoni->addWidget(rimuovi_utenti);
    bottoni->addWidget(aggiungi_utente_basic);
    bottoni->addWidget(aggiungi_utente_pro);

    orizzontale->addWidget(tablibri);
    orizzontale->addWidget(tabriviste);
    orizzontale->addWidget(tabutenti);
    orizzontale->addLayout(bottoni);


    Prlayout->addLayout(orizzontale);
    Prlayout->addWidget(exit);
    setLayout(Prlayout);

}

void mainWindow::modifica_campo(int ID){
    opera_selezionata=ID;
    abilita_bottoni();
    disabilita_bottoni_utenti();

}

void mainWindow::modifica_campo_utenti(int ID){
    utente_selezionato=ID;
    abilita_bottoni_utenti();
    disabilita_bottoni();

}


void mainWindow::rimuovi_segnale(){
    QString identificativo;
    identificativo.setNum(opera_selezionata);
    QMessageBox warning;
        warning.setIcon(QMessageBox::Question);
        warning.setWindowTitle("Rimuovi Opera");
        warning.setText("Hai selezionato l'opera con ID: <b>"+identificativo+"</b>");
        warning.setInformativeText("Vuoi veramente eliminare questa opera?");
        warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        warning.setDefaultButton(QMessageBox::Cancel);
        int ret = warning.exec();
        if(ret==QMessageBox::Yes) {
            emit rimuovi(opera_selezionata);
        }
}
void mainWindow::rimuovi_segnale_utenti(){
    bool erroreopereprestito=false;
    contenitore<opera>::iteratore it;
    for(it=get_modelutenteopere()->dbopereutenti_begin();it!=get_modelutenteopere()->dbopereutenti_end();it++)
    {if((*it)->Getappartenenza()==utente_selezionato){erroreopereprestito=true;}}
    if(erroreopereprestito==true)
    {
            QString identificativo;
            identificativo.setNum(utente_selezionato);
            QMessageBox warning;
            warning.setIcon(QMessageBox::Question);
            warning.setWindowTitle("Errore");
            warning.setText(" l'utente con ID: <b>"+identificativo+"</b> ha ancora opere in prestito");
            warning.setStandardButtons(QMessageBox::Cancel);
            warning.setDefaultButton(QMessageBox::Cancel);
            warning.exec();



    }else{

    QString identificativo;
    identificativo.setNum(utente_selezionato);
    QMessageBox warning;
        warning.setIcon(QMessageBox::Question);
        warning.setWindowTitle("Rimuovi Utente");
        warning.setText("Hai selezionato l'utente con ID: <b>"+identificativo+"</b>");
        warning.setInformativeText("Vuoi veramente eliminare questo utente?");
        warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        warning.setDefaultButton(QMessageBox::Cancel);
        int ret = warning.exec();
        if(ret==QMessageBox::Yes) {
            emit rimuovi_utente(utente_selezionato);
        }
    }
}

void mainWindow::slot_inserisci_rivista(){
    emit show_inserisci_rivista();
}

void mainWindow::slot_inserisci_libro(){
    emit show_inserisci_libro();
}
void mainWindow::slot_inserisci_utentebasic(){
    emit show_inserisci_utentebasic();
}
void mainWindow::slot_inserisci_utentepro(){
    emit show_inserisci_utentepro();
}


void mainWindow::disabilita(){
    disabilita_bottoni();
}


void mainWindow::aggiorna_vista(){tablibri->aggiorna_vista();tabriviste->aggiorna_vista();tabutenti->aggiorna_vista();}
void mainWindow::abilita_bottoni(){
    rimuovi_opera->setEnabled(true);
}

void mainWindow::disabilita_bottoni(){
   rimuovi_opera->setEnabled(false);

}
void mainWindow::abilita_bottoni_utenti(){
    rimuovi_utenti->setEnabled(true);

}

void mainWindow::disabilita_bottoni_utenti(){
   rimuovi_utenti->setEnabled(false);

}
void mainWindow::disabilita_bottoni_tutti(){
   rimuovi_opera->setEnabled(false);
   rimuovi_utenti->setEnabled(false);

}


void mainWindow::chiudi() {
    finestraprinc->abilita_pulsanti_home();
    emit chiudi_app();
}

void mainWindow::closeEvent(){finestraprinc->abilita_pulsanti_home(); emit chiudi_app(); }


mainWindow::~mainWindow(){
    delete bottoni;
    delete orizzontale;
    delete Prlayout;
    delete rimuovi_opera;
    delete rimuovi_utenti;
    delete tablibri;
    delete tabriviste;
    delete controllerRP;
    delete tabutenti;
    delete controllerLP;
    delete controllerUTENTI;
    delete aggiungi_libro;
    delete aggiungi_rivista;
    delete aggiungi_utente_basic;
    delete aggiungi_utente_pro;
    delete exit;
}





