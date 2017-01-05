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
#include "listaop.h"
#include "widget_padre.h"

#include "../CONTROLLER/c_listaop.h"
#include "../MODEL/database.h"
#include "../MODEL/database_utente.h"
#include "../CONTROLLER/c_listautenti.h"



class mainWindow : public Widget_Padre
{
    Q_OBJECT
public:
    explicit mainWindow(database*,database_utente*);
    virtual void aggiorna_vista();
    virtual void costruisci_contenuto();
    void costruisci_Tabella(const contenitore<opera>&);
    virtual void set_style();
    void closeEvent(QCloseEvent*);
    ~mainWindow();
signals:
    void chiudi_app();
    void rimuovi(int);
    void aggiorna_prestito(int);
    void show_inserisci_rivista();
    void show_inserisci_libro();
    void show_inserisci_utentebasic();
    void show_inserisci_utentepro();
    void cerca_opera(QString);

private slots:
    void rimuovi_segnale();
    void slot_aggiorna_prestito();
    void slot_inserisci_rivista();
    void slot_inserisci_libro();
    void slot_inserisci_utentebasic();
    void slot_inserisci_utentepro();
    void modifica_campo(int);
    void disabilita();
    void testo_editato(const QString&);
private:
    database* model;
    database_utente* modelutenti;
    listaOp* tab;
    listautenti* tabutenti;
    C_listaop* controllerOP;
    C_listautenti* controllerUTENTI;

    int opera_selezionata;
    int utente_selezionato;

    QLineEdit* barra_cerca;

    QPushButton* presta_rientra;
    QPushButton* aggiungi_rivista;
    QPushButton* aggiungi_libro;
    QPushButton* rimuovi_opera;
    QPushButton* aggiungi_utente_basic;
    QPushButton* aggiungi_utente_pro;
    QPushButton* exit;

    QHBoxLayout* orizzontale;
    QVBoxLayout* Prlayout, *bottoni;

    void creaLayout();
    void abilita_bottoni();
    void disabilita_bottoni();
};

#endif // MAINWINDOW_H
