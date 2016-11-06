#ifndef OPERA_H
#define OPERA_H

#include<string>
#include<iostream>


class opera {
private:
    string Titolo;                          //titolo dell'opera
    bool statoPresenza;                     //se l'opera è presente oppure è in prestito
    int id;                                 //ogni opera ha un codice identificativo univoco

    static int maxid;                       //massimo id (ultimo id) che è stato assegnato ad un opera
                                            //(l'ultima opera che è stata memorizzata nel database)
public:
    opera(string,bool =1) {}                //costruttore a 1,2 parametri (id della nuova opera sarà id=maxid+1)


    string GetTitolo() const {}             //restituisce il titolo di un opera
    int GetId() const  {}                   //restituisce id idi un opera
    int GetMaxId() const {}                 //restituisce id dell'ultima opera aggiunta al database
    //void Set_id(const int) {}             //setta id dell'opera
    //void Set_maxid(const int) {}          //setta maxid dell'opera


    virtual ~opera() {}
    void Riscatta() {}                      //opera non è più in prestito quindi viene messa nella biblioteca
    virtual bool ricerca_campi(const string&) const {} //ricerco un nome di opera(stringa) nel titolo o nel id
    virtual void Scrivi_opera(/*manca*/) =0 {} //scrivo l'opera del database
    virtual string Get_tipo() const =0 {}   //ritorna il tipo di quell'opera
    virtual void Presta_opera() {}          //da rivedere




};




#endif // OPERA_H

