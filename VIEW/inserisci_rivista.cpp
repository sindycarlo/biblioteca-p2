#include "inserisci_rivista.h"

inserisci_Rivista::inserisci_Rivista(QWidget *parent) : QWidget(parent){

    submit=new QPushButton("CONFERMA");
    exit= new QPushButton("ESCI");

    t=new QLabel("TITOLO:");
    a=new QLabel("ANNO DI USCITA");

    titolo=new QLineEdit();
    anno=new QLineEdit();

    grid=new QGridLayout();
    layout=new QVBoxLayout();

    build_Layout();
    connect(submit,SIGNAL(clicked()),this,SLOT(slot_submit()));
    connect(exit,SIGNAL(clicked()),this,SLOT(chiudi()));
}


void inserisci_Rivista::build_Layout(){

    grid->addWidget(t,0,0); grid->addWidget(titolo,0,1);
    grid->addWidget(a,1,0); grid->addWidget(anno,1,1);

    layout->addLayout(grid);
    layout->addWidget(submit);
    layout->addWidget(exit);

    setLayout(layout);
}


void inserisci_Rivista::slot_submit(){
    QRegExp re("\\d*");
    QDate t=QDate::currentDate();
    if(titolo->text().isEmpty() || anno->text().isEmpty())
    {
            QMessageBox warning;
            warning.setIcon(QMessageBox::Critical);
            warning.setWindowTitle("Impossibile inserire una nuova rivista");
            warning.setText("E' necessario compilare tutti i campi.");
            warning.setStandardButtons(QMessageBox::Ok);
            warning.setDefaultButton(QMessageBox::Ok);
            warning.exec();
        }else if((anno->text().toInt())>t.year() || !(re.exactMatch(anno->text()))) {
        QMessageBox warning;
        warning.setIcon(QMessageBox::Critical);
        warning.setWindowTitle("Impossibile inserire una nuova rivista");
        warning.setText("Anno di uscita della rivista non valido");
        warning.setStandardButtons(QMessageBox::Ok);
        warning.setDefaultButton(QMessageBox::Ok);
        warning.exec();
    }
    else{
            QMessageBox warning;
            warning.setIcon(QMessageBox::Question);
            warning.setWindowTitle("Inserisci nuova rivista");
            warning.setText("Sei sicuro di voler inserire la rivista <b>"+titolo->text()+"</b>");
            warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            warning.setDefaultButton(QMessageBox::Cancel);
            int ret = warning.exec();
            if(ret==QMessageBox::Yes) {
                info_opera op(titolo->text(),"disponibile","",anno->text(),"presente");
                emit submitR(op);
                pulisci_Campi();
                chiudi();
             }
            }
}
void inserisci_Rivista::pulisci_Campi(){
    titolo->clear();
    anno->clear();
}

void inserisci_Rivista::chiudi() {
    emit chiudi_aggiungi_rivista();
}

inserisci_Rivista::~inserisci_Rivista(){

    delete grid;
    delete layout;
    delete submit;
    delete exit;

    delete t;
    delete a;

    delete titolo;
    delete anno;
}

void inserisci_Rivista::closeEvent(QCloseEvent*){ emit chiudi_aggiungi_rivista(); }


