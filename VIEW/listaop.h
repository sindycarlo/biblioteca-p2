#ifndef LISTAOP_H
#define LISTAOP_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QAbstractItemView>
#include <QVBoxLayout>
#include <typeinfo>

#include "widget_padre.h"
#include"../MODEL/database.h"
#include"../MODEL/contenitore.h"

class listaOp : public Widget_Padre
{
    Q_OBJECT
public:
    explicit listaOp(database*,database_utente*,database_utente_opere*);

    //eredito i due metodi virtuali puri e non li implemento
    virtual void build_Nuova(const contenitore<opera>&) =0;
    int Getopera() const;
    QTableWidget* Getable() const;
    QVBoxLayout* Getlayout_table()const;
    void abilita_doppio_click();
    void disabilita_doppio_click();
    virtual ~listaOp();
signals:
   void richiesta_info(int);
   void disabilita_servizi();
   void tabella_vuota();
   void disabilita_funzioni();
   void abilita_funzioni();
   void selezione(const int);


private slots:
   void click_singolo(int);       //permette di far emettere il segnale selezione con l'id selezionato
   void doppio_click(int);

private:
    QTableWidget* table;
    QVBoxLayout* layout_table;
    int select_opera;
    void set_style();
};

#endif // LISTAOP_H

