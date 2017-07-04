#include "amministratore.h"

amministratore::amministratore(const QString u="admin", const QString p="admin", database *op=0, database_utente*uop=0): username(u), password(p), dbopere(op), dbutenti(uop) {}


void amministratore::add_libro(const info_opera & op) {
    dbopere->aggiungi_libro(op,-1);
}

void amministratore::add_rivista(const info_opera & op) {
    dbopere->aggiungi_rivista(op,-1);
}

void amministratore::add_utente(const info_utente & u) {
       if(u.get_tipoutente()=="Utente Basic")
           dbutenti->add_utentebasic(u);
       else if(u.get_tipoutente()=="Utente Pro")dbutenti->add_utentepro(u);
}

void amministratore::rimuovi_opera(int id) {
dbopere->remove_opera(-1,id);
}
void amministratore::rimuovi_utente(int id) {
dbutenti->remove_utente(id);
}
const QString amministratore::Getusername() const {
     return username;
 }
const QString amministratore::Getpassword() const {
     return password;
 }

int amministratore::autenticaUtente(int u, QString p, bool& trovato) const{
    //cerco utente nel database degli utenti con quel nome e quella password:
    contenitore<utente>::iteratore it;
    trovato=false;
    int id=-1;
    for(it=dbutenti->dbutenti_begin();it!=dbutenti->dbutenti_end() && !trovato;it++)
    {
        if((*it)->GetID()==u && (*it)->GetPassword()==p)
        {
            trovato=true;
            id=(*it)->GetID();
        }
    }
    if(trovato)
    {return id;}

}


void amministratore::modificaUtente(QString n, QString c,int id) {

    utente* u=dbutenti->trova_utente(id);
    if(u)
     {
        u->Setnome(n);
        u->Setcognome(c);
     }
}


void amministratore::modifica_libro(QString t, QString a, int id) {
    opera* op=dbopere->trova_opera(-1,id);
    libro* l=dynamic_cast<libro*>(op);
    if(l)
    {
        l->SetTitolo(t);
        l->SetAutore(a);
    }
}


void amministratore::modifica_rivista(QString t, QString an, int id) {
    opera* op=dbopere->trova_opera(-1,id);
    rivista* r=dynamic_cast<rivista*>(op);
    if(r)
    {
        r->SetTitolo(t);
        r->SetAnnouscita(an.toInt());
    }
}

bool amministratore::ricercautente(QString text, utente* u) const {
    if(u->GetNome().contains(text) || u->GetID()==text.toInt()) return true;
    else return false;
}

bool amministratore::ricerca(QString text, opera* a) const {
    if(a->GetTitolo().contains(text) || a->GetId()==text.toInt())return true;
    else return false;

}

amministratore::~amministratore() {}
