#include "utente_basic.h"
#include "database.h"
#include "database_utente_opere.h"
#include "QString"
#include <QXmlStreamWriter>
//un utente_basic può ricevere in prestito massimo 5 opere;

//inizializzo la variabile statica NumOpere:
unsigned int utente_basic::limiteopere=5;


//costruttore di utente_basic:
utente_basic::utente_basic(database *db, unsigned int no =0, QString n ="Sconociuto", QString c ="Sconosciuto", QString cf ="Sconosciuto", QString psw ="Sconosciuto"): utente(db,n,c,cf,psw), NumOpere(no) {
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
    XmlWriter.writeTextElement("Tipoutente","1");
    int id=GetID();
    QString x;
    x.setNum(id);
    //scrivo id dell'utente:
    XmlWriter.writeTextElement("Idutente",x);
    //scorro il contenitore di utente basic:
    contenitore<opera>::iteratore it;
    for(it=GetdbOpereUtente()->dbopereutenti_begin();it!=GetdbOpereUtente()->dbopereutenti_end();it++)
    {
        if((*it)->Getappartenenza()==GetID())
        {(*it)->Write_opera(XmlWriter);}
    }
    XmlWriter.writeEndElement();
}

//ottengo un oggetto info_utente che mi fornisce tutte le informazioni su un utente:
info_utente utente_basic::infoutente() const {
    QString id;
    id.setNum(GetID());
    QString no;
    no.setNum(Get_numopere());
    return info_utente(GetopereBiblioteca(),GetNome(),GetCognome(),id,GetPassword(),GetCodicefiscale(),no);
}

QString utente_basic::Get_tipo_utente() const {
    return "Utente Basic";
}



void utente_basic::ricevi_libro(unsigned int id) {
    info_opera op=GetopereBiblioteca()->get_infoOpera(id);
    GetdbOpereUtente()->aggiungi_libro_utente(op,GetID());
    GetopereBiblioteca()->remove_opera(id);
}

void utente_basic::ricevi_rivista(unsigned int id) {
    info_opera op=GetopereBiblioteca()->get_infoOpera(id);
    GetdbOpereUtente()->aggiungi_rivista_utente(op,GetID());
    //GetopereBiblioteca()->remove_opera(id);
}





