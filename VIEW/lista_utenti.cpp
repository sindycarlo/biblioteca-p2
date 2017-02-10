#include"listautenti.h"

listautenti::listautenti(database* db,database_utente* udb,database_utente_opere* uodb): Widget_Padre(db,udb,uodb){
    table=new QTableWidget();

  //inserisco la tabella nel layout del widget
    layout_table=new QVBoxLayout();
    layout_table->addWidget(table);
    set_style();
    setLayout(layout_table);

    costruisci_contenuto();

    connect(table,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(doppio_click_utenti(int)));     //doppio click
    connect(table,SIGNAL(cellClicked(int,int)),this,SLOT(click_singolo_utenti(int)));          //click singolo

}

void listautenti::costruisci_contenuto(){ aggiorna_vista(); }

void listautenti::aggiorna_vista(){

    int row=0;

        if(!((get_modelutenti())->vuoto()))
        {
             int id;
             QString i;
             contenitore<utente>::iteratore it;
             for(it=(get_modelutenti())->dbutenti_begin(); it!=(get_modelutenti())->dbutenti_end(); it++)
             {
                table->setRowCount(row+1);
                id=(*it)->GetID();
                i.setNum(id);

                QTableWidgetItem *ID = new QTableWidgetItem(i);
                QTableWidgetItem *nome = new QTableWidgetItem((*it)->GetNome());
                QTableWidgetItem *cognome = new QTableWidgetItem((*it)->GetCognome());

                table->setItem(row,0,ID);
                table->setItem(row,1,nome);
                table->setItem(row,2,cognome);
                row++;
             }
        }
        else{
                table->setRowCount(row);
                emit tabella_vuota_utenti();
            }
}

void listautenti::set_style(){
    Widget_Padre::set_style();
  //set numero righe e colonne della tabella
    table->setColumnCount(3);
    table->setRowCount(0);

  //set dimensioni tabella
    table->setMinimumWidth(200);
    table->setColumnWidth(0,50);
    table->setColumnWidth(1,105);
    table->setColumnWidth(2,100);
    table->setMaximumWidth(700);
    table->setMinimumHeight(300);
    table->setMaximumHeight(600);

    //intestazione tabella
    QStringList tabHeader;
    tabHeader<<"ID"<<"Nome"<<"Cognome";
    table->setHorizontalHeaderLabels(tabHeader);

    //comportamento nel momento in cui si seleziona un item
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
}


void listautenti::doppio_click_utenti(int r){
    select_utente=table->item(r,0)->text().toInt();
    emit richiesta_info_utenti(select_utente);
}

void listautenti::click_singolo_utenti(int r){
    select_utente=table->item(r,0)->text().toInt();
    emit selezione_utenti(select_utente);
}

listautenti::~listautenti(){
    delete table;
    delete layout_table;
}

void listautenti::abilita_doppio_click_utenti(){
    connect(table,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(doppio_click_utenti(int)));
    emit abilita_funzioni_utenti();
}

void listautenti::disabilita_doppio_click_utenti(){
    disconnect(table,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(doppio_click_utenti(int)));
    emit disabilita_funzioni_utenti();
}

void listautenti::abilita_click_singolo_utenti(){
    connect(table,SIGNAL(cellClicked(int,int)),this,SLOT(click_singolo_utenti(int)));
    emit abilita_funzioni_utenti();
}

void listautenti::disabilita_click_singolo_utenti(){
    disconnect(table,SIGNAL(cellClicked(int,int)),this,SLOT(click_singolo_utenti(int)));
    emit disabilita_funzioni_utenti();
}


void listautenti::ricerca(const QString text){

    int row=0;

        if(!((get_modelutenti())->vuoto()))
        {
             int id;
             QString i;
             bool trovato=false;
             contenitore<utente>::iteratore it;
             for(it=(get_modelutenti())->dbutenti_begin(); it!=(get_modelutenti())->dbutenti_end(); it++)
             {

                id=(*it)->GetID();
                utente*u=get_modelutenti()->trova_utente(id);
                if(u && u->GetNome()==text)
                {table->setRowCount(row+1);
                i.setNum(id);
                trovato=true;
                QTableWidgetItem *ID = new QTableWidgetItem(i);
                QTableWidgetItem *nome = new QTableWidgetItem((*it)->GetNome());
                QTableWidgetItem *cognome = new QTableWidgetItem((*it)->GetCognome());

                table->setItem(row,0,ID);
                table->setItem(row,1,nome);
                table->setItem(row,2,cognome);
                row++;
                }
             }
             if(trovato==false) aggiorna_vista();
        }
        else{
                table->setRowCount(row);
                aggiorna_vista();
            }
}

