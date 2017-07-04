#include "inserisci_libro.h"

inserisci_Libro::inserisci_Libro(QWidget *parent) : QWidget(parent){
    submit=new QPushButton("CONFERMA");
    exit= new QPushButton("ESCI");

    t=new QLabel("TITOLO:");
    a=new QLabel("AUTORE");

    titolo=new QLineEdit();
    autore=new QLineEdit();

    grid=new QGridLayout();
    layout=new QVBoxLayout();

    build_Layout();
    connect(submit,SIGNAL(clicked()),this,SLOT(slot_submit()));
    connect(exit,SIGNAL(clicked()),this,SLOT(chiudi()));
}


void inserisci_Libro::build_Layout(){

    grid->addWidget(t,0,0); grid->addWidget(titolo,0,1);
    grid->addWidget(a,1,0); grid->addWidget(autore,1,1);

    layout->addLayout(grid);
    layout->addWidget(submit);
    layout->addWidget(exit);

    setLayout(layout);
}


void inserisci_Libro::slot_submit(){
    if(titolo->text().isEmpty() || autore->text().isEmpty())
    {
            QMessageBox warning;
            warning.setIcon(QMessageBox::Critical);
            warning.setWindowTitle("Impossibile inserire una nuova rivista");
            warning.setText("E' necessario compilare tutti i campi.");
            warning.setStandardButtons(QMessageBox::Ok);
            warning.setDefaultButton(QMessageBox::Ok);
            warning.exec();
        }
        else{
            QMessageBox warning;
            warning.setIcon(QMessageBox::Question);
            warning.setWindowTitle("Inserisci nuovo libro");
            warning.setText("Sei sicuro di voler inserire il libro <b>"+titolo->text()+"</b>");
            warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            warning.setDefaultButton(QMessageBox::Yes);
            int ret = warning.exec();
            if(ret==QMessageBox::Yes) {
                info_opera op(titolo->text(),"disponibile","",autore->text(),"presente");
                emit submitL(op);
                pulisci_Campi();
                chiudi();
            }
            }
}
void inserisci_Libro::pulisci_Campi(){
    titolo->clear();
    autore->clear();
}

void inserisci_Libro::chiudi() {

    emit  chiudi_aggiungi_Libro();
}

void inserisci_Libro::closeEvent(QCloseEvent*){
    emit chiudi_aggiungi_Libro();
}

inserisci_Libro::~inserisci_Libro(){
     delete grid;
     delete layout;

     delete submit;
     delete exit;

     delete t;
     delete a;

     delete titolo;
     delete autore;
 }
