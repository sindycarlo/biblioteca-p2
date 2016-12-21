#ifndef DATABASE_UTENTE_OPERE_H
#define DATABASE_UTENTE_OPERE_H
#include<iostream>
#include<QFile>
#include<QXmlStreamWriter>
#include<QXmlStreamReader>
#include<QString>
#include<vector>

#include"contenitore.h"
#include"opera.h"
#include"utente.h"
#include"utente_basic.h"
//#include"utente_pro.h"




class database_utente_opere {
private:
    //campi dati
    static QString filename;
    contenitore<opera> db;                                     //creo il contenitore leggendo il file xml

    void Load();
    void Close();                                       //salva tutti i cambiamenti eseguiti dall'utente nel file XML

public:
     database_utente_opere();
    ~database_utente_opere();

    bool vuoto() const;                                 //ritorna true <=> contenitore è vuoto altrimenti ritorna false
    void remove_operadelutente(const int);                       //elimina un utente
    opera* trova_operadelutente(unsigned int) const;
    void add_librodelutente(const info_opera&);                             //aggiunge un libro in prestito
    void add_rivistadelutente(const info_opera&);                               //aggiunge una rivista in prestito



    contenitore<opera>::iteratore db_iter;

    contenitore<opera>::iteratore db_begin();
    contenitore<opera>::iteratore db_end();

};

#endif // DATABASE_UTENTE_OPERE_H
