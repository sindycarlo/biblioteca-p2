#include "utentewindow.h"
#include<QApplication>
#include<QToolTip>
utenteWindow::utenteWindow(database* db,database_utente* udb,database_utente_opere*uodb) : Widget_Padre(db,udb,uodb) {

    tablibri=new listalibri(get_model(),get_modelutenti(),get_modelutenteopere());   //tabella con l'elenco dei libri
    controllerLB=new C_listalibri(get_model(),tablibri);
    tabriviste=new listariviste(get_model(),get_modelutenti(),get_modelutenteopere());   //tabella con l'elenco deli libri
    controllerRB=new C_listariviste(get_model(),tabriviste);
    exit=new QPushButton("ESCI");
    ricevi_libro=new QPushButton("RICEVI LIBRO");
    ricevi_rivista=new QPushButton("RICEVI RIVISTA");
    restituisci_libro=new QPushButton("RESTITUISCI LIBRO");
    restituisci_rivista=new QPushButton("RESTITUISCI RIVISTA");
  //layout
    orizzontale=new QHBoxLayout();
    Prlayout=new QVBoxLayout();
    bottoni=new QVBoxLayout();

    costruisci_contenuto();
    creaLayout();
    set_style();


    connect(tablibri,SIGNAL(selezione(int)),this,SLOT(modifica_campo_libro(int)));
    connect(tabriviste,SIGNAL(selezione(int)),this,SLOT(modifica_campo_rivista(int)));
    connect(ricevi_libro,SIGNAL(clicked()),this,SLOT(ricevi_segnale_libri()));
    connect(ricevi_rivista,SIGNAL(clicked()),this,SLOT(ricevi_segnale_riviste()));
    //connect(restituisci_libro,SIGNAL(restituiscirivista(unsigned int)),this,SLOT(show_restituisci_rivista(unsigned int)));
    //connect(restituisci_rivista,SIGNAL(restituiscilibro(unsigned int)),this,SLOT(show_restituisci_libro(unsigned int)));
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
void utenteWindow::ricevi_segnale_libri(){
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
void utenteWindow::ricevi_segnale_riviste(){
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



void utenteWindow::creaLayout(){

    bottoni->addWidget(ricevi_libro);
    bottoni->addWidget(ricevi_rivista);
    bottoni->addWidget(restituisci_libro);
    bottoni->addWidget(restituisci_rivista);

    orizzontale->addWidget(tablibri);
    orizzontale->addWidget(tabriviste);
    orizzontale->addLayout(bottoni);

    Prlayout->addLayout(orizzontale);
    Prlayout->addWidget(exit);
    setLayout(Prlayout);

}


void utenteWindow::costruisci_Tabella_libri(const contenitore<opera>& lista){  }
void utenteWindow::costruisci_Tabella_riviste(const contenitore<opera>& lista){  }
void utenteWindow::aggiorna_vista(){tabriviste->aggiorna_vista();tablibri->aggiorna_vista();}
void utenteWindow::abilita_bottoni_libri(){
    ricevi_libro->setEnabled(true);
    restituisci_libro->setEnabled(true);
}
void utenteWindow::disabilita_bottoni_libri(){
    ricevi_libro->setEnabled(false);
    restituisci_libro->setEnabled(false);
}
void utenteWindow::abilita_bottoni_riviste(){
   ricevi_rivista->setEnabled(true);
   restituisci_rivista->setEnabled(true);

}

void utenteWindow::disabilita_bottoni_riviste(){
   ricevi_rivista->setEnabled(false);
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
    delete ricevi_libro;
    delete ricevi_rivista;
    delete restituisci_libro;
    delete restituisci_rivista;
    delete exit;
}
