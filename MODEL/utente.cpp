#include "utente.h"
#include<QString>


//inizializzo maxid di un utente:
unsigned int utente::maxid=0;


//costruttore di utente:
utente::utente(database *db, QString n ="Sconosciuto", QString c ="Sconosciuto", QString  cf ="Sconosciuto", QString psw ="Sconosciuto", unsigned int no=0): Nome(n), Cognome(c), codicefiscale(cf), password(psw),opereBiblioteca(db),numeroopere(no) {
    maxid++;
    id=maxid;

}

utente::~utente() {}


QString utente::GetNome() const {return Nome;}

QString utente::GetCognome() const {return Cognome;}

QString utente::GetCodicefiscale() const {return codicefiscale;}

QString utente::GetPassword() const {return password;}

unsigned int utente::GetID() const {return id;}

unsigned int utente::Getmaxid() const {return maxid;}

void utente::Set_maxid(const int x) {maxid=x;}

void utente::SetID(unsigned int x) {id=x;}

void utente::Setnome(QString n) {Nome=n;}

void utente::Setcognome(QString cn) {Cognome=cn;}

unsigned int utente::Getnumeroopere() const{return numeroopere;}
unsigned int& utente::setnumeroopere() {return numeroopere;}


void utente::restituisci_libro(unsigned int id) {
    opera*op=opereBiblioteca->trova_opera(GetID(),id);
    if(op!=0)
    {
        numeroopere--;
        info_opera o=op->info_tot();
        opereBiblioteca->remove_opera(GetID(),id);
        opereBiblioteca->aggiungi_libro(o,-1);

    }
    else std::cout<<"Errore libro non in prestito";
}

void utente::restituisci_rivista(unsigned int id) {
    opera*op=opereBiblioteca->trova_opera(GetID(),id);
    if(op!=0)
    {
        numeroopere--;
        info_opera o=op->info_tot();
         opereBiblioteca->remove_opera(GetID(),id);
        opereBiblioteca->aggiungi_rivista(o,-1);

    }
    else std::cout<<"Errore rivista non in prestito";
}


//ottengo un oggetto info_utente che mi fornisce tutte le informazioni su un utente:
info_utente utente::infoutente() const {
    QString id;
    id.setNum(GetID());
    QString tp;
    tp.setNum(numeroopere);
    return info_utente(opereBiblioteca,GetNome(),GetCognome(),id,GetPassword(),GetCodicefiscale(),tp,Get_tipo_utente());
}



void utente::ricevi_libro(unsigned int id) {

        info_opera op=opereBiblioteca->get_infoOpera(-1,id);
        opereBiblioteca->remove_opera(-1,id);
        opereBiblioteca->aggiungi_libro(op,GetID());
        numeroopere++;
}

void utente::ricevi_rivista(unsigned int id) {

        info_opera op=opereBiblioteca->get_infoOpera(-1,id);
        opereBiblioteca->aggiungi_rivista(op,GetID());
        numeroopere++;
        opereBiblioteca->remove_opera(-1,id);

}







