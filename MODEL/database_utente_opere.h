#ifndef DATABASE_UTENTE_OPERE_H
#define DATABASE_UTENTE_OPERE_H
#include<iostream>
#include<QFile>
#include<QXmlStreamWriter>
#include<QXmlStreamReader>
#include<QString>
#include<vector>
#include <QXmlQuery>

#include "info_utente.h"
#include "database.h"
#include "utente.h"

#include "database_utente.h"



class database_utente_opere {
private:
    //campi dati
    static QString filename;
    contenitore<opera> dbopereutente;                                     //creo il contenitore leggendo il file xml
    database_utente* utenti;
    void Load();
    void Close();                                       //salva tutti i cambiamenti eseguiti dall'utente nel file XML

public:
    database_utente_opere(database_utente*);
    ~database_utente_opere();

    bool vuoto() const;                                 //ritorna true <=> contenitore è vuoto altrimenti ritorna false
    void remove_operadelutente(const int, const int);                       //elimina un utente
    opera* trova_operadelutente(unsigned int,unsigned int) const;
    void aggiungi_libro_utente(const info_opera&,unsigned int);                 //aggiunge un opera al database ossia al contenitore
    void aggiungi_rivista_utente(const info_opera&,unsigned int);
    database_utente* Getutente() const;


    contenitore<opera>::iteratore db_iter;

    contenitore<opera>::iteratore dbopereutenti_begin();
    contenitore<opera>::iteratore dbopereutenti_end();

};

#endif // DATABASE_UTENTE_OPERE_HB

