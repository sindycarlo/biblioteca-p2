#include "utente_basic.h"
#include "database.h"
#include "QString"
#include <QXmlStreamWriter>

//costruttore di utente_basic:
utente_basic::utente_basic(database *db, unsigned int no =0, QString n ="Sconociuto", QString c ="Sconosciuto", QString cf ="Sconosciuto", QString psw ="Sconosciuto"): utente(db,n,c,cf,psw,no) {

}

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

QString utente_basic::Get_tipo_utente() const {
    return "Utente Basic";
}

 //metodo polimorfo di ricerca in base al tipo di utente:
 bool utente_basic::ricerca(const QString text, opera* op) const {
         ///eseguo una ricerca per titolo dell' opera:
         if(op->GetTitolo().contains(text) && op->Getappartenenza()==-1){
             return true;
         }else
         return false;
}



