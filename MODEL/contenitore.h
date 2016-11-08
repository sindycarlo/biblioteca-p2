// contenitore base che gestisce la memoria con gli smartp

#ifndef CONTENITORE_H
#define CONTENITORE_H

#include<iostream>
#include "opera.h"

class contenitore{
    friend class iteratore;
private:
    class nodo;

    class smartp{
    public:
            smartp(nodo* =0);							//costruttore 0~1 parametro + convertitore implicito nodo*->smartp
            ~smartp();									//distruttore
            smartp(const smartp&);						//costruttore di copia
            smartp& operator=(const smartp&);			//operatore di assegnazione
            bool operator==(const smartp&)const;		//operatore di uguaglianza
            bool operator!=(const smartp&)const;		//operatore di disuguaglianza
            nodo* operator->()const;					//operatore di accesso a membro
            nodo& operator*()const;

            nodo* punt;
        };

    class nodo{
    public:
        nodo(opera*, const smartp& =0);
        opera* op;
        smartp next;
        int riferimenti;
    };
    //campo dati
    smartp first;

public:
    class iteratore{
        friend class contenitore;
    private:
        contenitore::smartp punt;
    public:
        bool operator==(const iteratore&) const;       //operatore di uguaglianza
        bool operator!=(const iteratore&) const;       //operatore di disuguaglianza
        iteratore& operator++();                       //operatore di incremento prefisso
        iteratore& operator++(int);                    //operatore di incremento postfisso
        opera* operator*()const;                      //operatore di accesso a membro

    };

    contenitore();                                         //costruttore contenitore vuoto

    contenitore& operator=(const contenitore&);              //assegnazione con smartp

    contenitore(const contenitore&);                         //costruzione di copia

    //metodi pubblici contenitore
    bool empty() const;                                  // 1 <=> contenitore vuoto
    void add_item(opera*);                               //aggiunta opera in coda alla lista
    void remove_item(opera*);                            //rimuovi una opera dalla lista

    iteratore begin() const;
    iteratore end() const;
    opera* operator[](const iteratore&) const;

};



#endif // CONTENITORE_H




