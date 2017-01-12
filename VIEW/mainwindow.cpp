#include "mainwindow.h"
#include<QApplication>
#include<QToolTip>
mainWindow::mainWindow(database* db,database_utente* udb,database_utente_opere*uodb) : Widget_Padre(db,udb,uodb) {
    //da correggere
    tablibri=new listalibri(0,get_model(),get_modelutenti(),get_modelutenteopere());   //tabella con l'elenco delle opere
    tabriviste=new listariviste(0,get_model(),get_modelutenti(),get_modelutenteopere());
    tabutenti=new listautenti(get_model(),get_modelutenti(),get_modelutenteopere());
    controllerLP=new C_listalibri(get_model(),tablibri);
    controllerRP=new C_listariviste(get_model(),tabriviste);
    controllerUTENTI=new C_listautenti(get_modelutenti(),tabutenti);
  //bottoni
    exit=new QPushButton("ESCI");
    aggiungi_rivista=new QPushButton("AGGIUNGI RIVISTA");
    aggiungi_libro=new QPushButton("AGGIUNGI LIBRO");
    rimuovi_opera=new QPushButton("RIMUOVI OPERA");
    rimuovi_utenti=new QPushButton("RIMUOVI UTENTE");
    aggiungi_utente_basic=new QPushButton("AGGIUNGI UTENTE BASIC");
    aggiungi_utente_pro=new QPushButton("AGGIUNGI UTENTE PRO");
    disabilita_bottoni();
    disabilita_bottoni_utenti();

  //barra della ricerca
    barra_cerca=new QLineEdit();
    barra_cercautenti=new QLineEdit();

  //layout
    orizzontale=new QHBoxLayout();
    Prlayout=new QVBoxLayout();
    bottoni=new QVBoxLayout();

    costruisci_contenuto();   
    creaLayout();
    set_style();

    connect(tablibri,SIGNAL(selezione(int)),this,SLOT(modifica_campo(int)));
    connect(tabriviste,SIGNAL(selezione(int)),this,SLOT(modifica_campo(int)));
    connect(tabutenti,SIGNAL(selezione_utenti(int)),this,SLOT(modifica_campo_utenti(int)));
    connect(rimuovi_opera,SIGNAL(clicked()),this,SLOT(rimuovi_segnale()));
    connect(rimuovi_utenti,SIGNAL(clicked()),this,SLOT(rimuovi_segnale_utenti()));
    connect(aggiungi_rivista,SIGNAL(clicked()),this,SLOT(slot_inserisci_rivista()));
    connect(aggiungi_libro,SIGNAL(clicked()),this,SLOT(slot_inserisci_libro()));
    connect(aggiungi_utente_basic,SIGNAL(clicked()),this,SLOT(slot_inserisci_utentebasic()));
    connect(aggiungi_utente_pro,SIGNAL(clicked()),this,SLOT(slot_inserisci_utentepro()));
    connect(exit,SIGNAL(clicked()),qApp,SLOT(quit()));
    connect(barra_cerca,SIGNAL(textEdited(QString)),this,SLOT(testo_editato(const QString& )));
    connect(barra_cercautenti,SIGNAL(textEdited(QString)),this,SLOT(testo_editato(const QString& )));
}

void mainWindow::set_style(){
    Widget_Padre::set_style();
    barra_cerca->setPlaceholderText("Ricerca per: Titolo, Autore, Anno di uscita, ID");
    barra_cerca->setToolTip("Eliminare il contenuto della barra per tornare all'elenco completo delle opere");
    barra_cercautenti->setPlaceholderText("Ricerca per: Nome, Cognome, ID");
    barra_cercautenti->setToolTip("Eliminare il contenuto della barra per tornare all'elenco completo degli utenti");
    tablibri->setToolTip("Doppio click per visualizzare i dettagli dell'opera");
    tabutenti->setToolTip("Doppio click per visualizzare i dettagli dell'utente");
    barra_cerca->setToolTipDuration(5000);
    barra_cerca->setToolTipDuration(5000);
    barra_cerca->setToolTipDuration(5000);
    barra_cercautenti->setToolTipDuration(5000);
    barra_cercautenti->setToolTipDuration(5000);
    barra_cercautenti->setToolTipDuration(5000);

}

