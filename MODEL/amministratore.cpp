#include<MODEL/amministratore.h>

amministratore::amministratore(database_utente* uDb, database* oDb) : utentiDb(uDb), opereDb(oDb){}

void amministratore::rimuoviutente(const int idutente){
    utentiDb->remove_utente(idutente);
}
void amministratore::rimuoviopera(const int idopera){
    opereDb->remove_opera(idopera);
}


utente* amministratore::trovaUtente(const int idutente){
    return utentiDb->trova_utente(idutente);
}

contenitore<opera>::iteratore amministratore::begin() const{return opereDb->db_begin();}
contenitore<opera>::iteratore amministratore::end() const{return opereDb->db_end();}

contenitore<utente>::iteratore amministratore::ubegin() const{return utentiDb->dbutenti_begin();}
contenitore<utente>::iteratore amministratore::uend() const{return utentiDb->dbutenti_end();}


bool amministratore::dbEmpty() const {return utentiDb->vuoto();}


void amministratore::addUtentePro(const info_utente& u){
    utentiDb->add_utentepro(u);
    }

void amministratore::addUtenteBasic(const info_utente& u){
    utentiDb->add_utentebasic(u);
    }

void amministratore::addLibro(const info_opera& l){
    opereDb->add_Libro(l);
}
void amministratore::addRivista(const info_opera& r){
    opereDb->add_Rivista(r);
}
