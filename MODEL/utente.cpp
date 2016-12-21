#include "utente.h"
#include<QString>


//inizializzo maxid di un utente:
unsigned int utente::maxid=0;


//costruttore di utente:
utente::utente(QString n ="Sconosciuto", QString c ="Sconosciuto", QString  cf ="Sconosciuto", QString psw ="Sconosciuto",contenitore<opera>*db =0): Nome(n), Cognome(c), codicefiscale(cf), password(psw),opereuser(new contenitore<opera>()),puntdb(db) {
    maxid++;
    id=maxid;
}

//il distruttore di utente va a distruggere anche le sue opere che aveva in prestito
utente::~utente() {delete opereuser;}


QString utente::GetNome() const {return Nome;}

QString utente::GetCognome() const {return Cognome;}

QString utente::GetCodicefiscale() const {return codicefiscale;}

QString utente::GetPassword() const {return password;}

unsigned int utente::GetID() const {return id;}

unsigned int utente::Getmaxid() const {return maxid;}

void utente::SetID(unsigned int x) {id=x;}

//credo che in questo caso si renda necessario dynamic cast in quanto:
/*
 * 1) libro e rivista sono diversi in quanto a priori non posso sapere se
 * l'opera che sto per restituire ha un autore (libro) oppure un anno di uscita (rivista)
 *

*/
void utente::restituisci_opera(unsigned int x) {
contenitore<opera>::iteratore it;
contenitore<opera>::iteratore risultato;
bool trovata=false;
it=Getcontainer()->begin();
while(it!=Getcontainer()->end() && !trovata)
{

    if((*it)->GetId()==x) trovata=true;
    risultato=it;
    it++;
}

if(trovata)
{
    (*risultato)->Riscatta();
    Getpuntdb()->add_item(*risultato);
    Getcontainer()->remove_item((*risultato));
}

else {std::cout<<"ATTENZIONE!"<<" "<<"nessuna opera in prestito impossibile restituirla!";}

}
