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
#include "widget_padre.h"
#include "../CONTROLLER/c_listaop.h"
#include "listaop.h"

#include "../MODEL/database.h"
#include "../MODEL/database_utente.h"
#include "../MODEL/database_utente_opere.h"



class utenteWindow : public Widget_Padre
{
    Q_OBJECT
public:
    explicit utenteWindow(database*,database_utente*,database_utente_opere*);
    virtual void aggiorna_vista();
    virtual void costruisci_contenuto();
    void costruisci_Tabella_libri(const contenitore<opera>&);
    void costruisci_Tabella_riviste(const contenitore<opera>&);
    void costruisci_Tabella_prestito(const contenitore<opera>&);
    virtual void set_style();
    void closeEvent(QCloseEvent*);
    ~utenteWindow();
signals:
    void chiudi_app();
    void ricevilibro(unsigned int);
    void ricevirivista(unsigned int);

private slots:
    void show_ricevi_rivista(unsigned int);
    void show_ricevi_libro(unsigned int);
private:
    database* model;
    database_utente_opere* modelutenteopere;
    listaOp* tab;
    C_listaop* controllerOP;

    int libro_selezionato;
    int rivista_selezionata;


    QPushButton* ricevi_libro;
    QPushButton* ricevi_rivista;
    QPushButton* restituisci_libro;
    QPushButton* restituisci_rivista;
    QPushButton* exit;

    QHBoxLayout* orizzontale;
    QVBoxLayout* Prlayout, *bottoni;

    void creaLayout();
    void abilita_bottoni();
    void disabilita_bottoni();
};
#endif // UTENTEWINDOW_H
