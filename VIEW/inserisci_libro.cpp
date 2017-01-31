#include "inserisci_libro.h"

inserisci_Libro::inserisci_Libro(QWidget *parent) : QWidget(parent){
    submit=new QPushButton("CONFERMA");

    t=new QLabel("TITOLO:");
    a=new QLabel("AUTORE");

    titolo=new QLineEdit();
    autore=new QLineEdit();

    grid=new QGridLayout();
    layout=new QVBoxLayout();

    build_Layout();
    centra_finestra();
    connect(submit,SIGNAL(clicked()),this,SLOT(slot_submit()));
}


void inserisci_Libro::build_Layout(){

    grid->addWidget(t,0,0); grid->addWidget(titolo,0,1);
    grid->addWidget(a,1,0); grid->addWidget(autore,1,1);

    layout->addLayout(grid);
    layout->addWidget(submit);

    setLayout(layout);
}


void inserisci_Libro::slot_submit(){
    if(titolo->text().isEmpty() || titolo->text().isNull() ||  autore->text().isEmpty() || autore->text().isNull())
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
            warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
            warning.setDefaultButton(QMessageBox::Cancel);
            int ret = warning.exec();
            if(ret==QMessageBox::Yes) {
                info_opera op(titolo->text(),"","",autore->text(),"");
                emit submitL(op);
                pulisci_Campi();
            }
            }
}
void inserisci_Libro::pulisci_Campi(){
    titolo->clear();
    autore->clear();
}

void inserisci_Libro::centra_finestra(){
       int width = frameGeometry().width();
       int height = frameGeometry().height();

       QDesktopWidget wid;

       int screenWidth = wid.screen()->width();
       int screenHeight = wid.screen()->height();

       int x=static_cast<int>((screenWidth-width)/2);
       int y=static_cast<int>((screenHeight-height)/2);

       move(x,y);
}

void inserisci_Libro::closeEvent(QCloseEvent* event){
    emit chiudi_aggiungi_Libro();
}

inserisci_Libro::~inserisci_Libro(){
     delete grid;
     delete layout;

     delete submit;

     delete t;
     delete a;

     delete titolo;
     delete autore;
 }
