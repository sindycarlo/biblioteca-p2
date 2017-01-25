#include "MODEL/database_utente.h"


//faccio l'include del file xml:
QString database_utente::filename="../biblioteca-p2/databaseutenti.xml";



contenitore<utente>::iteratore database_utente::dbutenti_begin() {return dbutenti.begin();}

contenitore<utente>::iteratore database_utente::dbutenti_end() {return dbutenti.end();}



//creare un database significa caricare il file databaseutenti.xml:
database_utente::database_utente(database* biblio, database_utente_opere * opere) : biblioteca(biblio), opereutenti(opere){database_utente::Load();}


//"distruggere" un database significa fare la chiusura del file databaseutenti.xml:
database_utente::~database_utente() {database_utente::Close();}


//quando carico il database scrivo tutti gli utenti nel mio contenitore:
void database_utente::Load() {
    QString nome="Sconosciuto",cognome="Sconosciuto",codicefiscale="Sconosciuto",password="Sconosciuto";

    unsigned int Tipoutente=0, idutente=-1, numopere=0, numriviste=0;

    utente* tmp=NULL;
    QFile file(filename);
         if (!file.open(QFile::ReadOnly | QFile::Text))  std::cout << "Errore: Impossibile leggere il file"<< std::endl;
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
                                        if(xmlReader.name()=="NumeroRiviste") numriviste=xmlReader.readElementText().toInt();

                                        else std::cout<<"Errore nella lettura di un utente pro";
                    }

         }
         else //sono alla fine del documento quindi:
         {      //sono al tag </utente>
             if(xmlReader.isEndElement() && xmlReader.name()=="utente")
             {

               if(Tipoutente==1) tmp=new utente_basic(GetDatabase(),Getdbopere(),numopere,nome,cognome,codicefiscale,password);
               else tmp=new utente_pro(GetDatabase(),Getdbopere(),numriviste,nome,cognome,codicefiscale,password);
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
         xmlWriter.writeStartElement("databaseutenti");
         if(!vuoto())
        {
         contenitore<utente>::iteratore it;
         for(it=dbutenti.begin();it!=dbutenti.end();it++)
         {
             (*it)->Write_utente(xmlWriter);
         }

        }
          xmlWriter.writeEndDocument();
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


contenitore<utente> database_utente::trova_utenti_insieme(const QString &u) const {

    contenitore<utente> container;
    for(contenitore<utente>::iteratore it=dbutenti.begin();it!=dbutenti.end();it++)
    {
        if(dbutenti[it]->ricerca_campi(u)) container.add_item(dbutenti[it]);
    }
    return container;
}


//aggiunge un utente basic al mio contenitore quindi al database:
void database_utente::add_utentebasic(const info_utente& c) {
    unsigned int dettaglio=c.get_dettaglio().toInt();
    utente_basic*p=new utente_basic(GetDatabase(),Getdbopere(),dettaglio,c.get_nome(),c.get_cognome(),c.get_codicefiscale(),c.get_password());
    dbutenti.add_item(p);
}

//aggiunge un utente pro al mio contenitore quindi al database:
void database_utente::add_utentepro(const info_utente & c1) {
    unsigned int dettaglio=c1.get_dettaglio().toInt();
    utente_pro*p=new utente_pro(GetDatabase(),Getdbopere(),dettaglio,c1.get_nome(),c1.get_cognome(),c1.get_codicefiscale(),c1.get_password());
    dbutenti.add_item(p);
}

info_utente database_utente::get_infoUtente(int ID) const{
    utente*u=trova_utente(ID);
    if(!u)
    {
        return info_utente(0,"utente non presente", "utente non presente", "utente non presente", "utente non presente","utente non presente","utente non presente");
    }
    info_utente us=u->infoutente();
    return us;
}


void database_utente::aggiorna_view() const{
    std::vector<Widget_Padre*>::const_iterator it=registro.begin();
    std::vector<Widget_Padre*>::const_iterator it_e=registro.end();
    for(; it<it_e; ++it) (*it)->aggiorna_vista();
}


void database_utente::add_registro_utente(Widget_Padre* wp){
    registro.push_back(wp);
}


void database_utente::remove_registro_utente(Widget_Padre* wp){
    std::vector<Widget_Padre*>::iterator it=registro.begin();
    std::vector<Widget_Padre*>::iterator it_e=registro.end();
    bool trovato=false;
    for(; it<it_e && !trovato; ++it)
    {
        if((*it)==wp){
            trovato=true;
            registro.erase(it);
        }
    }
}




database* database_utente::GetDatabase() const {return biblioteca;}

database_utente_opere* database_utente::Getdbopere() const {return opereutenti;}
