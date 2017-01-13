#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include<QDesktopWidget>
#include <QApplication>
#include "listalibri.h"
#include "listariviste.h"
#include "widget_padre.h"

#include "../CONTROLLER/c_listariviste.h"
#include "../CONTROLLER/c_listalibri.h"
#include "../MODEL/database.h"
#include "../MODEL/database_utente.h"
#include "../CONTROLLER/c_listautenti.h"



class mainWindow : public Widget_Padre
{
    Q_OBJECT
public:
    explicit mainWindow(database*,database_utente*,database_utente_opere*);
    virtual void aggiorna_vista();
    virtual void costruisci_contenuto();
    void costruisci_Tabella_opere(const contenitore<opera>&);
    void costruisci_Tabellautenti(const contenitore<utente>&);
    virtual void set_style();
    void closeEvent(QCloseEvent*);
    ~mainWindow();
signals:
    void chiudi_app();
    void rimuovi(int);
    void rimuovi_utente(int);
    void show_inserisci_rivista();
    void show_inserisci_libro();
    void show_inserisci_utentebasic();
    void show_inserisci_utentepro();
    void cerca_opera(QString);
    void cerca_utente(QString);

private slots:
    void rimuovi_segnale();
    void rimuovi_segnale_utenti();
    void slot_inserisci_rivista();
    void slot_inserisci_libro();
    void slot_inserisci_utentebasic();
    void slot_inserisci_utentepro();
    void modifica_campo(int);
    void modifica_campo_utenti(int);
    void disabilita();
    void testo_editato_utenti(const QString&);
    void testo_editato(const QString&);
private:
    database* model;
    database_utente* modelutenti;
    listalibri* tablibri;
    listariviste* tabriviste;

    listautenti* tabutenti;
    C_listalibri* controllerLP;
    C_listariviste* controllerRP;
    C_listautenti* controllerUTENTI;

    int opera_selezionata;
    int utente_selezionato;

    QLineEdit* barra_cerca;
    QLineEdit* barra_cercautenti;

    QPushButton* aggiungi_rivista;
    QPushButton* aggiungi_libro;
    QPushButton* rimuovi_opera;
    QPushButton* rimuovi_utenti;
    QPushButton* aggiungi_utente_basic;
    QPushButton* aggiungi_utente_pro;
    QPushButton* exit;

    QHBoxLayout* orizzontale;
    QVBoxLayout* Prlayout, *bottoni;

    void creaLayout();
    void abilita_bottoni();
    void abilita_bottoni_utenti();
    void disabilita_bottoni();
    void disabilita_bottoni_utenti();

    void disabilita_bottoni_tutti();
};

#endif // MAINWINDOW_H
