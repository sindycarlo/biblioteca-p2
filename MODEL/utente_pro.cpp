#include "utente_pro.h"
#include "database.h"
#include "QString"
#include <QXmlStreamWriter>


//costruttore di utente_pro:
utente_pro::utente_pro(database* db, unsigned int tp =0, QString n ="Sconociuto", QString c ="Sconosciuto", QString cf ="Sconosciuto", QString psw ="Sconosciuto"): utente(db,n,c,cf,psw,tp) {
}

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
    unsigned int k=Getnumeroopere();
    QString z;
    z.setNum(k);
    XmlWriter.writeTextElement("NumeroOpere",z);
    XmlWriter.writeEndElement();
}

QString utente_pro::Get_tipo_utente() const {
    return "Utente Pro";
}

//metodo polimorfo di ricerca in base al tipo di utente:
bool utente_pro::ricerca(const QString text, opera* op) const {
    ///eseguo una ricerca per titolo dell' opera:
    if((op->GetTitolo()==text || op->GetId()==text.toInt()) && op->Getappartenenza()==-1){
        return true;
    }else
    return false;
}



