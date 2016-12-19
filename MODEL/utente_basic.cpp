#include "utente_basic.h"
#include "QString"

//un utente_basic può ricevere in prestito massimo 5 opere;

//inizializzo la variabile statica NumOpere:
unsigned int utente_basic::limiteopere=5;


//costruttore di utente_basic:
utente_basic::utente_basic(unsigned int no =0, QString n ="Sconociuto", QString c ="Sconosciuto", QString cf ="Sconosciuto", QString psw ="Sconosciuto"): utente(n,c,cf,psw), NumOpere(no) {
    if(no>limiteopere)
    {std::cout<<"Errore: un utente basic non può prendere in prestito più di 5 opere";}
    NumOpere=limiteopere;
}


unsigned int utente_basic::Get_numopere() const {return NumOpere;}

void utente_basic::Write_utente(QXmlStreamWriter & u) const {

}


info_utente utente_basic::infoutente() const {
    int id;
    id.setNum(GetID());
    return info_utente(GetNome(),GetCognome(),id,Getpassword(),Getcodicefiscale(),NumOpere);
}
