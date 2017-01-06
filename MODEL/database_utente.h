#ifndef DATABASE_UTENTE_H
#define DATABASE_UTENTE_H

#include<iostream>
#include<QFile>
#include<QXmlStreamWriter>
#include<QXmlStreamReader>
#include<QString>
#include<vector>

#include "info_utente.h"
#include"utente_basic.h"
#include"utente_pro.h"




class database_utente {
private:
    //campi dati
    static QString filename;
    contenitore<utente> dbutenti;                                     //creo il contenitore leggendo il file xml
    database* biblioteca;
    void Load();
    void Close();                                       //salva tutti i cambiamenti eseguiti dall'utente nel file XML

public:
     database_utente(database*);
    ~database_utente();

    bool vuoto() const;                                 //ritorna true <=> contenitore è vuoto altrimenti ritorna false
    void remove_utente(const int);                       //elimina un utente
    utente* trova_utente(unsigned int) const;
    contenitore<utente> trova_utenti_insieme(const QString&) const;
    void add_utentepro(const info_utente&);                             //aggiunge un utente_pro
    void add_utentebasic(const info_utente&);                               //aggiunge un utente basic
    database* GetDatabase() const;
    contenitore<utente>::iteratore db_iter;

    contenitore<utente>::iteratore dbutenti_begin();
    contenitore<utente>::iteratore dbutenti_end();

};

#endif // DATABASE_UTENTE_H
