#ifndef DETTAGLI_UTENTE_PRO_H
#define DETTAGLI_UTENTE_PRO_H

#include "dettagli_utente.h"

class dettagli_utente_pro : public dettagli_utente
{
    Q_OBJECT
public:
    explicit dettagli_utente_pro(int, database*,database_utente*,database_utente_opere*);
    ~dettagli_utente_pro();
public slots:
    void slot_submit();
private:
    QLabel* numeroriviste;                  //tempo di prestito assegnato all'utente
    QLineEdit* numriv;

    void costruisci_contenuto();
    void disabilita_modifica();
    void abilita_modifica();
    void set_style();

};

#endif // DETTAGLI_UTENTE_PRO_H
