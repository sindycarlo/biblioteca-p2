#include "utente_basic.h"
#include "database.h"
#include "QString"
#include <QXmlStreamWriter>
//un utente_basic può ricevere in prestito massimo 5 opere;

//inizializzo la variabile statica NumOpere:
unsigned int utente_basic::limiteopere=5;


//costruttore di utente_basic:
utente_basic::utente_basic(unsigned int no =0, QString n ="Sconociuto", QString c ="Sconosciuto", QString cf ="Sconosciuto", QString psw ="Sconosciuto",contenitore<opera>* db =0): utente(n,c,cf,psw,db), NumOpere(no) {
    if(NumOpere>limiteopere)
    {std::cout<<"Errore: un utente basic non può prendere in prestito più di 5 opere";NumOpere=limiteopere;}

}


unsigned int utente_basic::Get_numopere() const {return NumOpere;}

//scrive nel file xml un utente basic:
void utente_basic::Write_utente(QXmlStreamWriter &XmlWriter) const {
    XmlWriter.writeStartElement("utente");

    //essendo un utente basic il tipo è "1";
    XmlWriter.writeTextElement("Tipoutente","1");
    //scrivo il nome dell'utente:
    XmlWriter.writeTextElement("Nome",GetNome());
    //scrivo il cognome dell'utente:
    XmlWriter.writeTextElement("Cognome",GetCognome());
    //scrivo codice fiscale:
    XmlWriter.writeTextElement("CodiceFiscale",GetCodicefiscale());
    //scrivo id dell'utente:
    int id=GetID();
    QString x;
    x.setNum(id);
    XmlWriter.writeTextElement("Idutente",x);
    //scrivo password utente:
    XmlWriter.writeTextElement("Password",GetPassword());
    //scrivo il dettaglio di utente_basic che è Numero opere in prestito:
    unsigned int k=Get_numopere();
    QString z;
    z.setNum(k);
    XmlWriter.writeTextElement("NumeroOpere",z);
    XmlWriter.writeEndElement();
}


//scrive nel file xml le opere di un utente basic:
void utente_basic::Write_utenteopere(QXmlStreamWriter &XmlWriter) const {
    XmlWriter.writeStartElement("utente");

    //essendo un utente basic il tipo è "1";
    XmlWriter.writeTextElement("Tipo","1");
    int id=GetID();
    QString x;
    x.setNum(id);
    //scrivo id dell'utente:
    XmlWriter.writeTextElement("Id",x);
    //scorro il contenitore di utente basic:
    contenitore<opera>::iteratore it;
    for(it=Getcontainer()->begin();it!=Getcontainer()->end();it++)
    {(*it)->Write_opera(XmlWriter);}
    XmlWriter.writeEndElement();
}

//ottengo un oggetto info_utente che mi fornisce tutte le informazioni su un utente:
info_utente utente_basic::infoutente() const {
    QString id;
    id.setNum(GetID());
    QString no;
    no.setNum(Get_numopere());
    return info_utente(GetNome(),GetCognome(),id,GetPassword(),GetCodicefiscale(),no,Getpuntdb());
}

QString utente_basic::Get_tipo_utente() const {
    return "Utente Basic";
}

/*Per poter prendere in prestito un opera:
 * 1)inanzitutto deve essere disponibile nella Biblioteca;
 * 2)poi viene verificato se l'utente è abilitato ad ottenere il prestito
 * 3)se è abilitato allora l'opera viene salvata e rimossa dal database della biblioteca
 * 4)ed aggiunta al database delle opere del utente.
 *
*/
void utente_basic::ricevi_opera(unsigned int x) {
   //cerco l'opera dentro il database:
    contenitore<opera>::iteratore it;
    contenitore<opera>::iteratore risultato;
    bool trovata=false;
    it=Getpuntdb()->begin();
    while(it!=Getpuntdb()->end() && !trovata)
    {

        if((*it)->GetId()==x){trovata=true;}
        risultato=it;
        it++;
    }
   if(trovata)
   {
       if(Get_numopere()<limiteopere)
       {
            (*risultato)->Presta_opera();
            Getcontainer()->add_item((*risultato));
            Getpuntdb()->remove_item((*risultato));

       }

   }
   else{std::cout<<"Errore l'utente non è abilitato a ricevere l'opera";}
}







