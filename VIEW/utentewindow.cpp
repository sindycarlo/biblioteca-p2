#include "utentewindow.h"
#include<QApplication>
#include<QToolTip>
utenteWindow::utenteWindow(unsigned int id,database* db,database_utente* udb,database_utente_opere*uodb) : idutente(id), Widget_Padre(db,udb,uodb) {

    tablibri=new listalibri(Getidutente(),get_model(),get_modelutenti(),get_modelutenteopere());   //tabella con l'elenco dei libri
    controllerLB=new C_listalibri(get_model(),get_modelutenti(),get_modelutenteopere(),tablibri,0);
    tabriviste=new listariviste(Getidutente(),get_model(),get_modelutenti(),get_modelutenteopere());   //tabella con l'elenco deli libri
    controllerRB=new C_listariviste(get_model(),get_modelutenti(),get_modelutenteopere(),tabriviste,0);
    tablibriprestito=new listalibri(Getidutente(),get_model(),get_modelutenti(),get_modelutenteopere());   //tabella con l'elenco dei libri
    controllerLBprestito=new C_listalibri(get_model(),get_modelutenti(),get_modelutenteopere(),tablibriprestito);
    tabrivisteprestito=new listariviste(Getidutente(),get_model(),get_modelutenti(),get_modelutenteopere());   //tabella con l'elenco deli libri
    controllerRBprestito=new C_listariviste(get_model(),get_modelutenti(),get_modelutenteopere(),tabrivisteprestito);
    exit=new QPushButton("ESCI");
    ricevi_libro=new QPushButton("RICEVI LIBRO");
    ricevi_rivista=new QPushButton("RICEVI RIVISTA");
    restituisci_libro=new QPushButton("RESTITUISCI LIBRO");
    restituisci_rivista=new QPushButton("RESTITUISCI RIVISTA");
    disabilita_bottoni_libri();
    disabilita_bottoni_libri_prestito();
    disabilita_bottoni_riviste();
    disabilita_bottoni_riviste_prestito();
  //layout
    orizzontale=new QHBoxLayout();
    Prlayout=new QVBoxLayout();
    bottoni=new QVBoxLayout();

    costruisci_contenuto();
    creaLayout();
    set_style();


    connect(tablibri,SIGNAL(selezione(int)),this,SLOT(modifica_campo_libro(int)));
    connect(tabriviste,SIGNAL(selezione(int)),this,SLOT(modifica_campo_rivista(int)));
    connect(tablibriprestito,SIGNAL(selezione(int)),this,SLOT(modifica_campo_libro_prestito(int)));
    connect(tabrivisteprestito,SIGNAL(selezione(int)),this,SLOT(modifica_campo_rivista_prestito(int)));
    connect(ricevi_libro,SIGNAL(clicked()),this,SLOT(ricevi_segnale_libri()));
    connect(ricevi_rivista,SIGNAL(clicked()),this,SLOT(ricevi_segnale_riviste()));
    connect(restituisci_libro,SIGNAL(clicked()),this,SLOT(restituisci_segnale_libri()));
    connect(restituisci_rivista,SIGNAL(clicked()),this,SLOT(restituisci_segnale_riviste()));
    connect(exit,SIGNAL(clicked()),qApp,SLOT(quit()));
}

void utenteWindow::set_style(){
    Widget_Padre::set_style();
}

void utenteWindow::costruisci_contenuto(){
     aggiorna_vista();
}


void utenteWindow::modifica_campo_libro(int ID){
    libro_selezionato=ID;
    abilita_bottoni_libri();
    disabilita_bottoni_riviste();

}
void utenteWindow::modifica_campo_rivista(int ID){
    rivista_selezionata=ID;
    abilita_bottoni_riviste();
    disabilita_bottoni_libri();

}
void utenteWindow::modifica_campo_libro_prestito(int ID){
    libro_selezionato=ID;
    abilita_bottoni_libri_prestito();
    disabilita_bottoni_riviste_prestito();

}
void utenteWindow::modifica_campo_rivista_prestito(int ID){
    rivista_selezionata=ID;
    abilita_bottoni_riviste_prestito();
    disabilita_bottoni_libri_prestito();

}

void utenteWindow::ricevi_segnale_libri(){
    utente* u=get_modelutenti()->trova_utente(Getidutente());
    utente_basic* ub=dynamic_cast<utente_basic*>(u);
    if(ub && ub->Get_numopere()>=5)
    {
        QMessageBox warning;
            warning.setIcon(QMessageBox::Question);
            warning.setWindowTitle("Errore");
            warning.setText("Hai raggiunto il massimo numero di opere che puoi ricevere in prestito");
            warning.setStandardButtons(QMessageBox::Cancel);
            warning.setDefaultButton(QMessageBox::Cancel);
            warning.exec();
    }
    else {
    QString identificativo;
    identificativo.setNum(libro_selezionato);
    QMessageBox warning;
        warning.setIcon(QMessageBox::Question);
        warning.setWindowTitle("Ricevi Libro");
        warning.setText("Hai selezionato il libro con ID: <b>"+identificativo+"</b>");
        warning.setInformativeText("Vuoi veramente ricevere in prestito questa opera?");
        warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        warning.setDefaultButton(QMessageBox::Cancel);
        int ret = warning.exec();
        if(ret==QMessageBox::Yes) {
            emit show_ricevi_libro(libro_selezionato);
        }
    }
}

