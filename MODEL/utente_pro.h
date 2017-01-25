#ifndef UTENTE_PRO_H
#define UTENTE_PRO_H
#include "utente.h"
#include <QXmlStreamWriter>
#include<QString>
#include<iostream>

//utente_pro ha un solo limite relativo al tempo di prestito di un libro, ossia non può prendere in prestito un opera per un tempo maggiore di 30 giorni
class utente_pro : public utente {
private:
unsigned int numeroriviste;
static unsigned int limiteriviste;
public:
    utente_pro(database*,database_utente_opere*,unsigned int,QString,QString,QString,QString);              //costruttore a 0,5 parametri (id del nuovo utente sarà id=maxid+1)

    //metodi propri di utente_pro:
    unsigned int Get_numeroriviste() const;
    unsigned int Get_limiteriviste() const;
    virtual void Write_utente(QXmlStreamWriter&) const; //scrivo l'utente nel database
    virtual QString Get_tipo_utente() const;   //ritorna il tipo di utente
    virtual info_utente infoutente() const;
    virtual void  ricevi_libro(unsigned int); //metodo che da in prestito un libro a seconda del tipo di utente sono imposte certe condizioni
    virtual void  ricevi_rivista(unsigned int);
    virtual void restituisci_libro(unsigned int); //metodo che restituisce un opera alla biblioteca.
    virtual void restituisci_rivista(unsigned int);
};
#endif // UTENTE_PRO_H
