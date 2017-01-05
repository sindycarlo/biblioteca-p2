#include "inserisci_utentepro.h"

inserisci_utentepro::inserisci_utentepro(QWidget *parent) : QWidget(parent){
    submit=new QPushButton("CONFERMA");

    n=new QLabel("NOME:");
    co=new QLabel("COGNOME:");
    cf=new QLabel("CODICEFISCALE:");
    psw=new QLabel("PASSWORD:");
    Tempp=new QLabel("TEMPO PRESTITO:");


    nome=new QLineEdit();
    cognome=new QLineEdit();
    codicefiscale=new QLineEdit();
    password=new QLineEdit();
    Tempoprestito=new QLineEdit();

    grid=new QGridLayout();
    layout=new QVBoxLayout();

    build_Layout();
    centra_finestra();
    connect(submit,SIGNAL(clicked()),this,SLOT(slot_submit()));
}


void inserisci_utentepro::build_Layout(){

    grid->addWidget(n,0,0); grid->addWidget(nome,0,1);
    grid->addWidget(co,1,0); grid->addWidget(cognome,1,1);
    grid->addWidget(cf,2,0); grid->addWidget(codicefiscale,2,2);
    grid->addWidget(psw,3,0); grid->addWidget(password,3,3);
    grid->addWidget(Tempp,4,0); grid->addWidget(Tempoprestito,4,4);
    layout->addLayout(grid);
    layout->addWidget(submit);

    setLayout(layout);
}


void inserisci_utentepro::slot_submit(){
    if(nome->text().isEmpty() || nome->text().isNull() ||  cognome->text().isEmpty() || cognome->text().isNull()
              ||codicefiscale->text().isEmpty() || codicefiscale->text().isNull()
            ||password->text().isEmpty() || password->text().isNull()
            ||Tempoprestito->text().isEmpty() || Tempoprestito->text().isNull())
    {
            QMessageBox warning;
            warning.setIcon(QMessageBox::Critical);
            warning.setWindowTitle("Impossibile inserire un nuovo utente pro");
            warning.setText("E' necessario compilare tutti i campi.");
            warning.setStandardButtons(QMessageBox::Ok);
            warning.setDefaultButton(QMessageBox::Ok);
            warning.exec();
        }
        else{
            QMessageBox warning;
            warning.setIcon(QMessageBox::Question);
            warning.setWindowTitle("Inserisci nuovo utente pro");
            warning.setText("Sei sicuro di voler inserire l'utente basic <b>"+nome->text()+"</b>");
            warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
            warning.setDefaultButton(QMessageBox::Cancel);
            int ret = warning.exec();
            if(ret==QMessageBox::Yes) {
                info_utente u(0,nome->text(),cognome->text(),"",password->text(),codicefiscale->text(),Tempoprestito->text());
                emit submitup(u);
                pulisci_Campi();
            }
            }
}
void inserisci_utentepro::pulisci_Campi(){
    nome->clear();
    cognome->clear();
    codicefiscale->clear();
    password->clear();
    Tempoprestito->clear();
}

void inserisci_utentepro::centra_finestra(){
       int width = frameGeometry().width();
       int height = frameGeometry().height();

       QDesktopWidget wid;

       int screenWidth = wid.screen()->width();
       int screenHeight = wid.screen()->height();

       int x=static_cast<int>((screenWidth-width)/2);
       int y=static_cast<int>((screenHeight-height)/2);

       move(x,y);
}

void inserisci_utentepro::closeEvent(QCloseEvent *event){
    emit chiudi_aggiungi_utentepro();
}

inserisci_utentepro::~inserisci_utentepro(){
     delete grid;
     delete layout;

     delete submit;

     delete n;
     delete co;
     delete cf;
     delete psw;
     delete Tempp;

     delete nome;
     delete cognome;
     delete codicefiscale;
     delete password;
     delete Tempoprestito;
 }
