#ifndef UTENTE_BASIC_H
#define UTENTE_BASIC_H
#include "utente.h"
#include <QXmlStreamWriter>
#include<QString>
#include<iostream>


class utente_basic : public utente {
private:

public:
    utente_basic(database*,unsigned int,QString,QString,QString,QString);              //costruttore a 0,5 parametri (id del nuovo utente sarà id=maxid+1)

    //metodi propri di utente_basic:
    virtual void Write_utente(QXmlStreamWriter&) const; //scrivo l'utente nel database
    virtual QString Get_tipo_utente() const;   //ritorna il tipo di utente
    virtual bool ricerca(const QString,opera*) const;
};
#endif // UTENTE_BASIC_H
