#include "homewindow.h"
#include<QApplication>
#include<QToolTip>
homewindow::homewindow(database* db,database_utente* udb) : Widget_Padre(db,udb) {


  //bottoni
    exit=new QPushButton("ESCI");
    accedicomeadmin=new QPushButton("ACCEDI COME AMMINISTRATORE");
    accedicomeutente=new QPushButton("ACCEDI COME UTENTE");

  //layout
    orizzontale=new QHBoxLayout();
    Prlayout=new QVBoxLayout();
    bottoni=new QVBoxLayout();

  //campi dati richiesti ad utente
    nameuser=new QLineEdit();
    password=new QLineEdit();

    costruisci_contenuto();
    creaLayout();
    set_style();

    connect(accedicomeadmin,SIGNAL(clicked()),this,SLOT(slot_accedi()));
    connect(accedicomeutente,SIGNAL(clicked()),this,SLOT(slot_accediutente()));
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
void homewindow::slot_accediutente() {

    if(nameuser->text().isEmpty() || password->text().isEmpty())
    {
            QMessageBox warning;
            warning.setIcon(QMessageBox::Critical);
            warning.setWindowTitle("Impossibile inviare richiesta");
            warning.setText("E' necessario compilare tutti i campi.");
            warning.setStandardButtons(QMessageBox::Ok);
            warning.setDefaultButton(QMessageBox::Ok);
            warning.exec();
        }
        else{
                emit show_accediutente(nameuser->text(),password->text());
             }
}


void homewindow::creaLayout(){

    bottoni->addWidget(accedicomeadmin);
    bottoni->addWidget(accedicomeutente);
    bottoni->addWidget(nameuser);
    bottoni->addWidget(password);
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
    delete accedicomeutente;
    delete nameuser;
    delete password;
}





