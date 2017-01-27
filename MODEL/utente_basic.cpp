#include "utente_basic.h"
#include "database.h"
#include "database_utente_opere.h"
#include "QString"
#include <QXmlStreamWriter>
//un utente_basic può ricevere in prestito massimo 5 opere;

//inizializzo la variabile statica NumOpere:
unsigned int utente_basic::limiteopere_ub=5;


//costruttore di utente_basic:
utente_basic::utente_basic(database *db,database_utente_opere* udb, unsigned int no =0, QString n ="Sconociuto", QString c ="Sconosciuto", QString cf ="Sconosciuto", QString psw ="Sconosciuto"): utente(db,udb,n,c,cf,psw,no) {

}


unsigned int utente_basic::Get_limiteopere_ub() const {return limiteopere_ub;}

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
    unsigned int k=Getnumeroopere();
    QString z;
    z.setNum(k);
    XmlWriter.writeTextElement("NumeroOpere",z);
    XmlWriter.writeEndElement();
}

//ottengo un oggetto info_utente che mi fornisce tutte le informazioni su un utente:
info_utente utente_basic::infoutente() const {
    QString id;
    id.setNum(GetID());
    QString no;
    no.setNum(Getnumeroopere());
    return info_utente(GetopereBiblioteca(),GetNome(),GetCognome(),id,GetPassword(),GetCodicefiscale(),no);
}

QString utente_basic::Get_tipo_utente() const {
    return "Utente Basic";
}

 bool utente_basic::checklimite() const {
    if(Getnumeroopere()<limiteopere_ub) return true;
    else return false;
}



void utente_basic::ricevi_libro(unsigned int id) {
    if(Getnumeroopere()<limiteopere_ub)
    {
        info_opera op=GetopereBiblioteca()->get_infoOpera(id);
        GetdbOpereUtente()->aggiungi_libro_utente(op,GetID());
        setnumeroopere()++;
        GetopereBiblioteca()->remove_opera(id);
    }
}

void utente_basic::ricevi_rivista(unsigned int id) {
    if(Getnumeroopere()<limiteopere_ub)
    {
        info_opera op=GetopereBiblioteca()->get_infoOpera(id);
        GetdbOpereUtente()->aggiungi_rivista_utente(op,GetID());
        setnumeroopere()++;
        GetopereBiblioteca()->remove_opera(id);
    }
}

void utente_basic::restituisci_libro(unsigned int id) {
    opera*op=GetdbOpereUtente()->trova_operadelutente(GetID(),id);
    if(op!=0)
    {
        setnumeroopere()--;
        info_opera o=op->info_tot();
        GetdbOpereUtente()->remove_operadelutente(GetID(),id);
        GetopereBiblioteca()->add_Libro(o);

    }
    else std::cout<<"Errore libro non in prestito";
}

void utente_basic::restituisci_rivista(unsigned int id) {
    opera*op=GetdbOpereUtente()->trova_operadelutente(GetID(),id);
    if(op!=0)
    {
        setnumeroopere()--;
        info_opera o=op->info_tot();
         GetdbOpereUtente()->remove_operadelutente(GetID(),id);
        GetopereBiblioteca()->add_Rivista(o);

    }
    else std::cout<<"Errore rivista non in prestito";
}




