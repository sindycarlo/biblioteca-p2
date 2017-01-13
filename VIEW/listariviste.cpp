#include"listariviste.h"

listariviste::listariviste(unsigned int id,database* db,database_utente* udb,database_utente_opere* uodb):idutente(id), listaOp(db,udb,uodb){
    costruisci_contenuto();
}

void listariviste::costruisci_contenuto(){ aggiorna_vista(); }

unsigned int listariviste::Getidutente() const {return idutente;}

void listariviste::aggiorna_vista(){

    int row=0;
        database* ciao=get_model();
        if(!((get_model())->vuoto()))
        {
             int id;
             QString i;
             contenitore<opera>::iteratore it;
             for(it=(get_model())->db_begin(); it!=(get_model())->db_end(); it++)
             {
                 if((*it)->Get_tipo()=="rivista")
                 {
                    Getable()->setRowCount(row+1);
                    id=(*it)->GetId();
                    i.setNum(id);

                    QTableWidgetItem *ID = new QTableWidgetItem(i);
                    QTableWidgetItem *valore = new QTableWidgetItem((*it)->GetTitolo());
                    QTableWidgetItem *tipo = new QTableWidgetItem((*it)->Get_tipo());

                    Getable()->setItem(row,0,ID);
                    Getable()->setItem(row,1,valore);
                    Getable()->setItem(row,2,tipo);
                    row++;
                 }
             }
        }
        else{
                Getable()->setRowCount(row);
                emit tabella_vuota();
            }
}
void listariviste::aggiorna_vista_prestito_riviste(){

    int row=0;
        database* ciao=get_model();
        if(!((get_modelutenteopere())->vuoto()))
        {
             int id;
             QString i;
             bool trovato=false;
             contenitore<opera>::iteratore it;
             for(it=(get_modelutenteopere())->dbopereutenti_begin(); it!=(get_modelutenteopere())->dbopereutenti_end(); it++)
             {
                 if((*it)->Get_tipo()=="rivista" && (*it)->Getappartenenza()==Getidutente())
                {
                    Getable()->setRowCount(row+1);
                    id=(*it)->GetId();
                    i.setNum(id);
                    trovato=true;
                    QTableWidgetItem *ID = new QTableWidgetItem(i);
                    QTableWidgetItem *valore = new QTableWidgetItem((*it)->GetTitolo());
                    QTableWidgetItem *tipo = new QTableWidgetItem((*it)->Get_tipo());

                    Getable()->setItem(row,0,ID);
                    Getable()->setItem(row,1,valore);
                    Getable()->setItem(row,2,tipo);
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



void listariviste::build_Nuova(const contenitore<opera>& lista){
    int row=0;
    if(!(lista.empty()))
    {
         int id;
         QString i;
         contenitore<opera>::iteratore it;

         for(it=lista.begin(); it!=lista.end(); it++)
         {
             if((*it)->Get_tipo()=="rivista")
             {
                Getable()->setRowCount(row+1);
                id=(*it)->GetId();
                i.setNum(id);

                QTableWidgetItem *ID = new QTableWidgetItem(i);
                QTableWidgetItem *valore = new QTableWidgetItem((*it)->GetTitolo());
                QTableWidgetItem *tipo = new QTableWidgetItem((*it)->Get_tipo());

                Getable()->setItem(row,0,ID);
                Getable()->setItem(row,1,valore);
                Getable()->setItem(row,2,tipo);
                row++;
             }
         }
    }
    else{
            Getable()->setRowCount(row);
            emit tabella_vuota();
        }
}









