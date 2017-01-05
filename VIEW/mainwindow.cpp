#include "mainwindow.h"
#include<QApplication>
#include<QToolTip>
mainWindow::mainWindow(database* db,database_utente* udb) : Widget_Padre(db,udb) {

    tab=new listaOp(get_model(),get_modelutenti());   //tabella con l'elenco delle opere
    tabutenti=new listautenti(get_modelutenti());
    controllerOP=new C_listaop(get_model(),tab);
    controllerUTENTI=new C_listautenti(get_modelutenti(),tabutenti);
  //bottoni
    exit=new QPushButton("ESCI");
    presta_rientra=new QPushButton("PRESTA / RIENTRA");
    aggiungi_rivista=new QPushButton("AGGIUNGI RIVISTA");
    aggiungi_libro=new QPushButton("AGGIUNGI LIBRO");
    rimuovi_opera=new QPushButton("RIMUOVI OPERA");
    aggiungi_utente_basic=new QPushButton("AGGIUNGI UTENTE BASIC");
    aggiungi_utente_pro=new QPushButton("AGGIUNGI UTENTE PRO");
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
    connect(aggiungi_utente_basic,SIGNAL(clicked()),this,SLOT(slot_inserisci_utentebasic()));
    connect(aggiungi_utente_pro,SIGNAL(clicked()),this,SLOT(slot_inserisci_utentepro()));
    connect(exit,SIGNAL(clicked()),qApp,SLOT(quit()));
    connect(barra_cerca,SIGNAL(textEdited(QString)),this,SLOT(testo_editato(const QString& )));

}

void mainWindow::set_style(){
    Widget_Padre::set_style();
    barra_cerca->setPlaceholderText("Ricerca per: Titolo, Autore, Anno di uscita, ID");
    barra_cerca->setToolTip("Eliminare il contenuto della barra per tornare all'elenco completo delle opere");
    tab->setToolTip("Doppio click per visualizzare i dettagli dell'opera");
    tabutenti->setToolTip("Doppio click per visualizzare i dettagli dell'utente");
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
    bottoni->addWidget(aggiungi_utente_basic);
    bottoni->addWidget(aggiungi_utente_pro);

    orizzontale->addWidget(tab);
    orizzontale->addWidget(tabutenti);
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

}


void mainWindow::costruisci_Tabella(const contenitore<opera>& lista){ tab->build_Nuova(lista); }

void mainWindow::aggiorna_vista(){ tab->aggiorna_vista();tabutenti->aggiorna_vista(); }

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
    delete tabutenti;
    delete presta_rientra;
    delete controllerOP;
    delete controllerUTENTI;
    delete aggiungi_libro;
    delete barra_cerca;
    delete aggiungi_rivista;
    delete aggiungi_utente_basic;
    delete aggiungi_utente_pro;
    delete exit;
}





