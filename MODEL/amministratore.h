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
    const QString Getusername() const;
    const QString Getpassword() const;
    void add_libro(const info_opera&);
    void add_rivista(const info_opera&);
    void add_utente_basic(const info_utente&);
    void add_utente_pro(const info_utente&);
    void rimuovi_opera(int);
    void rimuovi_utente(int);





};

#endif // AMMINISTRATORE_H
