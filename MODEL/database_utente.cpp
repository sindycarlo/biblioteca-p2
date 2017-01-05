#include "MODEL/database_utente.h"


//faccio l'include del file xml:
QString database_utente::filename="../biblioteca-p2/databaseutenti.xml";



contenitore<utente>::iteratore database_utente::dbutenti_begin() {return dbutenti.begin();}

contenitore<utente>::iteratore database_utente::dbutenti_end() {return dbutenti.end();}



//creare un database significa caricare il file databaseutenti.xml:
database_utente::database_utente(database* biblio) : biblioteca(biblio) {database_utente::Load();}


//"distruggere" un database significa fare la chiusura del file databaseutenti.xml:
database_utente::~database_utente() {database_utente::Close();}


//quando carico il database scrivo tutti gli utenti nel mio contenitore:
void database_utente::Load() {
    QString nome="Sconosciuto",cognome="Sconosciuto",codicefiscale="Sconosciuto",password="Sconosciuto";

    unsigned int Tipoutente=0, idutente=-1, numopere=0, tempo=0;

    utente* tmp=NULL;
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
                    if(xmlReader.name()=="Tipoutente") Tipoutente=xmlReader.readElementText().toInt();
                    else
                        if(xmlReader.name()=="Idutente") idutente=xmlReader.readElementText().toInt();
                        else
                    if(Tipoutente==1)//sto leggendo un utente_basic:
                    {
                        if(xmlReader.name()=="Nome") nome=xmlReader.readElementText();
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
                        if(xmlReader.name()=="Nome") nome=xmlReader.readElementText();
                        else
                            if(xmlReader.name()=="Cognome") cognome=xmlReader.readElementText();
                            else
                                if(xmlReader.name()=="CodiceFiscale") codicefiscale=xmlReader.readElementText();
                                else
                                    if(xmlReader.name()=="Password") password=xmlReader.readElementText();
                                    else
                                        if(xmlReader.name()=="Tempoprestito") tempo=xmlReader.readElementText().toInt();

                                        else std::cout<<"Errore nella lettura di un utente pro";
                    }

         }
         else //sono alla fine del documento quindi:
         {      //sono al tag </utente>
             if(xmlReader.isEndDocument() && xmlReader.name()=="utente")
             {
               if(Tipoutente==1) tmp=new utente_basic(GetDatabase(),numopere,nome,cognome,codicefiscale,password);
               else tmp=new utente_pro(GetDatabase(),tempo,nome,cognome,codicefiscale,password);
                tmp->SetID(idutente);
                dbutenti.add_item(tmp);
                xmlReader.readNext();
              }
             else xmlReader.readNext();
         }
         }


}

//apporto le modifiche riscrivendo tutto il database:
void database_utente::Close() {
    QFile file(filename);
         file.open(QIODevice::WriteOnly);

         QXmlStreamWriter xmlWriter(&file);
         xmlWriter.setAutoFormatting(true);
         xmlWriter.writeStartDocument();
        if(!vuoto())
        {
         xmlWriter.writeStartElement("databaseutenti");
         contenitore<utente>::iteratore it;
         for(it=dbutenti.begin();it!=dbutenti.end();it++)
         {
             (*it)->Write_utente(xmlWriter);
         }
         xmlWriter.writeEndDocument();
        }
        file.close();
}



utente* database_utente::trova_utente(unsigned int id) const{
   if(vuoto()) return 0;

   contenitore<utente>::iteratore it;
   contenitore<utente>::iteratore risultato;
   bool trovato=false;
   it=dbutenti.begin();
   while(it!=dbutenti.end() && !trovato)
   {
       if((*it)->GetID()==id){ trovato=true;}
           risultato=it;
           it++;

   }
   if(trovato) return *risultato;
   return 0;
}
void database_utente::remove_utente(const int id) {
utente*tmp=trova_utente(id);
if(tmp!=0){dbutenti.remove_item(tmp);}
else std::cout<<"Errore utente non presente nel database";
}


bool database_utente::vuoto() const {return dbutenti.empty();}





//aggiunge un utente basic al mio contenitore quindi al database:
void database_utente::add_utentebasic(const info_utente& c) {
    unsigned int dettaglio=c.get_dettaglio().toInt();
    utente_basic*p=new utente_basic(GetDatabase(),dettaglio,c.get_nome(),c.get_cognome(),c.get_codicefiscale(),c.get_password());
    dbutenti.add_item(p);
}

//aggiunge un utente pro al mio contenitore quindi al database:
void database_utente::add_utentepro(const info_utente & c1) {
    unsigned int dettaglio=c1.get_dettaglio().toInt();
    utente_pro*p=new utente_pro(GetDatabase(),dettaglio,c1.get_nome(),c1.get_cognome(),c1.get_codicefiscale(),c1.get_password());
    dbutenti.add_item(p);
}


database* database_utente::GetDatabase() const {return biblioteca;}