unsigned int utenteWindow::Getidutente() const {return idutente;}

void utenteWindow::ricevi_segnale_riviste(){

    utente* u=get_modelutenti()->trova_utente(Getidutente());
    utente_basic* ub=dynamic_cast<utente_basic*>(u);
    if(ub && ub->Get_numopere()>=5)
    {
        QMessageBox warning;
            warning.setIcon(QMessageBox::Question);
            warning.setWindowTitle("Errore");
            warning.setText("Hai raggiunto il massimo numero di opere che puoi ricevere in prestito");
            warning.setStandardButtons(QMessageBox::Cancel);
            warning.setDefaultButton(QMessageBox::Cancel);
            warning.exec();
    }
    else {
    QString identificativo;
    identificativo.setNum(rivista_selezionata);
    QMessageBox warning;
        warning.setIcon(QMessageBox::Question);
        warning.setWindowTitle("Ricevi Rivista");
        warning.setText("Hai selezionato il libro con ID: <b>"+identificativo+"</b>");
        warning.setInformativeText("Vuoi veramente ricevere in prestito questa opera?");
        warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        warning.setDefaultButton(QMessageBox::Cancel);
        int ret = warning.exec();
        if(ret==QMessageBox::Yes) {
            emit show_ricevi_rivista(rivista_selezionata);
        }
    }
}
void utenteWindow::restituisci_segnale_libri(){
    QString identificativo;
    identificativo.setNum(libro_selezionato);
    QMessageBox warning;
        warning.setIcon(QMessageBox::Question);
        warning.setWindowTitle("Restituisci Libro");
        warning.setText("Hai selezionato il libro con ID: <b>"+identificativo+"</b>");
        warning.setInformativeText("Vuoi veramente restituire questa opera?");
        warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        warning.setDefaultButton(QMessageBox::Cancel);
        int ret = warning.exec();
        if(ret==QMessageBox::Yes) {
            emit show_restituisci_libro(libro_selezionato);
        }
}
void utenteWindow::restituisci_segnale_riviste(){
    QString identificativo;
    identificativo.setNum(rivista_selezionata);
    QMessageBox warning;
        warning.setIcon(QMessageBox::Question);
        warning.setWindowTitle("Restituisci Rivista");
        warning.setText("Hai selezionato il libro con ID: <b>"+identificativo+"</b>");
        warning.setInformativeText("Vuoi veramente restituire questa opera?");
        warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        warning.setDefaultButton(QMessageBox::Cancel);
        int ret = warning.exec();
        if(ret==QMessageBox::Yes) {
            emit show_restituisci_rivista(rivista_selezionata);
        }
}



void utenteWindow::creaLayout(){

    bottoni->addWidget(ricevi_libro);
    bottoni->addWidget(ricevi_rivista);
    bottoni->addWidget(restituisci_libro);
    bottoni->addWidget(restituisci_rivista);

    orizzontale->addWidget(tablibri);
    orizzontale->addWidget(tabriviste);
    orizzontale->addLayout(bottoni);
    orizzontale->addWidget(tablibriprestito);
    orizzontale->addWidget(tabrivisteprestito);

    Prlayout->addLayout(orizzontale);
    Prlayout->addWidget(exit);
    setLayout(Prlayout);

}


void utenteWindow::aggiorna_vista(){tabriviste->aggiorna_vista();tablibri->aggiorna_vista();tabrivisteprestito->aggiorna_vista_prestito_riviste();tablibriprestito->aggiorna_vista_prestito_libri();}
void utenteWindow::abilita_bottoni_libri(){
    ricevi_libro->setEnabled(true);
    restituisci_libro->setEnabled(false);
}
void utenteWindow::disabilita_bottoni_libri(){
    ricevi_libro->setEnabled(false);
    restituisci_libro->setEnabled(false);
}
void utenteWindow::abilita_bottoni_riviste(){
   ricevi_rivista->setEnabled(true);
   restituisci_rivista->setEnabled(false);

}

void utenteWindow::disabilita_bottoni_riviste(){
   ricevi_rivista->setEnabled(false);
   restituisci_rivista->setEnabled(false);

}

void utenteWindow::abilita_bottoni_libri_prestito(){
    restituisci_libro->setEnabled(true);
    ricevi_libro->setEnabled(false);
}
void utenteWindow::disabilita_bottoni_libri_prestito(){
    restituisci_libro->setEnabled(false);
}
void utenteWindow::abilita_bottoni_riviste_prestito(){
   restituisci_rivista->setEnabled(true);
   ricevi_rivista->setEnabled(false);

}

void utenteWindow::disabilita_bottoni_riviste_prestito(){
   restituisci_rivista->setEnabled(false);

}


void utenteWindow::closeEvent(QCloseEvent *event){ emit chiudi_app(); }


utenteWindow::~utenteWindow(){
    delete bottoni;
    delete orizzontale;
    delete Prlayout;
    delete tablibri;
    delete tabriviste;
    delete controllerLB;
    delete controllerRB;
    delete tablibriprestito;
    delete tabrivisteprestito;
    delete controllerLBprestito;
    delete controllerRBprestito;
    delete ricevi_libro;
    delete ricevi_rivista;
    delete restituisci_libro;
    delete restituisci_rivista;
    delete exit;
}
