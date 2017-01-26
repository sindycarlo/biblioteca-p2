#ifndef DETTAGLI_UTENTE_H
#define DETTAGLI_UTENTE_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>
#include <QGridLayout>

#include"../MODEL/database_utente.h"
#include "widget_padre.h"


class dettagli_utente : public Widget_Padre{
    Q_OBJECT

public:
    void closeEvent();
    virtual ~dettagli_utente();

signals:
    void modifica_utente(QString,QString,int);
    void chiudi_dettagli_utente();



protected:
    explicit dettagli_utente(int , database*,database_utente*,database_utente_opere*);

    virtual void set_style();
    virtual void costruisci_contenuto();
    void disabilita_modifica();
    void abilita_modifica();


private:

    int idutente;
    QLabel* n;                  //nome
    QLabel* c;                  //cognome
    QLabel* id;                  //id
    QLabel* cf;                  //codicefiscale
    QLabel* ps;                    //password

    QPushButton* submit;
    QLineEdit* nome;
    QLineEdit* cognome;
    QLineEdit* identificativo;
    QLineEdit* codicefiscale;
    QLineEdit* password;

    QPalette* paletteLine;
    QGridLayout* grid;
    QVBoxLayout*layout;

    void registra_utente() const;
    void elimina_registrazione_utente() const;

public:
    QLineEdit* Getnome() const;
    QLineEdit* Getcognome() const;
    QLineEdit* Getcodicefiscale() const;
    virtual void aggiorna_vista();
    int get_ID()const;
    QPalette* get_paletteLine()const;
    QGridLayout* get_grid()const;
    QPushButton* get_submit() const;

};

#endif // DETTAGLI_UTENTE_H
