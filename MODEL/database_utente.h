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
   std::vector<Widget_Padre*> registro;                //registro delle view "dettagli" collegate al modello per aggiornamenti
    database* biblioteca;
    database_utente_opere* opereutenti;
    void Load();
    void Close();                                       //salva tutti i cambiamenti eseguiti dall'utente nel file XML

public:
     database_utente(database*,database_utente_opere*);
    ~database_utente();

    bool vuoto() const;                                 //ritorna true <=> contenitore è vuoto altrimenti ritorna false
    void remove_utente(const int);                       //elimina un utente
    utente* trova_utente(unsigned int) const;
    contenitore<utente> trova_utenti_insieme(const QString&) const;
    void add_utentepro(const info_utente&);                             //aggiunge un utente_pro
    void add_utentebasic(const info_utente&);                               //aggiunge un utente basic
    database* GetDatabase() const;
    database_utente_opere* Getdbopere() const;
    info_utente get_infoUtente(int) const;
    contenitore<utente>::iteratore db_iter;


    void aggiorna_view() const;                         //permette di aggiornare le view registrate al dataBase
    void add_registro_utente(Widget_Padre*);                   //registrazione al DataBase
    void remove_registro_utente(Widget_Padre*);

    contenitore<utente>::iteratore dbutenti_begin();
    contenitore<utente>::iteratore dbutenti_end();

};

#endif // DATABASE_UTENTE_H
