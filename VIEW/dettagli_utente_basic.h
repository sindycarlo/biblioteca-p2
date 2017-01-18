#ifndef DETTAGLI_UTENTE_BASIC_H
#define DETTAGLI_UTENTE_BASIC_H

#include "dettagli_utente.h"

class dettagli_utente_basic : public dettagli_utente
{
    Q_OBJECT
public:
    explicit dettagli_utente_basic(int, database*,database_utente*,database_utente_opere*);
    ~dettagli_utente_basic();
public slots:
    void slot_submit();
private:
    QLabel* Numopere;                  //Numero opere in prestito
    QLineEdit* Numop;

    void costruisci_contenuto();
    void disabilita_modifica();
    void abilita_modifica();
    void set_style();

};


#endif // DETTAGLI_UTENTE_BASIC_H
