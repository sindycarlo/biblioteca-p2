#include "dettagli_utente.h"

dettagli_utente::dettagli_utente(int ID, database* db,database_utente* udb,database_utente_opere* uodb) :Widget_Padre(db,udb,uodb),idutente(ID)
{
    setWindowTitle("Dettagli utente");
    //set lable
       submit=new QPushButton("CONFERMA");
       exit=new QPushButton("ESCI");
       n=new QLabel("NOME:");
       c=new QLabel("COGNOME:");
       id=new QLabel("ID:");
       cf=new QLabel("CODICE FISCALE:");
       ps=new QLabel("PASSWORD:");
       Numop=new QLabel("NUMERO OPERE IN PRESTITO:");
       tuser=new QLabel("TIPO UTENTE");


    //set QLineEdit
       nome=new QLineEdit();
       cognome=new QLineEdit();
       identificativo=new QLineEdit();
       codicefiscale=new QLineEdit();
       password=new QLineEdit();
       Numopere=new QLineEdit();
       tipoutente=new QLineEdit();

       //creo i layout manager
        grid=new QGridLayout;
         layout=new QVBoxLayout;

       //setto i laypput manager
        grid->addWidget(n,0,0);
        grid->addWidget(nome,0,1);
        grid->addWidget(c,2,0);
        grid->addWidget(cognome,2,1);
        grid->addWidget(id,3,0);
        grid->addWidget(identificativo,3,1);
        grid->addWidget(cf,4,0);
        grid->addWidget(codicefiscale,4,1);
        grid->addWidget(ps,5,0);
        grid->addWidget(password,5,1);
        grid->addWidget(Numop,6,0);
        grid->addWidget(Numopere,6,1);
        grid->addWidget(tuser,7,0);
        grid->addWidget(tipoutente,7,1);
        layout->addLayout(grid);
        layout->addWidget(submit);
        layout->addWidget(exit);
        setLayout(layout);

        abilita_modifica();
        set_style();
        costruisci_contenuto();
        connect(submit,SIGNAL(clicked()),this,SLOT(slot_submit()));
        connect(exit,SIGNAL(clicked()),this,SLOT(esci()));

}

void dettagli_utente::set_style(){
    Widget_Padre::set_style();
    resize(300,250);
    paletteLine=new QPalette();
    paletteLine->setColor(QPalette::Text,"#4c4c4c");
    paletteLine->setColor(QPalette::Base,"#f2f1f0");

    nome->setPalette(*paletteLine);
    cognome->setPalette(*paletteLine);
    identificativo->setPalette(*paletteLine);
    codicefiscale->setPalette(*paletteLine);
    password->setPalette(*paletteLine);
    Numopere->setPalette(*paletteLine);
    tipoutente->setPalette(*paletteLine);
}

void dettagli_utente::costruisci_contenuto(){
    info_utente info_ut=(get_modelutenti())->get_infoUtente(idutente);
    utente* u=get_modelutenti()->trova_utente(idutente);
    QString tipo=u->Get_tipo_utente();
    nome->setText(info_ut.get_nome());
    cognome->setText(info_ut.get_cognome());
    identificativo->setText(info_ut.get_ID());
    codicefiscale->setText(info_ut.get_codicefiscale());
    password->setText(info_ut.get_password());
    Numopere->setText(info_ut.get_dettaglio());
    tipoutente->setText(tipo);

}

void dettagli_utente::disabilita_modifica(){
      nome->setEnabled(false);
      cognome->setEnabled(false);
      identificativo->setEnabled(false);
      codicefiscale->setEnabled(false);
      password->setEnabled(false);
      Numopere->setEnabled(false);
      tipoutente->setEnabled(false);

}
void dettagli_utente::slot_submit(){
    if(nome->text().isEmpty() || nome->text().isNull() ||  cognome->text().isEmpty() || cognome->text().isNull())
    {
            QMessageBox warning;
            warning.setIcon(QMessageBox::Critical);
            warning.setWindowTitle("Impossibile modificare l'utente");
            warning.setText("E' necessario compilare tutti i campi.");
            warning.setStandardButtons(QMessageBox::Ok);
            warning.setDefaultButton(QMessageBox::Ok);
            warning.exec();
        }
        else{
            QMessageBox warning;
            warning.setIcon(QMessageBox::Question);
            warning.setWindowTitle("Modifica a utente");
            warning.setText("Sei sicuro di voler modificare l'utente <b>"+nome->text()+"</b>");
            warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
            warning.setDefaultButton(QMessageBox::Cancel);
            int ret = warning.exec();
            if(ret==QMessageBox::Yes) {
            emit modifica_utente(nome->text(),cognome->text(),identificativo->text().toInt());
            }
            }

}

void dettagli_utente::esci() {
    emit chiudi_dettagli_utente();
}



void dettagli_utente::aggiorna_vista(){
    info_utente info_u=(get_modelutenti())->get_infoUtente(idutente);
    nome->setText(info_u.get_nome());
    cognome->setText(info_u.get_cognome());
}

void dettagli_utente::abilita_modifica(){
    nome->setEnabled(true);
    cognome->setEnabled(true);
    identificativo->setEnabled(false);
    codicefiscale->setEnabled(false);
    password->setEnabled(false);
    Numopere->setEnabled(false);
    tipoutente->setEnabled(false);

}



void dettagli_utente::closeEvent(QCloseEvent*){
    emit chiudi_dettagli_utente();
}


dettagli_utente::~dettagli_utente(){


    delete paletteLine;
    delete grid;
    delete layout;
    delete tuser;
    delete submit;
    delete exit;

    delete n;
    delete c;
    delete cf;
    delete id;
    delete ps;

    delete nome;
    delete cognome;
    delete identificativo;
    delete codicefiscale;
    delete password;
    delete Numop;
    delete Numopere;
    delete tipoutente;
}
