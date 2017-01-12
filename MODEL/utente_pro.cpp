#include "utente_pro.h"
#include "database.h"
#include "database_utente_opere.h"
#include "QString"
#include <QXmlStreamWriter>

//un utente pro ha il limite relativo al tempo di prestito di 30 giorni al massimo:
unsigned int utente_pro::limitetempo=30;

//costruttore di utente_pro:
utente_pro::utente_pro(database* db,database_utente_opere* udb, unsigned int tp =0, QString n ="Sconociuto", QString c ="Sconosciuto", QString cf ="Sconosciuto", QString psw ="Sconosciuto"): utente(db,udb,n,c,cf,psw), tempoprestito(tp) {
    if(tempoprestito>limitetempo)
    {std::cout<<"Errore: un utente pro non può prendere in prestito un opera per più di 30 giorni";tempoprestito=limitetempo;}

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


//ottengo un oggetto info_utente che mi fornisce tutte le informazioni su un utente:
info_utente utente_pro::infoutente() const {
    QString id;
    id.setNum(GetID());
    QString tp;
    tp.setNum(Get_tempoprestito());
    return info_utente(GetopereBiblioteca(),GetNome(),GetCognome(),id,GetPassword(),GetCodicefiscale(),tp);
}

QString utente_pro::Get_tipo_utente() const {
    return "Utente Pro";
}



void utente_pro::ricevi_libro(unsigned int id) {
    if(tempoprestito<=limitetempo)
    {
        info_opera op=GetopereBiblioteca()->get_infoOpera(id);
        GetdbOpereUtente()->aggiungi_libro_utente(op,GetID());
        GetopereBiblioteca()->remove_opera(id);
    }else std::cout<<"L'utente non è abilitato a ricevere il libro";
}

void utente_pro::ricevi_rivista(unsigned int id) {
    if(tempoprestito<=limitetempo)
   {
        info_opera op=GetopereBiblioteca()->get_infoOpera(id);
        GetdbOpereUtente()->aggiungi_rivista_utente(op,GetID());
        GetopereBiblioteca()->remove_opera(id);
   }else std::cout<<"L'utente non è abilitato a ricevere la rivista";
}

void utente_pro::restituisci_libro(unsigned int id) {
    opera*op=GetdbOpereUtente()->trova_operadelutente(GetID(),id);
    if(op!=0)
    {
        info_opera o=op->info_tot();
        GetdbOpereUtente()->remove_operadelutente(GetID(),id);
        GetopereBiblioteca()->add_Libro(o);
    }
    else std::cout<<"Errore libro non in prestito";
}

void utente_pro::restituisci_rivista(unsigned int id) {
    opera*op=GetdbOpereUtente()->trova_operadelutente(GetID(),id);
    if(op!=0)
    {
        info_opera o=op->info_tot();
        GetdbOpereUtente()->remove_operadelutente(GetID(),id);
        GetopereBiblioteca()->add_Rivista(o);

    }
    else std::cout<<"Errore rivista non in prestito";
}






