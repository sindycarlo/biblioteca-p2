#include "MODEL/database.h"

//faccio l'include del file xml:
QString database::filename="database.xml";



contenitore<opera>::iteratore database::db_begin() {return db.begin();}

contenitore<opera>::iteratore database::db_end() {return db.end();}



//creare un database significa caricare il file database.xml:
database::database() {database::Load();}


//"distruggere" un database significa fare la chiusura del file database.xml:
database::~database() {database::Close();}


//quando carico il database scrivo tutte le opre nel mio contenitore:
void database::Load() {
    int Tipo=0, AnnoUscita=0,max=0,Stato=-1, Id=0,Appartiene=-1;
    QString Titolo="Nessuno", Autore="Nessuno";
    opera*tmp=NULL;
    QFile file(filename);
     if (!file.open(QFile::ReadOnly | QFile::Text))  std::cout << "Errore: Impossibile leggere il file"<< std::endl;
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
                //imposto l'appartenenza dell'opera alla biblioteca o ad un utente
                tmp->Setappartenenza(Appartiene);
                db.add_item(tmp);
                xmlReader.readNext();
              }
             else xmlReader.readNext();
         }
         }


}

//apporto le modifiche riscrivendo tutto il database:
void database::Close() {
    QFile file(filename);
         file.open(QIODevice::WriteOnly);

         QXmlStreamWriter xmlWriter(&file);
         xmlWriter.setAutoFormatting(true);
         xmlWriter.writeStartDocument();
         xmlWriter.writeStartElement("database");
         contenitore<opera>::iteratore it=db.begin();
        if(!vuoto())
        {
            int max_val=db[it]->GetMaxId();
            QString MAX;
            MAX.setNum(max_val);
            xmlWriter.writeTextElement("max",MAX);

         for(;it!=db.end();it++)
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
 * */


bool database::vuoto() const {return db.empty();}


info_opera database::get_infoOpera(int ID,int idopera) const{
    opera* op=trova_opera(ID,idopera);
    if(!op)
    {
        return info_opera("Opera non presente", "Opera non presente", "Opera non presente", "Opera non presente","Opera non presente");
    }
    info_opera o=op->info_tot();
    return o;
}




opera* database::trova_opera(unsigned int id, unsigned int idopera) const{
   if(vuoto()) return 0;
   contenitore<opera>::iteratore it;
   contenitore<opera>::iteratore risultato;
   bool trovato=false;
   it=db.begin();
   while(it!=db.end() && !trovato)
   {
       if((*it)->Getappartenenza()==id && (*it)->GetId()==idopera){trovato=true;}
           risultato=it;
           it++;

   }
   if(trovato) return *risultato;
   return 0;

}

void database::aggiungi_libro(const info_opera& l,unsigned int id) {
    libro*p=new libro(l.get_titolo(),l.get_dettaglio(),1);
    p->Setappartenenza(id);
    if(p->Getappartenenza()!=-1)
        p->Presta_opera();
    else p->Riscatta();
    db.add_item(p);
}

void database::aggiungi_rivista(const info_opera& s,unsigned int id) {
    unsigned int x=s.get_dettaglio().toInt();
    rivista*p=new rivista(s.get_titolo(),x,1);
    p->Setappartenenza(id);
    if(p->Getappartenenza()!=-1)
        p->Presta_opera();
    else p->Riscatta();
    db.add_item(p);


}

void database::remove_opera(const int id, const int idopera) {
opera*tmp=trova_opera(id,idopera);
if(tmp!=0){db.remove_item(tmp);}
else std::cout<<"Errore opera non presente nel database";
}




