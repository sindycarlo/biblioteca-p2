#include "c_mainwindow.h"

C_mainWindow::C_mainWindow(database* db,mainWindow* v, QObject *parent) :model(db),view(v),  QObject(parent) {
    connect(view,SIGNAL(rimuovi(int)),this,SLOT(rimuovi_operaDB(int)));
    connect(view,SIGNAL(aggiorna_prestito(int)),this,SLOT(aggiorna_prestitoDB(int)));
    connect(view,SIGNAL(show_inserisci_rivista()),this,SLOT(inserisci_rivistaDB()));
    connect(view,SIGNAL(show_inserisci_libro()),this,SLOT(inserisci_libroDB()));

   //connessione che permette la ricerca di un'opera o di una serie di opere
    connect(view,SIGNAL(cerca_opera(QString)),this,SLOT(cerca_operaDB(QString)));

    //chiudi
    connect(view,SIGNAL(chiudi_app()),qApp,SLOT(quit()));
}

void C_mainWindow::cerca_operaDB(const QString& text){
    /*contenitore<opera> lista=model->trova_opera(text);
    if(!(lista.empty())){
        view->costruisci_Tabella(lista);
    }else view->aggiorna_vista();
    */
}

void C_mainWindow::rimuovi_operaDB(int ID){
    model->remove_opera(ID);
    view->aggiorna_vista();
}

void C_mainWindow::aggiorna_prestitoDB(int ID){
 /*   try{ model->Presta_ricevi(ID); }
    catch(Exc){
        QString identificativo;
        identificativo.setNum(ID);
        QMessageBox warning;
            warning.setIcon(QMessageBox::Warning);
            warning.setWindowTitle("OPERAZIONE NON ESEGUITA");
            warning.setText("L'opera con ID <b>"+identificativo+"</b> non può essere prestata in quanto ha una data di uscita maggiore o uguale a 20 anni");
            warning.setStandardButtons(QMessageBox::Cancel);
            warning.setDefaultButton(QMessageBox::Cancel);
            int ret = warning.exec();
    }
*/
}


void C_mainWindow::inserisci_rivistaDB(){
    inserisci_Rivista* inserisci=new inserisci_Rivista();
    c_add_rivista * controller=new c_add_rivista(model,inserisci,view);
    inserisci->show();


}
void C_mainWindow::inserisci_libroDB(){
    inserisci_Libro* inserisci=new inserisci_Libro();
    c_add_libro* controller=new c_add_libro(model,inserisci,view);
    inserisci->show();
}
