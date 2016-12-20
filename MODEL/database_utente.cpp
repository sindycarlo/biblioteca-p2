#include "MODEL/database_utente.h"

//faccio l'include del file xml:
QString database::filename="../biblioteca-p2/databaseutenti.xml";



contenitore<utente>::iteratore database::db_begin() {return db.begin();}

contenitore<utente>::iteratore database::db_end() {return db.end();}



//creare un database significa caricare il file databaseutenti.xml:
database::database() {database::Load();}


//"distruggere" un database significa fare la chiusura del file databaseutenti.xml:
database::~database() {database::Close();}


//quando carico il database scrivo tutti gli utenti nel mio contenitore:
void database::Load() {
    QString Tipoutente=0,nome="Sconosciuto",cognome="Sconosciuto",codicefiscale="Sconosciuto",password="Sconosciuto";

    unsigned int idutente=-1, numopere=0, tempo=0;

    utente*tmp=0;
    QFile file(filename);
         file.open(QIODevice::ReadOnly);
           // if (!file.open(QFile::ReadOnly | QFile::Text))  std::cout << "Errore: Impossibile leggere il file"<< std::endl;
         QXmlStreamReader xmlReader(&file);
         xmlReader.readNext();
         while(!xmlReader.atEnd())
         {
            if(xmlReader.isStartElement())
            {
                if(xmlReader.name()=="databaseutenti" || xmlReader.name()=="utente") xmlReader.readNext();
                else
                    if(xmlReader.name()=="Tipoutente") Tipo=xmlReader.readElementText().toInt();
                    else
                        if(xmlReader.name()=="Idutente") id=xmlReader.readElementText().toInt();
                        else
                    if(Tipoutente==1)//sto leggendo un utente_basic:
                    {
                        if(xmlReader.name()=="Nome") Nome=xmlReader.readElementText();
                        else
                            if(xmlReader.name()=="Cognome") cognome=xmlReader.readElementText();
                            else
                                if(xmlReader.name()=="CodiceFiscale") codicefiscale=xmlReader.readElementText();
                                else
                                    if(xmlReader.name()=="Password") password=xmlReader.readElementText();
                                    else
                                        if(xmlReader.name()=="NumeroOpere") numopere=xmlReader.readElementText().toInt();

                                        else std::cout<<"Errore nella lettura di un utente basic";
                    }
                    else if(Tipoutente==2)
                    {
                        if(xmlReader.name()=="Nome") Nome=xmlReader.readElementText();
                        else
                            if(xmlReader.name()=="Cognome") cognome=xmlReader.readElementText();
                            else
                                if(xmlReader.name()=="CodiceFiscale") codicefiscale=xmlReader.readElementText();
                                else
                                    if(xmlReader.name()=="Password") password=xmlReader.readElementText();
                                    else
                                        if(xmlReader.name()=="TempoPrestito") tempo=xmlReader.readElementText().toInt();

                                        else std::cout<<"Errore nella lettura di un utente pro";
                    }

         }
         else //sono alla fine del documento quindi:
         {      //sono al tag </utente>
             if(xmlReader.isEndDocument() && xmlReader.name()=="utente")
             {
               if(Tipo==1) tmp=new utente_basic(numopere,nome,cognome,codicefiscale,password);
               else tmp=new utente_pro(tempo,nome,cognome,codicefiscale,password);
                tmp->SetID(idutente);
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
         contenitore<opera>::iteratore it;
         for(it=db.begin();it!=db.end();it++)
         {
             (*it)->Write_opera(xmlWriter);
         }
         xmlWriter.writeEndDocument();
        }
        file.close();
}



utente* database::trova_utente(unsigned int id) const{
   if(vuoto()) return 0;

   contenitore<utente>::iteratore it;
   contenitore<utente>::iteratore risultato;
   bool trovato=false;
   it=db.begin();
   while(it!=db.end() && !trovato)
   {
       if((*it)->GetId()==id){ trovato=true;}
           risultato=it;
           it++;

   }
   if(trovato) return *risultato;
   return 0;
}
void database::remove_utente(const int id) {
opera*tmp=trova_utente(id);
if(tmp!=0){db.remove_item(tmp);}
else std::cout<<"Errore utente non presente nel database";
}


bool database::vuoto() const {return db.empty();}





//aggiunge un utente basic al mio contenitore quindi al database:
void database::add_utentebasic(const info_utente& c) {
utente_basic*p=new utente_basic(c.get_nome(),c.get_cognome(),c.get_ID(),c.get_password(),c.get_codicefiscale(),c.get_dettaglio());
db.add_item(p);
}

//aggiunge un utente pro al mio contenitore quindi al database:
void database::add_utentepro(const info_utente & c1) {
    utente_pro*p=new utente_pro(c.get_nome(),c.get_cognome(),c.get_ID(),c.get_password(),c.get_codicefiscale(),c.get_dettaglio());
    db.add_item(p);
}




