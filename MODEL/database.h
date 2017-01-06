#ifndef DATABASE_H
#define DATABASE_H

#include<iostream>
#include<QFile>
#include<QXmlStreamWriter>
#include<QXmlStreamReader>
#include<QString>
#include<vector>

#include"contenitore.h"
#include"opera.h"
#include"rivista.h"
#include"libro.h"
#include"info_opera.h"
#include"../VIEW/widget_padre.h"



class database{
private:
    //campi dati
    static QString filename;
    contenitore<opera> db;                                     //creo il contenitore leggendo il file xml
    std::vector<Widget_Padre*> registro;                //registro delle view "dettagli" collegate al modello per aggionramento nel caso in cui "presta/ricevi" venga con la view dettagli aperta
    void Load();
    void Close();                                       //salva tutti i cambiamenti eseguiti dall'utente nel file XML

public:
     database();
    ~database();

    bool vuoto() const;                                 //ritorna true <=> contenitore è vuoto altrimenti ritorna false
    void remove_opera(const int);                       //elimina una opera
    contenitore<opera> trova_opere_insieme(const QString&) const;
    opera* trova_opera(unsigned int) const;
    void add_Rivista(const info_opera&);                             //aggiunge una rivista
    void add_Libro(const info_opera&);                               //aggiunge una libro
    info_opera get_infoOpera(int) const;

    void aggiorna_view() const;                         //permette di aggiornare le view registrate al dataBase
    void add_registro(Widget_Padre*);                   //registrazione al DataBase
    void remove_registro(Widget_Padre*);                //permette di eliminare la registrazione al DataBase


    contenitore<opera>::iteratore db_iter;

    contenitore<opera>::iteratore db_begin();
    contenitore<opera>::iteratore db_end();

};



#endif // DATABASE_H
