#include "utente.h"
#include<QString>


//inizializzo maxid di un utente:
unsigned int utente::maxid=0;


//costruttore di utente:
utente::utente(QString n ="Sconosciuto", QString c ="Sconosciuto", QString  cf ="Sconosciuto", QString psw ="Sconosciuto", database * db =0): Nome(n), Cognome(c), codicefiscale(cf), password(psw),opereuser(new contenitore<opera>()),puntdb(db) {
    maxid++;
    id=maxid;
}

//il distruttore di utente va a distruggere anche le sue opere che aveva in prestito
utente::~utente() {}


QString utente::GetNome() const {return Nome;}

QString utente::GetCognome() const {return Cognome;}

QString utente::GetCodicefiscale() const {return codicefiscale;}

QString utente::GetPassword() const {return password;}

unsigned int utente::GetID() const {return id;}

unsigned int utente::Getmaxid() const {return maxid;}

void utente::SetID(unsigned int x) {id=x;}

void utente::restituisci_opera(unsigned int x) {
opera* op=Getpuntdb()->trova_opera(x);
if(op!=0)
{
   Getcontainer()->add_item(op); opereuser->remove_item(op);
}
else {std::cout<<"nessuna opera in prestito impossibile restituirla!";}
}
