#ifndef DETTAGLI_LIBRO_H
#define DETTAGLI_LIBRO_H
#include"dettagli_opera.h"

class dettagli_Libro : public dettagli_opera
{
    Q_OBJECT
public:
    explicit dettagli_Libro(int, database*,database_utente*,database_utente_opere*);
    void update_dettagli(QString,QString);
    ~dettagli_Libro();
public slots:
    void slot_submit();
private:
    QLabel* a;                  //autore
    QLineEdit* autore;

    void costruisci_contenuto();
    void disabilita_modifica();
    void abilita_modifica();
    void set_style();

};



#endif // DETTAGLI_LIBRO_H
