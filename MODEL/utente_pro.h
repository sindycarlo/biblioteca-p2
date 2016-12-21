#ifndef UTENTE_PRO_H
#define UTENTE_PRO_H
#include "info_utente.h"
#include "utente.h"
#include <QXmlStreamWriter>
#include<QString>
#include<iostream>

//utente_pro ha un solo limite relativo al tempo di prestito di un libro, ossia non può prendere in prestito un opera per un tempo maggiore di 30 giorni
class utente_pro : public utente {
private:
unsigned int tempoprestito;
static unsigned int limitetempo;
public:
    utente_pro(unsigned int,QString,QString,QString,QString,contenitore<opera>*);              //costruttore a 0,5 parametri (id del nuovo utente sarà id=maxid+1)

    //metodi propri di utente_pro:
    unsigned int Get_tempoprestito() const;
    virtual void Write_utente(QXmlStreamWriter&) const; //scrivo l'utente nel database
     virtual void Write_utenteopere(QXmlStreamWriter&) const;
    virtual QString Get_tipo_utente() const;   //ritorna il tipo di utente
    virtual info_utente infoutente() const;
    virtual void  ricevi_opera(unsigned int); //metodo che da in prestito un opera a seconda del tipo di utente sono imposte certe condizioni

};
#endif // UTENTE_PRO_H