void mainWindow::costruisci_contenuto(){
     aggiorna_vista();
}

void mainWindow::creaLayout(){

    bottoni->addWidget(aggiungi_libro);
    bottoni->addWidget(aggiungi_rivista);
    bottoni->addWidget(rimuovi_opera);
    bottoni->addWidget(rimuovi_utenti);
    bottoni->addWidget(aggiungi_utente_basic);
    bottoni->addWidget(aggiungi_utente_pro);

    orizzontale->addWidget(tablibri);
    orizzontale->addWidget(tabriviste);
    orizzontale->addWidget(tabutenti);
    orizzontale->addLayout(bottoni);

    Prlayout->addWidget(barra_cerca);
    Prlayout->addWidget(barra_cercautenti);
    Prlayout->addLayout(orizzontale);
    Prlayout->addWidget(exit);
    setLayout(Prlayout);

}

void mainWindow::modifica_campo(int ID){
    opera_selezionata=ID;
    abilita_bottoni();
    disabilita_bottoni_utenti();

}

void mainWindow::modifica_campo_utenti(int ID){
    utente_selezionato=ID;
    abilita_bottoni_utenti();
    disabilita_bottoni();

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
void mainWindow::rimuovi_segnale_utenti(){
    QString identificativo;
    identificativo.setNum(utente_selezionato);
    QMessageBox warning;
        warning.setIcon(QMessageBox::Question);
        warning.setWindowTitle("Rimuovi Utente");
        warning.setText("Hai selezionato l'utente con ID: <b>"+identificativo+"</b>");
        warning.setInformativeText("Vuoi veramente eliminare questo utente?");
        warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        warning.setDefaultButton(QMessageBox::Cancel);
        int ret = warning.exec();
        if(ret==QMessageBox::Yes) {
            emit rimuovi_utente(utente_selezionato);
        }
}


void mainWindow::testo_editato(const QString& text){ emit cerca_opera(text); }

void mainWindow::testo_editato_utenti(const QString& text){ emit cerca_utente(text); }

void mainWindow::slot_inserisci_rivista(){
    emit show_inserisci_rivista();
}

void mainWindow::slot_inserisci_libro(){
    emit show_inserisci_libro();
}
void mainWindow::slot_inserisci_utentebasic(){
    emit show_inserisci_utentebasic();
}
void mainWindow::slot_inserisci_utentepro(){
    emit show_inserisci_utentepro();
}


void mainWindow::disabilita(){
    disabilita_bottoni();
}


void mainWindow::costruisci_Tabella(const contenitore<opera>& lista){ tablibri->build_Nuova(lista); tabriviste->build_Nuova(lista);}
void mainWindow::costruisci_Tabellautenti(const contenitore<utente> & listautenti) {tabutenti->build_Nuova(listautenti);}
void mainWindow::aggiorna_vista(){tablibri->aggiorna_vista();tabriviste->aggiorna_vista();tabutenti->aggiorna_vista();}
void mainWindow::abilita_bottoni(){
    rimuovi_opera->setEnabled(true);
}

void mainWindow::disabilita_bottoni(){
   rimuovi_opera->setEnabled(false);

}
void mainWindow::abilita_bottoni_utenti(){
    rimuovi_utenti->setEnabled(true);

}

void mainWindow::disabilita_bottoni_utenti(){
   rimuovi_utenti->setEnabled(false);

}


void mainWindow::closeEvent(QCloseEvent *event){ emit chiudi_app(); }


mainWindow::~mainWindow(){
    delete bottoni;
    delete orizzontale;
    delete Prlayout;
    delete rimuovi_opera;
    delete rimuovi_utenti;
    delete tablibri;
    delete tabriviste;
    delete controllerRP;
    delete tabutenti;
    delete controllerLP;
    delete controllerUTENTI;
    delete aggiungi_libro;
    delete barra_cerca;
    delete barra_cercautenti;
    delete aggiungi_rivista;
    delete aggiungi_utente_basic;
    delete aggiungi_utente_pro;
    delete exit;
}





