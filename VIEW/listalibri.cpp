#include"listalibri.h"

listalibri::listalibri(unsigned int id,database* db,database_utente* udb,amministratore* a):  listaOp(db,udb),identificativo(id), admin(a){
    costruisci_contenuto();
}

void listalibri::costruisci_contenuto(){ aggiorna_vista(); }

void listalibri::aggiorna_vista(){ aggiornalibri(); }

void listalibri::aggiornalibri() {

    int row=0;

        if(!((get_model())->vuoto()))
        {
             int id;
             QString i;
             contenitore<opera>::iteratore it;
             bool trovata=false;
             for(it=(get_model())->db_begin(); it!=(get_model())->db_end(); it++)
             {


                    libro*l=visualizzaopera(*it);
                    if(l && l->Getappartenenza()==identificativo)
                     {
                        Getable()->setRowCount(row+1);
                        id=(*it)->GetId();
                        i.setNum(id);
                        trovata=true;
                        QTableWidgetItem *ID = new QTableWidgetItem(i);
                        QTableWidgetItem *valore = new QTableWidgetItem((l)->GetTitolo());
                        QTableWidgetItem *autore = new QTableWidgetItem(l->Getautore());
                        QTableWidgetItem *tipo = new QTableWidgetItem((l)->Get_tipo());

                        Getable()->setItem(row,0,ID);
                        Getable()->setItem(row,1,valore);
                        Getable()->setItem(row,2,autore);
                        Getable()->setItem(row,3,tipo);
                        row++;
                    }

             }if(trovata==false)
             {
                 Getable()->setRowCount(row);
                 emit tabella_vuota();
             }
        }
        else{
                Getable()->setRowCount(row);
                emit tabella_vuota();
            }
}

void listalibri::ricerca(const QString text){

    int row=0;

        if(!((get_model())->vuoto()))
        {
             int idopera;
             QString i;
             bool trovata=true;
             bool ok=false;
             utente*u=get_modelutenti()->trova_utente(identificativo);
             contenitore<opera>::iteratore it;  
             for(it=get_model()->db_begin(); it!=get_model()->db_end(); it++)
             {
                    if(u){
                    trovata=u->ricerca(text,*it);
                    }else trovata=admin->ricerca(text,*it);

                    libro*l=visualizzaopera(*it);
                    if(l && trovata)
                    {
                        Getable()->setRowCount(row+1);
                        idopera=(*it)->GetId();
                        i.setNum(idopera);
                        ok=true;
                        QTableWidgetItem *ID = new QTableWidgetItem(i);
                        QTableWidgetItem *valore = new QTableWidgetItem((l)->GetTitolo());
                        QTableWidgetItem *autore = new QTableWidgetItem(l->Getautore());
                        QTableWidgetItem *tipo = new QTableWidgetItem((l)->Get_tipo());

                        Getable()->setItem(row,0,ID);
                        Getable()->setItem(row,1,valore);
                        Getable()->setItem(row,2,autore);
                        Getable()->setItem(row,3,tipo);
                        row++;
                    }

             }if(ok==false)
             {
                 Getable()->setRowCount(row);
                 aggiorna_vista();
             }
        }
        else{
                Getable()->setRowCount(row);
                emit tabella_vuota();
            }
}

libro* listalibri::visualizzaopera(opera * op) const {
    return dynamic_cast<libro*>(op);
}







