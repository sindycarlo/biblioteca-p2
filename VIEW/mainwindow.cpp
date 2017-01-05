#include "mainwindow.h"
#include<QApplication>
#include<QToolTip>
mainWindow::mainWindow(database* db) : Widget_Padre(db) {

    tab=new listaOp(get_model());   //tabella con l'elenco delle opere

    controllerOP=new C_listaop(get_model(),tab);

  //bottoni
    exit=new QPushButton("ESCI");
    presta_rientra=new QPushButton("PRESTA / RIENTRA");
    aggiungi_rivista=new QPushButton("AGGIUNGI RIVISTA");
    aggiungi_libro=new QPushButton("AGGIUNGI LIBRO");
    rimuovi_opera=new QPushButton("RIMUOVI OPERA");
    disabilita_bottoni();

  //barra della ricerca
    barra_cerca=new QLineEdit();

  //layout
    orizzontale=new QHBoxLayout();
    Prlayout=new QVBoxLayout();
    bottoni=new QVBoxLayout();

    costruisci_contenuto();   
    creaLayout();
    set_style();

    connect(tab,SIGNAL(selezione(int)),this,SLOT(modifica_campo(int)));
    connect(rimuovi_opera,SIGNAL(clicked()),this,SLOT(rimuovi_segnale()));
    connect(presta_rientra,SIGNAL(clicked()),this,SLOT(slot_aggiorna_prestito()));
    connect(aggiungi_rivista,SIGNAL(clicked()),this,SLOT(slot_inserisci_rivista()));
    connect(aggiungi_libro,SIGNAL(clicked()),this,SLOT(slot_inserisci_libro()));
    connect(exit,SIGNAL(clicked()),qApp,SLOT(quit()));
    connect(barra_cerca,SIGNAL(textEdited(QString)),this,SLOT(testo_editato(const QString& )));

}

void mainWindow::set_style(){
    Widget_Padre::set_style();
    barra_cerca->setPlaceholderText("Ricerca per: Titolo, Autore, Anno di uscita, ID");
    barra_cerca->setToolTip("Eliminare il contenuto della barra per tornare all'elenco completo delle opere");
    tab->setToolTip("Doppio click per visualizzare i dettagli dell'opera");
    presta_rientra->setToolTip("Funzione disponibile se si seleziona un' opera con un click");
    barra_cerca->setToolTipDuration(5000);
    barra_cerca->setToolTipDuration(5000);
    barra_cerca->setToolTipDuration(5000);

}

void mainWindow::costruisci_contenuto(){
     aggiorna_vista();
}

void mainWindow::creaLayout(){

    bottoni->addWidget(presta_rientra);
    bottoni->addWidget(aggiungi_libro);
    bottoni->addWidget(aggiungi_rivista);
    bottoni->addWidget(rimuovi_opera);

    orizzontale->addWidget(tab);
    orizzontale->addLayout(bottoni);

    Prlayout->addWidget(barra_cerca);
    Prlayout->addLayout(orizzontale);
    Prlayout->addWidget(exit);
    setLayout(Prlayout);

}

void mainWindow::modifica_campo(int ID){
    opera_selezionata=ID;
    abilita_bottoni();

}

void mainWindow::rimuovi_segnale(){
    QString identificativo;
    identificativo.setNum(opera_selezionata);
    QMessageBox warning;
        warning.setIcon(QMessageBox::Question);
        warning.setWindowTitle("Rimuovi Opera");
        warning.setText("Hai selezionato l'opera con ID: <b>"+identificativo+"</b>");
        warning.setInformativeText("Vuoi veramente eliminare questa opera?");
        warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        warning.setDefaultButton(QMessageBox::Cancel);
        int ret = warning.exec();
        if(ret==QMessageBox::Yes) {
            emit rimuovi(opera_selezionata);
        }
}


void mainWindow::testo_editato(const QString& text){ emit cerca_opera(text); }

void mainWindow::slot_inserisci_rivista(){
    emit show_inserisci_rivista();
}

void mainWindow::slot_inserisci_libro(){
    emit show_inserisci_libro();
}


void mainWindow::disabilita(){
    disabilita_bottoni();
}

void mainWindow::slot_aggiorna_prestito(){

 /*   info_opera infoOP=(get_model()->(opera_selezionata);
    QString identificativo,stato;
    identificativo.setNum(opera_selezionata);

    if(infoOP.is_consultabile()=="si") stato="prestare";
    else stato="ricevere";

    QMessageBox warning;
        warning.setIcon(QMessageBox::Question);
        warning.setWindowTitle("Aggiornamento del prestito");
        warning.setText("Hai selezionato l'opera con ID: <b>"+identificativo+"</b>");
        warning.setInformativeText("Vuoi veramente "+stato+ " questa opera?");
        warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        warning.setDefaultButton(QMessageBox::Cancel);
        int ret = warning.exec();
        if(ret==QMessageBox::Yes)
        {
            (get_model())->aggiorna_view();
            emit aggiorna_prestito(opera_selezionata);
        }
        */
}


void mainWindow::costruisci_Tabella(const contenitore<opera>& lista){ tab->build_Nuova(lista); }

void mainWindow::aggiorna_vista(){ tab->aggiorna_vista(); }

void mainWindow::abilita_bottoni(){
    rimuovi_opera->setEnabled(true);
    presta_rientra->setEnabled(true);
}

void mainWindow::disabilita_bottoni(){
   rimuovi_opera->setEnabled(false);
   presta_rientra->setEnabled(false);
}


void mainWindow::closeEvent(QCloseEvent *event){ emit chiudi_app(); }


mainWindow::~mainWindow(){
    delete bottoni;
    delete orizzontale;
    delete Prlayout;
    delete rimuovi_opera;
    delete tab;
    delete presta_rientra;
    delete controllerOP;
    delete aggiungi_libro;
    delete barra_cerca;
    delete aggiungi_rivista;
    delete exit;
}





