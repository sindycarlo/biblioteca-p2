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


class homewindow : public Widget_Padre
{
    Q_OBJECT
public:
    explicit homewindow(database*,database_utente*,database_utente_opere*);
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
    void show_accediutente(QString,QString);

private slots:

    void slot_accedi();
    void slot_accediutente();

private:



    QPushButton* accedicomeadmin;
    QPushButton* accedicomeutente;
    QPushButton* exit;

    QLabel* au;
    QLabel* ap;

    QLineEdit* adminuser;
    QLineEdit* adminpassword;

    QLabel*nu;
    QLabel*np;

    QLineEdit* nameuser;
    QLineEdit* password;


    QGridLayout* gridadmin;
    QGridLayout* gridutente;
    QVBoxLayout* layout;


    void creaLayout();

};


#endif // HOMEWINDOW_H
