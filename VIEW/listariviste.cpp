#include"listariviste.h"

listariviste::listariviste(unsigned int id,database* db,database_utente* udb,amministratore* a):listaOp(db,udb),idutente(id), admin(a){
    costruisci_contenuto();
}

void listariviste::costruisci_contenuto(){ aggiorna_vista(); }

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
                    if(r && r->Getappartenenza()==-1)
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
        if(!((get_model())->vuoto()))
        {
             int id;
             QString i;
             bool trovato=false;
             contenitore<opera>::iteratore it;
             for(it=(get_model())->db_begin(); it!=(get_model())->db_end(); it++)
             {
                 rivista* r=visualizzaopera((*it));
                 if(r && (*it)->Getappartenenza()==idutente)
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
             int idopera;
             QString i;
             bool trovata=true;
             bool ok=false;
             utente*u=get_modelutenti()->trova_utente(idutente);
             contenitore<opera>::iteratore it;
             for(it=(get_model())->db_begin(); it!=(get_model())->db_end(); it++)
             {
                    if(u){
                    trovata=u->ricerca(text,*it);
                    }else trovata=admin->ricerca(text,*it);

                    rivista* r=visualizzaopera((*it));
                    if(r && trovata)
                    {
                        Getable()->setRowCount(row+1);
                        info_opera rivista=r->info_tot();
                        idopera=(r)->GetId();
                        i.setNum(idopera);
                        ok=true;
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
             if(ok==false)
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





