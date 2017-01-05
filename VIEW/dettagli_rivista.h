#ifndef DETTAGLI_RIVISTA_H
#define DETTAGLI_RIVISTA_H
#include"dettagli_opera.h"

class Dettagli_Rivista : public Dettagli_opera
{
    Q_OBJECT
public:
    explicit Dettagli_Rivista(int, database*);
    void update_dettagli();
    ~Dettagli_Rivista();
private:

    QLabel* a;                      //anno

    QLineEdit* anno;

    void costruisci_contenuto();
    void disabilita_modifica();
    void set_style();

};

#endif // DETTAGLI_RIVISTA_H



