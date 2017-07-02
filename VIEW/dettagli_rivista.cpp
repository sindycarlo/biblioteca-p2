#include "dettagli_rivista.h"
#include <QPalette>
dettagli_Rivista::dettagli_Rivista(int Id, database* db,database_utente*udb) : dettagli_opera(Id,db,udb)
{

    setWindowTitle("Dettagli della rivista");
    a=new QLabel("ANNO:");

    anno=new QLineEdit();

    get_grid()->addWidget(a,1,0);
    get_grid()->addWidget(anno,1,1);

    abilita_modifica();
    costruisci_contenuto();
    set_style();
    connect(get_submit(),SIGNAL(clicked()),this,SLOT(slot_submit()));


}

void dettagli_Rivista::costruisci_contenuto(){
     dettagli_opera::costruisci_contenuto();
     info_opera iRivista=(get_model())->get_infoOpera(-1,get_ID());
     anno->setText(iRivista.get_dettaglio());
}

void dettagli_Rivista::set_style(){
    dettagli_opera::set_style();
    anno->setPalette(*get_paletteLine());
}

void dettagli_Rivista::slot_submit(){
    QRegExp re("\\d*");
    QDate time=QDate::currentDate();
    if(Gettitolo()->text().isEmpty() || Gettitolo()->text().isNull() ||  anno->text().isEmpty() || anno->text().isNull())
    {
            QMessageBox warning;
            warning.setIcon(QMessageBox::Critical);
            warning.setWindowTitle("Impossibile modificare la rivista");
            warning.setText("E' necessario compilare tutti i campi.");
            warning.setStandardButtons(QMessageBox::Ok);
            warning.setDefaultButton(QMessageBox::Ok);
            warning.exec();
        }
        else if((anno->text().toInt())>time.year() || !(re.exactMatch(anno->text()))){
                QMessageBox warning;
                warning.setIcon(QMessageBox::Critical);
                warning.setWindowTitle("Impossibile modificare la rivista");
                warning.setText("Anno di uscita non valido");
                warning.setStandardButtons(QMessageBox::Ok);
                warning.setDefaultButton(QMessageBox::Ok);
                warning.exec();
            }else {
                QMessageBox warning;
                warning.setIcon(QMessageBox::Question);
                warning.setWindowTitle("Modifica a rivista");
                warning.setText("Sei sicuro di voler modificare la rivista <b>"+Gettitolo()->text()+"</b>");
                warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
                warning.setDefaultButton(QMessageBox::Cancel);
                int ret = warning.exec();
                if(ret==QMessageBox::Yes) {
                emit modifica(Gettitolo()->text(),anno->text(),get_ID());
            }emit chiudi_dettagli_opera();
          }

}


void dettagli_Rivista::disabilita_modifica(){
      dettagli_opera::disabilita_modifica();
      anno->setEnabled(false);
}

void dettagli_Rivista::abilita_modifica(){
      dettagli_opera::abilita_modifica();
      anno->setEnabled(true);
}


dettagli_Rivista::~dettagli_Rivista(){
    delete a;
    delete anno;
}
