#include "dettagli_opera.h"

dettagli_opera::dettagli_opera(int ID, database* db,database_utente* udb,database_utente_opere* uodb) : id(ID) , Widget_Padre(db,udb,uodb)
{
    registra();
    //set lable
       submit=new QPushButton("CONFERMA");
       t=new QLabel("TITOLO:");
       p=new QLabel("PRESTITO:");
       i=new QLabel("ID:");
       c=new QLabel("IN SEDE:");

    //set QLineEdit
       titolo=new QLineEdit();
       prestito=new QLineEdit();
       identificativo=new QLineEdit();
       consultabile=new QLineEdit();

       //creo i layout manager
        grid=new QGridLayout;
        layout=new QVBoxLayout;

       //setto i laypput manager
        grid->addWidget(t,0,0);
        grid->addWidget(titolo,0,1);
        grid->addWidget(i,2,0);
        grid->addWidget(identificativo,2,1);
        grid->addWidget(p,3,0);
        grid->addWidget(prestito,3,1);
        grid->addWidget(c,4,0);
        grid->addWidget(consultabile,4,1);
        layout->addLayout(grid);
        layout->addWidget(submit);
        setLayout(layout);

}

void dettagli_opera::set_style(){
    Widget_Padre::set_style();
    resize(300,250);
    paletteLine=new QPalette();
    paletteLine->setColor(QPalette::Text,"#4c4c4c");
    paletteLine->setColor(QPalette::Base,"#f2f1f0");

    titolo->setPalette(*paletteLine);
    prestito->setPalette(*paletteLine);
    identificativo->setPalette(*paletteLine);
    consultabile->setPalette(*paletteLine);
}

void dettagli_opera::costruisci_contenuto(){
    info_opera info_Op=(get_model())->get_infoOpera(id);

    titolo->setText(info_Op.get_titolo());
    prestito->setText(info_Op.get_stato());
    identificativo->setText(info_Op.get_ID());
    consultabile->setText(info_Op.is_consultabile());
}

void dettagli_opera::disabilita_modifica(){
      titolo->setEnabled(false);
      prestito->setEnabled(false);
      identificativo->setEnabled(false);
      consultabile->setEnabled(false);
}

void dettagli_opera::abilita_modifica(){
      titolo->setEnabled(true);
      prestito->setEnabled(false);
      identificativo->setEnabled(false);
      consultabile->setEnabled(false);
}


int dettagli_opera::get_ID()const{ return id; }

QLineEdit* dettagli_opera::Gettitolo() const {return titolo;}

QPalette* dettagli_opera::get_paletteLine()const{ return paletteLine; }

QGridLayout* dettagli_opera::get_grid()const{ return grid; }

QPushButton* dettagli_opera::get_submit() const {return submit;}

void dettagli_opera::aggiorna_vista(){
    info_opera info_Op=(get_model())->get_infoOpera(id);
    prestito->setText(info_Op.get_stato());
    consultabile->setText(info_Op.is_consultabile());
}




void dettagli_opera::closeEvent(QCloseEvent *event){
    emit chiudi_dettagli_opera();
}


dettagli_opera::~dettagli_opera(){
    elimina_registrazione();

    delete paletteLine;
    delete grid;
    delete layout;
    delete submit;

    delete t;                  //titolo
    delete p;                  //prestito
    delete i;                  //id
    delete c;                  //disponibilità

    delete titolo;
    delete prestito;
    delete identificativo;
    delete consultabile;
}

void dettagli_opera::registra() const{ get_model()->add_registro(const_cast<dettagli_opera*> (this)); }

void dettagli_opera::elimina_registrazione() const { get_model()->remove_registro(const_cast<dettagli_opera*> (this)); }
