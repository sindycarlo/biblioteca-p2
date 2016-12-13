#ifndef OPERA_H
#define OPERA_H
#include "info_opera.h"
#include <QXmlStreamWriter>
#include<QString>
#include<iostream>


class opera {
private:
    QString Titolo;                          //titolo dell'opera
    bool statoPresenza;                     //se l'opera è presente oppure è in prestito
    int id;                                 //ogni opera ha un codice identificativo univoco

    static int maxid;                       //massimo id (ultimo id) che è stato assegnato ad un opera
                                            //(l'ultima opera che è stata memorizzata nel database)
public:
    opera(QString,bool =1);              //costruttore a 1,2 parametri (id della nuova opera sarà id=maxid+1)


    QString GetTitolo() const;            //restituisce il titolo di un opera
    int GetId() const;                  //restituisce id idi un opera
    int GetMaxId() const;                 //restituisce id dell'ultima opera aggiunta al database
    void Set_id(const int);             //setta id dell'opera
    void Set_maxid(const int);         //setta maxid dell'opera
    bool presente () const;              // metodo che mi dice se l'opera è presente oppure no nella biblioteca

    virtual ~opera();
    void Riscatta();                    //opera non è più in prestito quindi viene messa nella biblioteca
    virtual bool ricerca_campi(const QString&) const; //ricerco un nome di opera(stringa) nel titolo o nel id
    virtual void Write_opera(QXmlStreamWriter&) const =0; //scrivo l'opera del database
    virtual QString Get_tipo() const =0;   //ritorna il tipo di quell'opera
    virtual void Presta_opera();         //da rivedere
    virtual info_opera info_tot() const =0; // metodo che mi restituisce un oggetto di tipo info_opera che mi da tutte le informazioni sull'opera
    virtual bool disponibile() const;     //verifica se l'opera è disponibile al prestito secondo certe condizioni che vengono scelte dai sottotipi.




};




#endif // OPERA_H

