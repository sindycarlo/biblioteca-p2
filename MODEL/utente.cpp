#include "utente.h"
#include<QString>


//inizializzo maxid di un utente:
unsigned int utente::maxid=0;


//costruttore di utente:
utente::utente(QString n ="Sconosciuto", QString c ="Sconosciuto", QString  cf ="Sconosciuto", QString psw ="Sconosciuto"): Nome(n), Cognome(c), codicefiscale(cf), password(psw), opereuser(0) {
    maxid++;
    id=maxid;
}

//il distruttore di utente va a distruggere anche le sue opere che aveva in prestito
utente::~utente() {delete opereuser;}


QString utente::GetNome() const {return Nome;}

QString utente::GetCognome() const {return Cognome;}

QString utente::GetCodicefiscale() const {return codicefiscale;}

QString utente::GetPassword() const {return password;}

QString utente::GetID() const {return id;}

QString utente::Getmaxid() const {return maxid;}
