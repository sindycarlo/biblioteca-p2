#ifndef UTENTE_H
#define UTENTE_H

#include <QXmlStreamWriter>
#include<QString>
#include<iostream>
#include "info_utente.h"

class utente {
private:
    QString Nome;                          //nome dell'utente
    QString Cognome;                      //cognome dell'utente
    QString codicefiscale;                 //codice fiscale dell'utente
    QString password;                       //password per accedere alla biblioteca
    database* opereBiblioteca;          //puntatore al database della biblioteca
    unsigned int id;                                 //ogni utente ha un codice identificativo univoco
    unsigned int numeroopere;
    static unsigned int maxid;                       //massimo id (ultimo id) che è stato assegnato ad un utente
                                            //(l'ultimo utente che è stato memorizzato nel database)
public:
    utente(database*, QString, QString, QString, QString, unsigned int);              //costruttore a 0,5 parametri (id del nuovo utente sarà id=maxid+1)

    virtual ~utente();
    QString GetNome() const;            //restituisce il nome di un utente
    QString GetCognome() const;         //restituisce il cognome di un utente
    QString GetCodicefiscale() const;   //restituisce il codice fiscale di un utente
    QString GetPassword() const;        //restituisce la password di un utente.
    database* GetopereBiblioteca() const;
    unsigned int GetID() const;
    unsigned int Getmaxid() const;
    unsigned int Getnumeroopere() const;
    unsigned int& setnumeroopere();
    void SetID(unsigned int);
    void Setnome(QString);
    void Setcognome(QString);
    void Set_maxid(const int);

    //metodi che sono propri della classe utente:
    void restituisci_libro(unsigned int); //metodo che restituisce un libro alla biblioteca
    void restituisci_rivista(unsigned int); //metodo che restituisce una rivista alla biblioteca
    virtual info_utente infoutente() const; //metodo che mi restituisce le informazioni su quell'utente
    void  ricevi_libro(unsigned int); //metodo che da in prestito un libro a seconda del tipo di utente sono imposte certe condizioni
    void ricevi_rivista(unsigned int); //metodo che da in prestito una rivista a seconda del tipo di utente sono imposte certe condizioni



    //metodi puri di utente:
    virtual void Write_utente(QXmlStreamWriter&) const =0; //scrivo l'utente nel database
    virtual QString Get_tipo_utente() const =0;   //ritorna il tipo di utente
    virtual bool ricerca(const QString,opera*) const =0; //metodo che permette in base al tipo di utente di cercare un opera

};

#endif // UTENTE_H
