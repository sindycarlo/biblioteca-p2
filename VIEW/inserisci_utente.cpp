#include "inserisci_utente.h"

inserisci_utente::inserisci_utente(QWidget *parent) : QWidget(parent){
    submit=new QPushButton("CONFERMA");
    exit=new QPushButton("ESCI");

    n=new QLabel("NOME:");
    co=new QLabel("COGNOME:");
    cf=new QLabel("CODICEFISCALE:");
    psw=new QLabel("PASSWORD:");
    tipoutente=new QLabel("TIPO UTENTE");


    nome=new QLineEdit();
    cognome=new QLineEdit();
    codicefiscale=new QLineEdit();
    password=new QLineEdit();

    tipu= new QComboBox();
    tipu->addItem("Utente Basic");
    tipu->addItem("Utente Pro");

    grid=new QGridLayout();
    layout=new QVBoxLayout();

    build_Layout();
    connect(submit,SIGNAL(clicked()),this,SLOT(slot_submit()));
    connect(exit,SIGNAL(clicked()),this,SLOT(chiudi()));
}


void inserisci_utente::build_Layout(){

    grid->addWidget(n,0,0); grid->addWidget(nome,0,1);
    grid->addWidget(co,1,0); grid->addWidget(cognome,1,1);
    grid->addWidget(cf,2,0); grid->addWidget(codicefiscale,2,1);
    grid->addWidget(psw,3,0); grid->addWidget(password,3,1);
    grid->addWidget(tipoutente,4,0); grid->addWidget(tipu,4,1);
    layout->addLayout(grid);
    layout->addWidget(submit);
    layout->addWidget(exit);

    setLayout(layout);
}


void inserisci_utente::slot_submit(){
    QRegExp re("\\d*");
    if(nome->text().isEmpty() || nome->text().isNull() ||  cognome->text().isEmpty() || cognome->text().isNull()
              ||codicefiscale->text().isEmpty() || codicefiscale->text().isNull()
            ||password->text().isEmpty() || password->text().isNull()
            )
    {
            QMessageBox warning;
            warning.setIcon(QMessageBox::Critical);
            warning.setWindowTitle("Impossibile inserire un nuovo utente");
            warning.setText("E' necessario compilare tutti i campi.");
            warning.setStandardButtons(QMessageBox::Ok);
            warning.setDefaultButton(QMessageBox::Ok);
            warning.exec();
        }
        else {
        QMessageBox warning;
        warning.setIcon(QMessageBox::Question);
        warning.setWindowTitle("Inserisci nuovo utente ");
        warning.setText("Sei sicuro di voler inserire l'utente  <b>"+nome->text()+"</b>");
        warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        warning.setDefaultButton(QMessageBox::Cancel);
        int ret = warning.exec();
        if(ret==QMessageBox::Yes) {
            info_utente u(0,nome->text(),cognome->text(),"",password->text(),codicefiscale->text(),0,tipu->currentText());
            emit submitu(u);
            pulisci_Campi();
            chiudi();
            }
    }
}
void inserisci_utente::pulisci_Campi(){
    nome->clear();
    cognome->clear();
    codicefiscale->clear();
    password->clear();
}

void inserisci_utente::chiudi() {
    emit chiudi_aggiungi_utente();
}

void inserisci_utente::closeEvent(QCloseEvent*){
    emit chiudi_aggiungi_utente();
}

inserisci_utente::~inserisci_utente(){
     delete grid;
     delete layout;

     delete submit;
     delete exit;

    delete tipu;
    delete tipoutente;

     delete n;
     delete co;
     delete cf;
     delete psw;


     delete nome;
     delete cognome;
     delete codicefiscale;
     delete password;

 }
