#include"listaop.h"

listaOp::listaOp(database* db,database_utente* udb,database_utente_opere* uodb): Widget_Padre(db,udb,uodb){
    table=new QTableWidget();

    layout_table=new QVBoxLayout();
    layout_table->addWidget(table);
    set_style();
    setLayout(layout_table);

    connect(table,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(doppio_click(int)));     //doppio click
    connect(table,SIGNAL(cellClicked(int,int)),this,SLOT(click_singolo(int)));          //click singolo
}
void listaOp::set_style(){
    Widget_Padre::set_style();
  //set numero righe e colonne della tabella
    table->setColumnCount(4);
    table->setRowCount(0);

  //set dimensioni tabella
    table->setMinimumWidth(400);
    table->setColumnWidth(0,50);
    table->setColumnWidth(1,210);
    table->setColumnWidth(2,100);
    table->setMaximumWidth(600);
    table->setMinimumHeight(300);
    table->setMaximumHeight(600);

    //intestazione tabella
    QStringList tabHeader;
    tabHeader<<"ID"<<"Titolo"<<"Dettaglio"<<"Tipologia";
    table->setHorizontalHeaderLabels(tabHeader);

    //comportamento nel momento in cui si seleziona un item
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
}



void listaOp::abilita_doppio_click(){
    connect(table,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(doppio_click(int)));
    emit abilita_funzioni();
}
void listaOp::disabilita_doppio_click(){
    disconnect(table,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(doppio_click(int)));
    emit disabilita_funzioni();
}

void listaOp::doppio_click(int r){
    select_opera=table->item(r,0)->text().toInt();
    emit richiesta_info(select_opera);
}

void listaOp::click_singolo(int r){
    select_opera=table->item(r,0)->text().toInt();
    emit selezione(select_opera);
}


int listaOp::Getopera() const{
    return select_opera;
}
QTableWidget* listaOp::Getable() const {
    return table;
}
QVBoxLayout* listaOp::Getlayout_table() const {
    return layout_table;
}


 listaOp::~listaOp() {
    delete table;
    delete layout_table;
}






