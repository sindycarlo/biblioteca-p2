#ifndef UTENTE_BASIC_H
#define UTENTE_BASIC_H
#include "info_utente.h"
#include "utente.h"
#include <QXmlStreamWriter>
#include<QString>
#include<iostream>

class utente_basic {
private:
    unsigned int NumOpere;
    static unsigned int limiteopere;

public:
    utente_basic(unsigned int,QString,QString,QString,QString);              //costruttore a 0,5 parametri (id del nuovo utente sarà id=maxid+1)

    //metodi propri di utente_basic:
    unsigned int Get_numopere() const;
    virtual void Write_utente(QXmlStreamWriter&) const; //scrivo l'utente nel database
    virtual QString Get_tipo_utente() const;   //ritorna il tipo di utente
    virtual info_utente infoutente() const;
    virtual void  ricevi_opera(QString); //metodo che da in prestito un opera a seconda del tipo di utente sono imposte certe condizioni
    virtual void restituisci_opera(const opera&); //metodo che restituisce un opera alla biblioteca.

};
#endif // UTENTE_BASIC_H
