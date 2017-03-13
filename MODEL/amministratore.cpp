#include "amministratore.h"

amministratore::amministratore(const QString u="admin", const QString p="admin", database *op=0, database_utente*uop=0): username(u), password(p), dbopere(op), dbutenti(uop) {}


void amministratore::add_libro(const info_opera & op) {
    dbopere->add_Libro(op);
}

void amministratore::add_rivista(const info_opera & op) {
    dbopere->add_Rivista(op);
}

void amministratore::add_utente_basic(const info_utente & u) {
    dbutenti->add_utentebasic(u);
}

void amministratore::add_utente_pro(const info_utente & u) {
    dbutenti->add_utentepro(u);
}
void amministratore::rimuovi_opera(int id) {
dbopere->remove_opera(id);
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

 amministratore::~amministratore() {}
