#include "homewindow.h"
#include<QApplication>
#include<QToolTip>
homewindow::homewindow(database* db,database_utente* udb) : Widget_Padre(db,udb) {


  //bottoni
    exit=new QPushButton("ESCI");
    accedicomeadmin=new QPushButton("ACCEDI COME AMMINISTRATORE");

  //layout
    orizzontale=new QHBoxLayout();
    Prlayout=new QVBoxLayout();
    bottoni=new QVBoxLayout();

    costruisci_contenuto();
    creaLayout();
    set_style();

    connect(accedicomeadmin,SIGNAL(clicked()),this,SLOT(slot_accedi()));
    connect(exit,SIGNAL(clicked()),qApp,SLOT(quit()));
}

void homewindow::set_style(){
    Widget_Padre::set_style();
}

void homewindow::costruisci_contenuto(){
     //aggiorna_vista();
}
void homewindow::aggiorna_vista() {

}

void homewindow::slot_accedi() {
    emit show_accedi();
}

void homewindow::creaLayout(){

    bottoni->addWidget(accedicomeadmin);
    orizzontale->addLayout(bottoni);
    Prlayout->addLayout(orizzontale);
    Prlayout->addWidget(exit);
    setLayout(Prlayout);

}





void homewindow::closeEvent(QCloseEvent *event){ emit chiudi_app(); }


homewindow::~homewindow(){
    delete bottoni;
    delete orizzontale;
    delete Prlayout;
    delete accedicomeadmin;
    delete exit;
}





