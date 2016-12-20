#include"info_utente.h"
#include <QXmlStreamWriter>
#include<QString>
#include<iostream>



info_utente::info_utente(QString n ="Sconosciuto", QString c ="Sconosciuto", QString  id ="Sconosciuto", QString psw ="Sconosciuto", QString cf ="Sconosciuto",QString det ="Sconosciuto") : nome(n), cognome(c), ID(id), password(psw), codicefiscale(cf), dettaglio(det) {}





QString info_utente::get_nome() const{return nome;}
QString info_utente::get_cognome() const{return cognome;}
QString info_utente::get_ID() const{return ID;}
QString info_utente::get_password() const{return password;}
QString info_utente::get_codicefiscale() const{return codicefiscale;}
QString info_utente::get_dettaglio() const{return dettaglio;}