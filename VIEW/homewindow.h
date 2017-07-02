#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include<QDesktopWidget>
#include <QApplication>
#include "widget_padre.h"

#include "../MODEL/database_utente.h"
#include "../MODEL/amministratore.h"


class homewindow : public Widget_Padre
{
    Q_OBJECT
public:
    explicit homewindow(database*,database_utente*,amministratore*);
    virtual void aggiorna_vista();
    virtual void costruisci_contenuto();
    virtual void set_style();
    void closeEvent(QCloseEvent*);
    void disabilita_pulsanti_home();
    void abilita_pulsanti_home();
    ~homewindow();
signals:
    void chiudi_app();
    void show_accedi();
    void show_accedi_utente(int);

private slots:

    void slot_accedi();
    void slot_accedi_utente();

private:



    QPushButton* accedicomeadmin;
    QPushButton* accedicomeutente;
    QPushButton* exit;
    amministratore* admin;

    QLabel*us;
    QLabel*passw;

    QLineEdit* username;
    QLineEdit* password;


    QGridLayout* gridlogin;
    QVBoxLayout* layout;


    void creaLayout();

};


#endif // HOMEWINDOW_H
