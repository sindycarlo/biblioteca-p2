#include "MODEL/database_utente_opere.h"
#include "MODEL/rivista.h"

//faccio l'include del file xml:
QString database_utente_opere::filename="opereutenti.xml";



contenitore<opera>::iteratore database_utente_opere::dbopereutenti_begin() {return dbopereutente.begin();}

contenitore<opera>::iteratore database_utente_opere::dbopereutenti_end() {return dbopereutente.end();}



//creare un database significa caricare il file database.xml:
database_utente_opere::database_utente_opere() {database_utente_opere::Load();}


//"distruggere" un database significa fare la chiusura del file database.xml:
database_utente_opere::~database_utente_opere() {database_utente_opere::Close();}


//quando carico il database scrivo tutte le opre nel mio contenitore:
void database_utente_opere::Load() {
    QString Titolo="Sconosciuto",Autore="Sconosciuto";
     int  Id=-1, Stato=-1,max=0, Tipo=0,  AnnoUscita=0;
    opera*tmp=NULL;
    int Appartiene=-1;
    QFile file(filename);
         file.open(QIODevice::ReadOnly);
           // if (!file.open(QFile::ReadOnly | QFile::Text))  std::cout << "Errore: Impossibile leggere il file"<< std::endl;
         QXmlStreamReader xmlReader(&file);
         xmlReader.readNext();
         while(!xmlReader.atEnd())
         {
            if(xmlReader.isStartElement())
            {
                if(xmlReader.name()=="database" || xmlReader.name()=="opera") xmlReader.readNext();
                else
                  if(xmlReader.name()=="max") max=xmlReader.readElementText().toInt();
                   else
                    if(xmlReader.name()=="Tipo") Tipo=xmlReader.readElementText().toInt();
                    else
                        if(xmlReader.name()=="Id") Id=xmlReader.readElementText().toInt();
                        else
                            if(xmlReader.name()=="Appartenenza") Appartiene=xmlReader.readElementText().toInt();
                            else
                            if(xmlReader.name()=="Stato") Stato=xmlReader.readElementText().toInt();
                            else
                    if(Tipo==1)//sto leggendo un libro:
                    {
                        if(xmlReader.name()=="Titolo") Titolo=xmlReader.readElementText();
                        else
                            if(xmlReader.name()=="Autore") Autore=xmlReader.readElementText();
                        else std::cout<<"Errore nella lettura di un libro";
                    }
                    else if(Tipo==2)
                    {
                        if(xmlReader.name()=="Titolo") Titolo=xmlReader.readElementText();
                        else
                            if(xmlReader.name()=="AnnoUscita") AnnoUscita=xmlReader.readElementText().toInt();
                        else std::cout<<"Errore nella lettura di una rivista";
                    }

         }
         else //sono alla fine del documento quindi:
         {      //sono al tag </opera>
             if(xmlReader.isEndElement() && xmlReader.name()=="opera")
             {
               if(Tipo==1) tmp=new libro(Titolo,Autore,Stato);
               else tmp=new rivista(Titolo,AnnoUscita,Stato);
                tmp->Set_id(Id);
                tmp->Set_maxid(max);
                tmp->Setappartenenza(Appartiene);
                dbopereutente.add_item(tmp);
                xmlReader.readNext();
              }
             else xmlReader.readNext();
         }
}
}


//apporto le modifiche riscrivendo tutto il database:
void database_utente_opere::Close() {
    QFile file(filename);
         file.open(QIODevice::WriteOnly);

         QXmlStreamWriter xmlWriter(&file);
         xmlWriter.setAutoFormatting(true);
         xmlWriter.writeStartDocument();
          xmlWriter.writeStartElement("database");
          contenitore<opera>::iteratore it=dbopereutente.begin();
        if(!vuoto())
        {
            int max_val=dbopereutente[it]->GetMaxId();
            QString MAX;
            MAX.setNum(max_val);
            xmlWriter.writeTextElement("max",MAX);

         for(;it!=dbopereutenti_end();it++)
         {
             (*it)->Write_opera(xmlWriter);
         }

        }
         xmlWriter.writeEndDocument();
        file.close();
}

//rimuovere un opera dal database significa:
/*1) cercare l'opera nel database con quel id;
 * (utilizzare un opportuno metodo)
 * 2) rimuoverla dal mio contenitore di opere;
 * 3) aggiornare il database;
 * (metodo close aggiorna il database con le modifiche!)
*/

opera* database_utente_opere::trova_operadelutente(unsigned int idutente, unsigned int idopera) const{
   if(vuoto()) return 0;
   contenitore<opera>::iteratore it;
   contenitore<opera>::iteratore risultato;
   bool trovato=false;
   it=dbopereutente.begin();
   while(it!=dbopereutente.end() && !trovato)
   {
       if((*it)->Getappartenenza()==idutente && (*it)->GetId()==idopera){trovato=true;}
           risultato=it;
           it++;

   }
   if(trovato) return *risultato;
   return 0;

}
void database_utente_opere::remove_operadelutente(const int idutente, const int idopera) {
opera*tmp=trova_operadelutente(idutente,idopera);
if(tmp!=0){dbopereutente.remove_item(tmp);}
else std::cout<<"Errore opera non presente nel database";
}


bool database_utente_opere::vuoto() const {return dbopereutente.empty();}


void database_utente_opere::aggiungi_libro_utente(const info_opera& l,unsigned int id) {
    libro*p=new libro(l.get_titolo(),l.get_dettaglio(),0);
    p->Setappartenenza(id);
    p->Presta_opera();
    dbopereutente.add_item(p);
}
void database_utente_opere::aggiungi_rivista_utente(const info_opera& s,unsigned int id) {
    unsigned int x=s.get_dettaglio().toInt();
    rivista*p=new rivista(s.get_titolo(),x,0);
    p->Setappartenenza(id);
    dbopereutente.add_item(p);


}


