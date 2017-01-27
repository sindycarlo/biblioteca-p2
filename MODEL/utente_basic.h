#ifndef UTENTE_BASIC_H
#define UTENTE_BASIC_H
#include "utente.h"
#include <QXmlStreamWriter>
#include<QString>
#include<iostream>

class utente_basic : public utente {
private:
    static unsigned int limiteopere_ub;

public:
    utente_basic(database*,database_utente_opere*,unsigned int,QString,QString,QString,QString);              //costruttore a 0,5 parametri (id del nuovo utente sarà id=maxid+1)

    //metodi propri di utente_basic:

    unsigned int Get_limiteopere_ub() const;
    virtual void Write_utente(QXmlStreamWriter&) const; //scrivo l'utente nel database
    virtual QString Get_tipo_utente() const;   //ritorna il tipo di utente
    virtual info_utente infoutente() const;
    virtual void  ricevi_libro(unsigned int); //metodo che da in prestito un libro a seconda del tipo di utente sono imposte certe condizioni
    virtual void  ricevi_rivista(unsigned int);
    virtual void restituisci_libro(unsigned int); //metodo che restituisce un opera alla biblioteca.
    virtual void restituisci_rivista(unsigned int);

    virtual bool checklimite() const;
};
#endif // UTENTE_BASIC_H
