#include"listariviste.h"

listariviste::listariviste(unsigned int id,database* db,database_utente* udb,database_utente_opere* uodb):listaOp(db,udb,uodb),idutente(id){
    costruisci_contenuto();
}

void listariviste::costruisci_contenuto(){ aggiorna_vista(); }

unsigned int listariviste::Getidutente() const {return idutente;}

void listariviste::aggiorna_vista(){

    int row=0;

        if(!((get_model())->vuoto()))
        {
             int id;
             QString i;
             contenitore<opera>::iteratore it;
             bool trovata=false;
             for(it=(get_model())->db_begin(); it!=(get_model())->db_end(); it++)
             {

                    rivista* r=visualizzaopera((*it));
                    if(r)
                    {
                        Getable()->setRowCount(row+1);
                        info_opera rivista=r->info_tot();
                        id=(r)->GetId();
                        i.setNum(id);
                        trovata=true;
                        QTableWidgetItem *ID = new QTableWidgetItem(i);
                        QTableWidgetItem *valore = new QTableWidgetItem(rivista.get_titolo());
                        QTableWidgetItem *annouscita = new QTableWidgetItem(rivista.get_dettaglio());
                        QTableWidgetItem *tipo = new QTableWidgetItem((r)->Get_tipo());

                        Getable()->setItem(row,0,ID);
                        Getable()->setItem(row,1,valore);
                        Getable()->setItem(row,2,annouscita);
                        Getable()->setItem(row,3,tipo);
                        row++;
                    }

             }
             if(trovata==false)
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
void listariviste::aggiorna_vista_prestito_riviste(){

    int row=0;
        if(!((get_modelutenteopere())->vuoto()))
        {
             int id;
             QString i;
             bool trovato=false;
             contenitore<opera>::iteratore it;
             for(it=(get_modelutenteopere())->dbopereutenti_begin(); it!=(get_modelutenteopere())->dbopereutenti_end(); it++)
             {
                 rivista* r=visualizzaopera((*it));
                 if(r && (*it)->Getappartenenza()==Getidutente())
                {
                    Getable()->setRowCount(row+1);
                    info_opera rivista=r->info_tot();
                    id=(*it)->GetId();
                    i.setNum(id);
                    trovato=true;
                    QTableWidgetItem *ID = new QTableWidgetItem(i);
                    QTableWidgetItem *valore = new QTableWidgetItem(rivista.get_titolo());
                    QTableWidgetItem *annouscita = new QTableWidgetItem(rivista.get_dettaglio());
                    QTableWidgetItem *tipo = new QTableWidgetItem(r->Get_tipo());

                    Getable()->setItem(row,0,ID);
                    Getable()->setItem(row,1,valore);
                    Getable()->setItem(row,2,annouscita);
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
void listariviste::ricerca( const QString text){

    int row=0;

        if(!((get_model())->vuoto()))
        {
             int id;
             QString i;
             contenitore<opera>::iteratore it;
             bool trovata=false;
             for(it=(get_model())->db_begin(); it!=(get_model())->db_end(); it++)
             {

                    rivista* r=visualizzaopera((*it));
                    if(r && text==r->GetTitolo())
                    {
                        Getable()->setRowCount(row+1);
                        info_opera rivista=r->info_tot();
                        id=(r)->GetId();
                        i.setNum(id);
                        trovata=true;
                        QTableWidgetItem *ID = new QTableWidgetItem(i);
                        QTableWidgetItem *valore = new QTableWidgetItem(rivista.get_titolo());
                        QTableWidgetItem *annouscita = new QTableWidgetItem(rivista.get_dettaglio());
                        QTableWidgetItem *tipo = new QTableWidgetItem((r)->Get_tipo());

                        Getable()->setItem(row,0,ID);
                        Getable()->setItem(row,1,valore);
                        Getable()->setItem(row,2,annouscita);
                        Getable()->setItem(row,3,tipo);
                        row++;
                    }

             }
             if(trovata==false)
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

rivista* listariviste::visualizzaopera(opera *op) const {
    return dynamic_cast<rivista*>(op);
}





