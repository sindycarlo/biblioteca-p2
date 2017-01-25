#include "homewindow.h"
#include<QApplication>
#include<QToolTip>
homewindow::homewindow(database* db,database_utente* udb,database_utente_opere* uodb) : Widget_Padre(db,udb,uodb) {


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
    password->setEchoMode(QLineEdit::Password);

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
    aggiorna_vista();
}
void homewindow::aggiorna_vista() {
    nameuser->clear();
    password->clear();
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
        //verifico se username e password coincidono con un utente nel database:
        contenitore<utente>::iteratore it;
        bool trovato=false;
        for(it=get_modelutenti()->dbutenti_begin();it!=get_modelutenti()->dbutenti_end();it++)
        {
            if((*it)->GetNome()==nameuser->text() && (*it)->GetPassword()==password->text())
            {
                trovato=true;
            }
        }
        if(trovato==false)
        {
            QMessageBox warning;
            warning.setIcon(QMessageBox::Critical);
            warning.setWindowTitle("Impossibile inviare richiesta");
            warning.setText("Errore username o password non corretti");
            warning.setStandardButtons(QMessageBox::Ok);
            warning.setDefaultButton(QMessageBox::Ok);
            warning.exec();
            aggiorna_vista();

        }
        else { emit show_accediutente(nameuser->text(),password->text());}

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

void homewindow::abilita_pulsanti_home() {
    accedicomeadmin->setEnabled(true);
    accedicomeutente->setEnabled(true);
}

void homewindow::disabilita_pulsanti_home() {
    accedicomeadmin->setEnabled(false);
    accedicomeutente->setEnabled(false);
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





