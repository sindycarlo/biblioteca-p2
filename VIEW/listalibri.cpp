#include"listalibri.h"

listalibri::listalibri(unsigned int id,database* db,database_utente* udb,database_utente_opere* uodb): idutente(id), listaOp(db,udb,uodb){
    costruisci_contenuto();
}

void listalibri::costruisci_contenuto(){ aggiorna_vista(); }

unsigned int listalibri::Getidutente() const {return idutente;}

void listalibri::aggiorna_vista(){

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
                    if(l)
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

void listalibri::aggiorna_vista_prestito_libri(){

    int row=0;

        if(!((get_modelutenteopere())->vuoto()))
        {
             int id;
             QString i;
             contenitore<opera>::iteratore it;
             bool trovato=false;
             for(it=(get_modelutenteopere())->dbopereutenti_begin(); it!=(get_modelutenteopere())->dbopereutenti_end(); it++)
             {
                 libro*l=visualizzaopera(*it);
                 if(l && (*it)->Getappartenenza()==Getidutente())
                {
                    Getable()->setRowCount(row+1);
                    id=(l)->GetId();
                    i.setNum(id);
                    trovato=true;
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
             }
             if(trovato==false)
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

libro* listalibri::visualizzaopera(opera * op) const {
    return dynamic_cast<libro*>(op);
}







