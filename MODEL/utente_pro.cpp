#include "utente_pro.h"
#include "database.h"
#include "QString"
#include <QXmlStreamWriter>

//un utente pro ha il limite relativo al tempo di prestito di 30 giorni al massimo:
unsigned int utente_pro::limitetempo=30;

//costruttore di utente_pro:
utente_pro::utente_pro(unsigned int tp =0, QString n ="Sconociuto", QString c ="Sconosciuto", QString cf ="Sconosciuto", QString psw ="Sconosciuto",database* db =0): utente(n,c,cf,psw,db), tempoprestito(tp) {
    if(tp>limitetempo)
    {std::cout<<"Errore: un utente pro non può prendere in prestito un opera per più di 30 giorni";}
    tempoprestito=limitetempo;
}


unsigned int utente_pro::Get_tempoprestito() const {return tempoprestito;}

//scrive nel file xml un utente basic:
void utente_pro::Write_utente(QXmlStreamWriter &XmlWriter) const {
    XmlWriter.writeStartElement("utente");

    //essendo un utente pro il tipo è "2";
    XmlWriter.writeTextElement("Tipoutente","2");
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
    unsigned int k=Get_tempoprestito();
    QString z;
    z.setNum(k);
    XmlWriter.writeTextElement("Tempoprestito",z);
    XmlWriter.writeEndElement();
}


//scrive nel file xml le opere di un utente basic:
void utente_pro::Write_utenteopere(QXmlStreamWriter &XmlWriter) const {
    XmlWriter.writeStartElement("utente");

    //essendo un utente pro il tipo è "2";
    XmlWriter.writeTextElement("Tipo","2");
    int id=GetID();
    QString x;
    x.setNum(id);
    //scrivo id dell'utente:
    XmlWriter.writeTextElement("Id",x);
    //scorro il contenitore di utente pro:
    contenitore<opera>::iteratore it;
    for(it=Getcontainer()->begin();it!=Getcontainer()->end();it++)
    {(*it)->Write_opera(XmlWriter);}
    XmlWriter.writeEndElement();
}

//ottengo un oggetto info_utente che mi fornisce tutte le informazioni su un utente:
info_utente utente_pro::infoutente() const {
    QString id;
    id.setNum(GetID());
    QString tp;
    tp.setNum(Get_tempoprestito());
    return info_utente(GetNome(),GetCognome(),id,GetPassword(),GetCodicefiscale(),no,Getpuntdb());
}

QString utente_pro::Get_tipo_utente() const {
    return "Utente Pro";
}

/*Per poter prendere in prestito un opera:
 * 1)inanzitutto deve essere disponibile nella Biblioteca;
 * 2)poi viene verificato se l'utente è abilitato ad ottenere il prestito
 * 3)se è abilitato allora l'opera viene salvata e rimossa dal database della biblioteca
 * 4)ed aggiunta al database delle opere del utente.
 *
*/
void utente_pro::ricevi_opera(unsigned int x) {
   //cerco l'opera dentro il database:
   opera*op=Getpuntdb()->trova_opera(x);
   if(op->disponibile()==true && Get_numopere()<=NumOpere)
   {
        op->Presta_opera();
        Getcontainer()->add_item(op);
        int id=op->GetId();
        Getpuntdb()->remove_opera(id);
   }
   else{std::cout<<"Errore l'utente non è abilitato a ricevere l'opera";}
}







