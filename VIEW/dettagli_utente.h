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
    explicit dettagli_utente(int , database*,database_utente*);

    virtual void set_style();
    virtual void aggiorna_vista();
    virtual void costruisci_contenuto();
    void disabilita_modifica();
    void abilita_modifica();
    void closeEvent(QCloseEvent*);
    ~dettagli_utente();

signals:
    void modifica_utente(QString,QString,int);
    void chiudi_dettagli_utente();

public slots:
    void slot_submit();
    void esci();

private:

    int idutente;
    QLabel* n;                  //nome
    QLabel* c;                  //cognome
    QLabel* id;                  //id
    QLabel* cf;                  //codicefiscale
    QLabel* ps;                    //password
    QLabel* tuser;           //tipo utente basic o pro

    QPushButton* submit;
    QPushButton* exit;
    QLineEdit* nome;
    QLineEdit* cognome;
    QLineEdit* identificativo;
    QLineEdit* codicefiscale;
    QLineEdit* password;
    QLineEdit* tipoutente;

    QPalette* paletteLine;
    QGridLayout* grid;
    QVBoxLayout*layout;

    QLabel* Numop;                  //Numero opere in prestito
    QLineEdit* Numopere;






};

#endif // DETTAGLI_UTENTE_H
