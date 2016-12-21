#ifndef INFO_UTENTE_H
#define INFO_UTENTE_H

#include <iostream>
#include <QString>
#include "database.h"

//Un oggetto di tipo info_utente mi restituisce tutte le informazioni di quell'utente d'invocazione
class info_utente
{
private:
    QString nome;
    QString cognome;
    QString ID;
    QString password;
    QString codicefiscale;
    QString dettaglio;
    database* punt;
public:
    info_utente(QString, QString, QString, QString, QString, QString, database*); //costruttore 0~5 parametri.
    QString get_nome() const;
    QString get_cognome() const;
    QString get_ID() const;
    QString get_password() const;
    QString get_codicefiscale() const;
    QString get_dettaglio() const;
    database* get_database() const;
};

#endif // INFO_UTENTE_H
