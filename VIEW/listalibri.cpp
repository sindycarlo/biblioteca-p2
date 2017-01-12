#include"listalibri.h"

listalibri::listalibri(unsigned int id,database* db,database_utente* udb,database_utente_opere* uodb): idutente(id), listaOp(db,udb,uodb){
    costruisci_contenuto();
}

void listalibri::costruisci_contenuto(){ aggiorna_vista(); }

unsigned int listalibri::Getidutente() const {return idutente;}

void listalibri::aggiorna_vista(){

    int row=0;
        database* ciao=get_model();
        if(!((get_model())->vuoto()))
        {
             int id;
             QString i;
             contenitore<opera>::iteratore it;
             for(it=(get_model())->db_begin(); it!=(get_model())->db_end(); it++)
             {
                 if((*it)->Get_tipo()=="libro")
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

void listalibri::aggiorna_vista_prestito_libri(){

    int row=0;
        database* ciao=get_model();
        if(!((get_modelutenteopere())->vuoto()))
        {
             int id;
             QString i;
             contenitore<opera>::iteratore it;
             for(it=(get_modelutenteopere())->dbopereutenti_begin(); it!=(get_modelutenteopere())->dbopereutenti_end(); it++)
             {
                 if((*it)->Get_tipo()=="libro" && (*it)->Getappartenenza()==Getidutente())
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



void listalibri::build_Nuova(const contenitore<opera>& lista){
    int row=0;
    if(!(lista.empty()))
    {
         int id;
         QString i;
         contenitore<opera>::iteratore it;

         for(it=lista.begin(); it!=lista.end(); it++)
         {
             if((*it)->Get_tipo()=="libro")
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











