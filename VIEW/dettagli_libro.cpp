#include "dettagli_libro.h"
#include <QPalette>
dettagli_Libro::dettagli_Libro(int Id, database* db,database_utente*udb,database_utente_opere*uodb) : dettagli_opera(Id,db,udb,uodb)
{

    setWindowTitle("Dettagli del libro");

    a=new QLabel("AUTORE:");

    autore=new QLineEdit();


    get_grid()->addWidget(a,1,0);
    get_grid()->addWidget(autore,1,1);

    setLayout(get_grid());
    abilita_modifica();
    set_style();
    costruisci_contenuto();
    connect(get_submit(),SIGNAL(clicked()),this,SLOT(slot_submit()));

}

void dettagli_Libro::costruisci_contenuto(){
     dettagli_opera::costruisci_contenuto();
     info_opera iLibro=(get_model())->get_infoOpera(get_ID());
     autore->setText(iLibro.get_dettaglio());


}
void dettagli_Libro::slot_submit(){
    if(Gettitolo()->text().isEmpty() || Gettitolo()->text().isNull() ||  autore->text().isEmpty() || autore->text().isNull())
    {
            QMessageBox warning;
            warning.setIcon(QMessageBox::Critical);
            warning.setWindowTitle("Impossibile modificare il libro");
            warning.setText("E' necessario compilare tutti i campi.");
            warning.setStandardButtons(QMessageBox::Ok);
            warning.setDefaultButton(QMessageBox::Ok);
            warning.exec();
        }
        else{
            QMessageBox warning;
            warning.setIcon(QMessageBox::Question);
            warning.setWindowTitle("Modifica a libro");
            warning.setText("Sei sicuro di voler modificare il libro <b>"+Gettitolo()->text()+"</b>");
            warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
            warning.setDefaultButton(QMessageBox::Cancel);
            int ret = warning.exec();
            if(ret==QMessageBox::Yes) {
            emit modifica(Gettitolo()->text(),autore->text(),get_ID());
            }
            }

}

void dettagli_Libro::set_style(){
    dettagli_opera::set_style();
    autore->setPalette(*get_paletteLine());
}


void dettagli_Libro::disabilita_modifica(){
      dettagli_opera::disabilita_modifica();
      autore->setEnabled(false);
}

void dettagli_Libro::abilita_modifica(){
      dettagli_opera::abilita_modifica();
      autore->setEnabled(true);
}


dettagli_Libro::~dettagli_Libro(){
    delete a;     //autore
    delete autore;
}
