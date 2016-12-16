#include "MODEL/database.h"

//faccio l'include del file xml:
QString database::filename="../biblioteca-p2/database.xml";



contenitore::iteratore database::db_begin() {return db.begin();}

contenitore::iteratore database::db_end() {return db.end();}



//creare un database significa caricare il file database.xml:
database::database() {database::Load();}


//"distruggere" un database significa fare la chiusura del file database.xml:
database::~database() {database::Close();}


//quando carico il database scrivo tutte le opre nel mio contenitore:
void database::Load() {
    int Tipo=0, AnnoUscita=0,Stato=-1, Id=0;
    QString Titolo="Nessuno", Autore="Nessuno";
    opera*tmp=NULL;
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
                    if(xmlReader.name()=="Tipo") Tipo=xmlReader.readElementText().toInt();
                    else
                        if(xmlReader.name()=="Id") Id=xmlReader.readElementText().toInt();
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
                            if(xmlReader.name()=="AnnoUscita") Autore=xmlReader.readElementText();
                        else std::cout<<"Errore nella lettura di un libro";
                    }

         }
         else //sono alla fine del documento quindi:
         {      //sono al tag </opera>
             if(xmlReader.isEndDocument() && xmlReader.name()=="opera")
             {
               if(Tipo==1) tmp=new libro(Titolo,Autore,Stato);
               else tmp=new rivista(Titolo,AnnoUscita,Stato);
                tmp->Set_id(Id);
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
        if(!vuoto())
        {
         xmlWriter.writeStartElement("database");
         contenitore::iteratore it;
         for(it=db.begin();it!=db.end();it++)
         {
             (*it)->Write_opera(xmlWriter);
         }
         xmlWriter.writeEndDocument();
        }
        file.close();
}

//rimuovere un opera dal database significa:
/*1) cercare l'opera nel database con quel id;
 * (utilizzare un opportuno metodo)
 * 2) rimuoverla dal mio contenitore di opere;
 * 3) aggiornare il database;
 * (metodo close aggiorna il database con le modifiche!)
 * */

opera* database::trova_opera(unsigned int id) const{
   if(vuoto()) return 0;

   contenitore::iteratore it;
   contenitore::iteratore risultato;
   bool trovato=false;
   for(it=db.begin();it!=db.end() && !trovato;it++)
   {
       if((*it)->GetId()==id) trovato=true;
           risultato=it;
           it++;

   }
   if(trovato) return *risultato;
   return 0;
}
void database::remove_opera(const int id) {
opera*tmp=trova_opera(id);
if(tmp!=0){db.remove_item(tmp);}
else std::cout<<"Errore opera non presente nel database";
}


bool database::vuoto() const {return db.empty();}





//aggiunge un libro al mio contenitore quindi al database:
void database::add_Libro(const info_opera& c) {
libro*p=new libro(c.get_titolo(),c.get_dettaglio(),1);
db.add_item(p);
}

//aggiunge una rivista al mio contenitore quindi al database:
void database::add_Rivista(const info_opera & c1) {
    unsigned int x=c1.get_dettaglio().toInt();
    rivista*p=new rivista(c1.get_titolo(),x,1);
    db.add_item(p);
}




