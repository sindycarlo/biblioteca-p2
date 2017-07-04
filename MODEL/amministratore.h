#ifndef AMMINISTRATORE_H
#define AMMINISTRATORE_H
#include "database.h"
#include "database_utente.h"
#include "info_utente.h"
class amministratore {
private:
    const QString username;
    const QString password;
    database* dbopere;
    database_utente* dbutenti;

 public:
    amministratore(const QString u, const QString p, database* op, database_utente* uop);
    ~amministratore();

    //metodi propri di amministratore:
    const QString Getusername() const;
    const QString Getpassword() const;
    void add_libro(const info_opera&);
    void add_rivista(const info_opera&);
    void add_utente(const info_utente&);
    void modifica_rivista(QString,QString,int);
    void modifica_libro(QString,QString,int);
    void modificaUtente(QString, QString,int);
    int autenticaUtente(int,QString,bool&) const;
    void rimuovi_opera(int);
    void rimuovi_utente(int);
    bool ricercautente(QString,utente*) const;
    bool ricerca(QString,opera*) const;

};

#endif // AMMINISTRATORE_H
