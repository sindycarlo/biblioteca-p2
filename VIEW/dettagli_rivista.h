#ifndef DETTAGLI_RIVISTA_H
#define DETTAGLI_RIVISTA_H
#include"dettagli_opera.h"

class dettagli_Rivista : public dettagli_opera
{
    Q_OBJECT
public:
    explicit dettagli_Rivista(int, database*,database_utente*);
    ~dettagli_Rivista();
public slots:
    void slot_submit();
private:
    QLabel* a;                      //anno
    QLineEdit* anno;

    void costruisci_contenuto();
    void disabilita_modifica();
    void abilita_modifica();
    void set_style();

};

#endif // DETTAGLI_RIVISTA_H
