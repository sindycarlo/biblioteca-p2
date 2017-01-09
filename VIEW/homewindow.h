#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include<QDesktopWidget>
#include <QApplication>
#include "widget_padre.h"


class homewindow : public Widget_Padre
{
    Q_OBJECT
public:
    explicit homewindow(database*,database_utente*);
    virtual void aggiorna_vista();
    virtual void costruisci_contenuto();
    virtual void set_style();
    void closeEvent(QCloseEvent*);
    ~homewindow();
signals:
    void chiudi_app();
    void show_accedi();

private slots:

    void slot_accedi();

private:


    QPushButton* accedicomeadmin;
    QPushButton* exit;


    QHBoxLayout* orizzontale;
    QVBoxLayout* Prlayout, *bottoni;

    void creaLayout();

};


#endif // HOMEWINDOW_H
