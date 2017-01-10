#include "utentewindow.h"
#include<QApplication>
#include<QToolTip>
utenteWindow::utenteWindow(database* db,database_utente* udb,database_utente_opere*uodb) : Widget_Padre(db,udb,uodb) {

    tab=new listaOp(get_model(),get_modelutenti(),get_modelutenteopere());   //tabella con l'elenco delle opere
    controllerOP=new C_listaop(get_model(),tab);

    exit=new QPushButton("ESCI");
    ricevi_libro=new QPushButton("RICEVI LIBRO");
    ricevi_rivista=new QPushButton("RICEVI RIVISTA");

    disabilita_bottoni();


  //layout
    orizzontale=new QHBoxLayout();
    Prlayout=new QVBoxLayout();
    bottoni=new QVBoxLayout();

    costruisci_contenuto();
    creaLayout();
    set_style();

    connect(ricevi_libro,SIGNAL(ricevilibro(unsigned int)),this,SLOT(show_ricevi_libro(unsigned int)));
    connect(ricevi_libro,SIGNAL(ricevirivista(unsigned int)),this,SLOT(show_ricevi_rivista(unsigned int)));
    connect(exit,SIGNAL(clicked()),qApp,SLOT(quit()));
}

void utenteWindow::set_style(){
    Widget_Padre::set_style();
}

void utenteWindow::costruisci_contenuto(){
     //aggiorna_vista();
}

void utenteWindow::creaLayout(){

    bottoni->addWidget(ricevi_libro);
    bottoni->addWidget(ricevi_rivista);


    orizzontale->addWidget(tab);
    orizzontale->addLayout(bottoni);

    Prlayout->addLayout(orizzontale);
    Prlayout->addWidget(exit);
    setLayout(Prlayout);

}

void utenteWindow::show_ricevi_libro(unsigned int idl){
    emit ricevilibro(idl);
}

void utenteWindow::show_ricevi_rivista(unsigned int idr){
    emit ricevirivista(idr);
}


void utenteWindow::costruisci_Tabella_libri(const contenitore<opera>& lista){ tab->build_Nuova(lista); }
void utenteWindow::costruisci_Tabella_riviste(const contenitore<opera>& lista){ tab->build_Nuova(lista); }
void utenteWindow::aggiorna_vista(){ tab->aggiorna_vista();}
void utenteWindow::abilita_bottoni(){
    ricevi_libro->setEnabled(true);
    ricevi_rivista->setEnabled(true);
}

void utenteWindow::disabilita_bottoni(){
   ricevi_rivista->setEnabled(false);
   ricevi_libro->setEnabled(false);

}


void utenteWindow::closeEvent(QCloseEvent *event){ emit chiudi_app(); }


utenteWindow::~utenteWindow(){
    delete bottoni;
    delete orizzontale;
    delete Prlayout;
    delete tab;
    delete controllerOP;
    delete ricevi_libro;
    delete ricevi_rivista;
    delete exit;
}
