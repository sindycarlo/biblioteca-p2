#ifndef AMMINISTRATORE_H
#define AMMINISTRATORE_H

#include<QString>
#include<MODEL/database.h>
#include<MODEL/database_utente.h>

class amministratore
{
private:
    database_utente* utentiDb;
   database* opereDb;
public:
    amministratore(database_utente* uDb, database* oDb);
    void rimuoviutente(const int);
    void rimuoviopera(const int idopera);
    contenitore<opera>::iteratore begin() const;
    contenitore<opera>::iteratore end() const;
    bool dbEmpty() const;
    contenitore<utente>::iteratore ubegin() const;
    contenitore<utente>::iteratore uend() const;
    void addUtenteBasic(const info_utente&);
     void addUtentePro(const info_utente&);
    void addLibro(const info_opera&);
    void addRivista(const info_opera&);
    utente* trovaUtente(const int);


};



#endif // AMMINISTRATORE_H
