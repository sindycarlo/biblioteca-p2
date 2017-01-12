#ifndef UTENTEWINDOW_H
#define UTENTEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include<QDesktopWidget>
#include <QApplication>
#include "../CONTROLLER/c_listalibri.h"
#include "listalibri.h"
#include "../CONTROLLER/c_listariviste.h"
#include "listariviste.h"

#include "../MODEL/database.h"
#include "../MODEL/database_utente.h"
#include "../MODEL/database_utente_opere.h"



class utenteWindow : public Widget_Padre
{
    Q_OBJECT
public:
    explicit utenteWindow(unsigned int,database*,database_utente*,database_utente_opere*);
    virtual void aggiorna_vista();
    virtual void costruisci_contenuto();
    unsigned int Getidutente() const;
    virtual void set_style();
    void closeEvent(QCloseEvent*);
    ~utenteWindow();
signals:
    void chiudi_app();
    void show_ricevi_rivista(unsigned int);
    void show_ricevi_libro(unsigned int);
    void show_restituisci_rivista(unsigned int);
    void show_restituisci_libro(unsigned int);


private slots:
    void ricevi_segnale_libri();
    void ricevi_segnale_riviste();
    void restituisci_segnale_libri();
    void restituisci_segnale_riviste();
    void modifica_campo_libro(int);
    void modifica_campo_rivista(int);
    void modifica_campo_libro_prestito(int);
    void modifica_campo_rivista_prestito(int);
private:
    unsigned int idutente;
    database* model;
    database_utente_opere* modelutenteopere;
    listalibri* tablibri;
    C_listalibri* controllerLB;
    listariviste* tabriviste;
    C_listariviste* controllerRB;
    listalibri* tablibriprestito;
    C_listalibri* controllerLBprestito;
    listariviste* tabrivisteprestito;
    C_listariviste* controllerRBprestito;



    int libro_selezionato;
    int rivista_selezionata;


    QPushButton* ricevi_libro;
    QPushButton* ricevi_rivista;
    QPushButton* restituisci_libro;
    QPushButton* restituisci_rivista;
    QPushButton* exit;

    QHBoxLayout* orizzontale;
    QVBoxLayout* Prlayout, *bottoni,*verticale;

    void creaLayout();
    void abilita_bottoni_libri();
    void disabilita_bottoni_libri();
    void abilita_bottoni_riviste();
    void disabilita_bottoni_riviste();
    void abilita_bottoni_libri_prestito();
    void disabilita_bottoni_libri_prestito();
    void abilita_bottoni_riviste_prestito();
    void disabilita_bottoni_riviste_prestito();
};
#endif // UTENTEWINDOW_H
