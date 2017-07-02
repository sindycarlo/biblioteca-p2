#include "homewindow.h"
#include<QApplication>
#include<QToolTip>
homewindow::homewindow(database* db,database_utente* udb,amministratore* a) : Widget_Padre(db,udb), admin(a) {

    setWindowFlags ( Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    //bottoni
      exit=new QPushButton("ESCI");
      accedicomeadmin=new QPushButton("ACCEDI COME AMMINISTRATORE");
      accedicomeutente=new QPushButton("ACCEDI COME UTENTE");

    //Label
      us=new QLabel("username:");
      passw=new QLabel("password:");


    //layout
      gridlogin=new QGridLayout;
      layout=new QVBoxLayout;



      //campi dati richiesti
        username=new QLineEdit();
        password=new QLineEdit();
        password->setEchoMode(QLineEdit::Password);

    costruisci_contenuto();
    creaLayout();
    set_style();

    connect(accedicomeadmin,SIGNAL(clicked()),this,SLOT(slot_accedi()));
    connect(accedicomeutente,SIGNAL(clicked()),this,SLOT(slot_accedi_utente()));
    connect(exit,SIGNAL(clicked()),qApp,SLOT(quit()));
}

void homewindow::set_style(){
    Widget_Padre::set_style();
}

void homewindow::costruisci_contenuto(){
    aggiorna_vista();
}
void homewindow::aggiorna_vista() {
    username->clear();
    password->clear();
}
void homewindow::slot_accedi() {

    if(username->text().isEmpty() || password->text().isEmpty() || admin->Getusername()!=username->text() || admin->Getpassword()!=password->text() )
    {
            QMessageBox warning;
            warning.setIcon(QMessageBox::Critical);
            warning.setWindowTitle("Impossibile inviare richiesta");
            warning.setText("E' necessario compilare tutti i campi correttamente.");
            warning.setStandardButtons(QMessageBox::Ok);
            warning.setDefaultButton(QMessageBox::Ok);
            warning.exec();
        }
        else if(username->text()==admin->Getusername() && password->text()==admin->Getpassword())
                {aggiorna_vista(); emit show_accedi();}

}
void homewindow::slot_accedi_utente() {

    if(username->text().isEmpty() || password->text().isEmpty())
    {
            QMessageBox warning;
            warning.setIcon(QMessageBox::Critical);
            warning.setWindowTitle("Impossibile inviare richiesta");
            warning.setText("E' necessario compilare tutti i campi correttamente.");
            warning.setStandardButtons(QMessageBox::Ok);
            warning.setDefaultButton(QMessageBox::Ok);
            warning.exec();
        }
        else{
       //amministratore controlla se esiste l'utente:
        bool trovato=false;
       int id=admin->autenticaUtente(username->text().toInt(),password->text(), trovato);
        if(trovato==false)
        {
            QMessageBox warning;
            warning.setIcon(QMessageBox::Critical);
            warning.setWindowTitle("Impossibile inviare richiesta");
            warning.setText("Errore ID o password non corretti");
            warning.setStandardButtons(QMessageBox::Ok);
            warning.setDefaultButton(QMessageBox::Ok);
            warning.exec();
            aggiorna_vista();

        }
        else { emit show_accedi_utente(id);}

    }
}


void homewindow::creaLayout(){
    gridlogin->addWidget(us,0,0);
    gridlogin->addWidget(passw,0,1);
    gridlogin->addWidget(username,1,0);
    gridlogin->addWidget(password,1,1);
    layout->addLayout(gridlogin);
    layout->addWidget(accedicomeadmin);
    layout->addWidget(accedicomeutente);

    layout->addWidget(exit);
    setLayout(layout);

}

void homewindow::abilita_pulsanti_home() {
    accedicomeadmin->setEnabled(true);
    accedicomeutente->setEnabled(true);
    exit->setEnabled(true);
}

void homewindow::disabilita_pulsanti_home() {
    accedicomeadmin->setEnabled(false);
    accedicomeutente->setEnabled(false);
    exit->setEnabled(false);
}



void homewindow::closeEvent(QCloseEvent*){ emit chiudi_app(); }

homewindow::~homewindow(){

    delete accedicomeadmin;
    delete exit;
    delete gridlogin;
    delete accedicomeutente;
    delete username;
    delete password;
}





