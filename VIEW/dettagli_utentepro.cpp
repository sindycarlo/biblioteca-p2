#include "dettagli_utente_pro.h"
#include <QPalette>
dettagli_utente_pro::dettagli_utente_pro(int Id, database* db,database_utente*udb,database_utente_opere*uodb) : dettagli_utente(Id,db,udb,uodb)
{

    setWindowTitle("Dettagli utente PRO");

    tempoprestito=new QLabel("TEMPO PRESTITO OPERA:");

    tempop=new QLineEdit();


    get_grid()->addWidget(tempoprestito,1,0);
    get_grid()->addWidget(tempop,1,1);
    setLayout(get_grid());
    abilita_modifica();
    set_style();
    costruisci_contenuto();
    connect(get_submit(),SIGNAL(clicked()),this,SLOT(slot_submit()));
}

void dettagli_utente_pro::costruisci_contenuto(){
     dettagli_utente::costruisci_contenuto();
     info_utente info_upro=(get_modelutenti())->get_infoUtente(get_ID());
     tempop->setText(info_upro.get_dettaglio());


}
void dettagli_utente_pro::slot_submit(){
    if(Getnome()->text().isEmpty() || Getnome()->text().isNull() ||  Getcognome()->text().isEmpty() || Getcognome()->text().isNull())
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
            warning.setText("Sei sicuro di voler modificare l'utente <b>"+Getnome()->text()+"</b>");
            warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
            warning.setDefaultButton(QMessageBox::Cancel);
            int ret = warning.exec();
            if(ret==QMessageBox::Yes) {
            emit modifica_utente(Getnome()->text(),Getcognome()->text(),get_ID());
            }
            }

}

void dettagli_utente_pro::set_style(){
    dettagli_utente::set_style();
    tempoprestito->setPalette(*get_paletteLine());
}


void dettagli_utente_pro::disabilita_modifica(){
      dettagli_utente::disabilita_modifica();
      tempop->setEnabled(false);
}

void dettagli_utente_pro::abilita_modifica(){
      dettagli_utente::abilita_modifica();
      tempop->setEnabled(false);
}


dettagli_utente_pro::~dettagli_utente_pro(){
    delete tempop;
    delete tempoprestito;
}
