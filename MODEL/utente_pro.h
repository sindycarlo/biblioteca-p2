#ifndef UTENTE_PRO_H
#define UTENTE_PRO_H
#include "utente.h"
#include <QXmlStreamWriter>
#include<QString>
#include<iostream>

class utente_pro : public utente {
private:

public:
    utente_pro(database*,unsigned int,QString,QString,QString,QString);              //costruttore a 0,5 parametri (id del nuovo utente sarà id=maxid+1)

    //metodi propri di utente_pro:
    virtual void Write_utente(QXmlStreamWriter&) const; //scrivo l'utente nel database
    virtual QString Get_tipo_utente() const;   //ritorna il tipo di utente
    virtual bool ricerca(const QString,opera*) const;

};
#endif // UTENTE_PRO_H
