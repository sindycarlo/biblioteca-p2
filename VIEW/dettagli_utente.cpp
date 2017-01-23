#include "dettagli_utente.h"

dettagli_utente::dettagli_utente(int ID, database* db,database_utente* udb,database_utente_opere* uodb) : idutente(ID) , Widget_Padre(db,udb,uodb)
{
    registra_utente();
    //set lable
       submit=new QPushButton("CONFERMA");
       n=new QLabel("NOME:");
       c=new QLabel("COGNOME:");
       id=new QLabel("ID:");
       cf=new QLabel("CODICE FISCALE:");
       ps=new QLabel("PASSWORD:");

    //set QLineEdit
       nome=new QLineEdit();
       cognome=new QLineEdit();
       identificativo=new QLineEdit();
       codicefiscale=new QLineEdit();
       password=new QLineEdit();

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
        layout->addLayout(grid);
        layout->addWidget(submit);
        setLayout(layout);
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
}

void dettagli_utente::costruisci_contenuto(){
    info_utente info_ut=(get_modelutenti())->get_infoUtente(idutente);

    nome->setText(info_ut.get_nome());
    cognome->setText(info_ut.get_cognome());
    identificativo->setText(info_ut.get_ID());
    codicefiscale->setText(info_ut.get_codicefiscale());
    password->setText(info_ut.get_password());
}

void dettagli_utente::disabilita_modifica(){
      nome->setEnabled(false);
      cognome->setEnabled(false);
      identificativo->setEnabled(false);
      codicefiscale->setEnabled(false);
      password->setEnabled(false);
}

int dettagli_utente::get_ID()const{ return idutente; }

QPalette* dettagli_utente::get_paletteLine()const{ return paletteLine; }

QGridLayout* dettagli_utente::get_grid()const{ return grid; }

void dettagli_utente::aggiorna_vista(){
    info_utente info_u=(get_modelutenti())->get_infoUtente(idutente);
    //da definire!!!
}

void dettagli_utente::abilita_modifica(){
    nome->setEnabled(true);
    cognome->setEnabled(true);
    identificativo->setEnabled(false);
    codicefiscale->setEnabled(false);
    password->setEnabled(false);

}

QPushButton* dettagli_utente::get_submit() const {return submit;}

QLineEdit* dettagli_utente::Getnome() const {return nome;}
QLineEdit* dettagli_utente::Getcognome() const {return cognome;}


void dettagli_utente::closeEvent(QCloseEvent *event){
    emit chiudi_dettagli_utente();
}


dettagli_utente::~dettagli_utente(){
    elimina_registrazione_utente();

    delete paletteLine;
    delete grid;
    delete layout;
    delete submit;

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
}

void dettagli_utente::registra_utente() const{ get_modelutenti()->add_registro_utente(const_cast<dettagli_utente*> (this)); }

void dettagli_utente::elimina_registrazione_utente() const { get_modelutenti()->remove_registro_utente(const_cast<dettagli_utente*> (this)); }
