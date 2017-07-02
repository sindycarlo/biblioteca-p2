#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCloseEvent>
#include <QLabel>
#include <QMessageBox>
#include<QDesktopWidget>
#include <QApplication>
#include "listalibri.h"
#include "listariviste.h"
#include "widget_padre.h"

#include "../CONTROLLER/c_listariviste.h"
#include "../CONTROLLER/c_listalibri.h"
#include "../VIEW/homewindow.h"
#include "../MODEL/database.h"
#include "../MODEL/database_utente.h"
#include "../CONTROLLER/c_listautenti.h"



class mainWindow : public Widget_Padre
{
    Q_OBJECT
public:
    explicit mainWindow(database*,database_utente*,homewindow*,amministratore*);
    virtual void aggiorna_vista();
    virtual void costruisci_contenuto();
    void disabilita_view();
    void abilita_view();
    virtual void set_style();
    void closeEvent(QCloseEvent*);
    ~mainWindow();
signals:
    void chiudi_app();
    void rimuovi(int);
    void rimuovi_utente(int);
    void show_inserisci_rivista();
    void show_inserisci_libro();
    void show_inserisci_utente();

private slots:
    void rimuovi_segnale();
    void rimuovi_segnale_utenti();
    void slot_inserisci_rivista();
    void slot_inserisci_libro();
    void slot_inserisci_utente();
    void modifica_campo(int);
    void modifica_campo_utenti(int);
    void ricerca_opera(QString);
    void ricerca_utente(QString);
    void disabilita();
    void chiudi();
private:

    homewindow* finestraprinc;

    QLabel* r;
    QLabel* ru;
    QLineEdit* ricerca;
    QLineEdit* ricercautente;
    QGridLayout* gridr;

    database* model;
    database_utente* modelutenti;
    listalibri* tablibri;
    listariviste* tabriviste;

    listautenti* tabutenti;
    C_listalibri* controllerLP;
    C_listariviste* controllerRP;
    C_listautenti* controllerUTENTI;

    unsigned int opera_selezionata;
    unsigned int utente_selezionato;


    QPushButton* aggiungi_rivista;
    QPushButton* aggiungi_libro;
    QPushButton* rimuovi_opera;
    QPushButton* rimuovi_utenti;
    QPushButton* aggiungi_utente;
    QPushButton* exit;

    QHBoxLayout* orizzontale;
    QVBoxLayout* Prlayout, *bottoni;

    amministratore* admin;


    void creaLayout();
    void abilita_bottoni();
    void abilita_bottoni_utenti();
    void disabilita_bottoni();
    void disabilita_bottoni_utenti();
    void disabilita_bottoni_tutti();
};

#endif // MAINWINDOW_H
