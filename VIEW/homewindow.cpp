#include "homewindow.h"
#include<QApplication>
#include<QToolTip>
homewindow::homewindow(database* db,database_utente* udb,database_utente_opere* uodb) : Widget_Padre(db,udb,uodb) {

    //bottoni
      exit=new QPushButton("ESCI");
      accedicomeadmin=new QPushButton("ACCEDI COME AMMINISTRATORE");
      accedicomeutente=new QPushButton("ACCEDI COME UTENTE");

    //Label
      au=new QLabel("username admin:");
      ap=new QLabel("password admin:");

      nu=new QLabel("username utente:");
      np=new QLabel("password utente:");

    //layout
      gridadmin=new QGridLayout;
      gridutente=new QGridLayout;
      layout=new QVBoxLayout;



      //campi dati richiesti ad amministratore
        adminuser=new QLineEdit();
        adminpassword=new QLineEdit();
        adminpassword->setEchoMode(QLineEdit::Password);

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
    adminuser->clear();
    adminpassword->clear();
}
void homewindow::slot_accedi() {
    if(adminuser->text().isEmpty() || adminpassword->text().isEmpty() || adminuser->text()!="admin" || adminpassword->text()!="admin")
    {
            QMessageBox warning;
            warning.setIcon(QMessageBox::Critical);
            warning.setWindowTitle("Impossibile inviare richiesta");
            warning.setText("E' necessario compilare tutti i campi correttamente.");
            warning.setStandardButtons(QMessageBox::Ok);
            warning.setDefaultButton(QMessageBox::Ok);
            warning.exec();
        }
        else if(adminuser->text()=="admin" && adminpassword->text()=="admin")
                {aggiorna_vista();emit show_accedi();}

}
void homewindow::slot_accediutente() {

    if(nameuser->text().isEmpty() || password->text().isEmpty())
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
    gridadmin->addWidget(au,0,0);
    gridadmin->addWidget(adminuser,0,1);
    gridadmin->addWidget(ap,2,0);
    gridadmin->addWidget(adminpassword,2,1);
    layout->addLayout(gridadmin);
    layout->addWidget(accedicomeadmin);


    gridutente->addWidget(nu,0,0);
    gridutente->addWidget(nameuser,0,1);
    gridutente->addWidget(np,2,0);
    gridutente->addWidget(password,2,1);
    layout->addLayout(gridutente);
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
    delete accedicomeutente;
    delete adminuser;
    delete adminpassword;
    delete nameuser;
    delete password;
}





