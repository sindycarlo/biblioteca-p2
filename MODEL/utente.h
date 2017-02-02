#ifndef UTENTE_H
#define UTENTE_H

#include <QXmlStreamWriter>
#include<QString>
#include<iostream>
#include "info_utente.h"

class database_utente_opere;


class utente {
private:
    QString Nome;                          //nome dell'utente
    QString Cognome;                      //cognome dell'utente
    QString codicefiscale;                 //codice fiscale dell'utente
    QString password;                       //password per accedere alla biblioteca
    database* opereBiblioteca;          //puntatore al database della biblioteca
    database_utente_opere* opereUtente;     //ogni utente ha un database con le proprie opere in prestito
    unsigned int id;                                 //ogni utente ha un codice identificativo univoco


    unsigned int numeroopere;

    static unsigned int maxid;                       //massimo id (ultimo id) che è stato assegnato ad un utente
                                            //(l'ultimo utente che è stato memorizzato nel database)
public:
    utente(database*, database_utente_opere*, QString, QString, QString, QString, unsigned int);              //costruttore a 0,5 parametri (id del nuovo utente sarà id=maxid+1)


    virtual ~utente();
    QString GetNome() const;            //restituisce il nome di un utente
    QString GetCognome() const;         //restituisce il cognome di un utente
    QString GetCodicefiscale() const;   //restituisce il codice fiscale di un utente
    QString GetPassword() const;        //restituisce la password di un utente.
    database_utente_opere* GetdbOpereUtente() const;
    database* GetopereBiblioteca() const;
    unsigned int GetID() const;
    unsigned int Getmaxid() const;
    unsigned int Getnumeroopere() const;
    unsigned int& setnumeroopere();

    void SetID(unsigned int);
    void Setnome(QString);
    void Setcognome(QString);
    void Set_maxid(const int);

    //metodi propri di utente:
    virtual void Write_utente(QXmlStreamWriter&) const =0; //scrivo l'utente nel database
    virtual QString Get_tipo_utente() const =0;   //ritorna il tipo di utente
    virtual info_utente infoutente() const =0;
    virtual void  ricevi_libro(unsigned int) =0; //metodo che da in prestito un libro a seconda del tipo di utente sono imposte certe condizioni
    virtual void ricevi_rivista(unsigned int) =0; //metodo che da in prestito una rivista a seconda del tipo di utente sono imposte certe condizioni
    virtual void restituisci_libro(unsigned int)=0; //metodo che restituisce un opera alla biblioteca.
    virtual void restituisci_rivista(unsigned int)=0;

    virtual bool checklimite() const =0;
};

#endif // UTENTE_H
