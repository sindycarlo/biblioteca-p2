#ifndef WIDGET_PADRE_H
#define WIDGET_PADRE_H

#include <QWidget>
#include <QDesktopWidget>



class database;

class Widget_Padre : public QWidget
{
    Q_OBJECT
public:
    explicit Widget_Padre(database*, QWidget *parent = 0);
    virtual ~Widget_Padre();

    database* get_model() const;                //ritorna un puntatore al database
    virtual void set_style();                   //imposta lo stile nelle view
    virtual void aggiorna_vista() =0;           //aggionrnamento del contenuto di ogni vista
    virtual void costruisci_contenuto() =0;     //costruisce il contenuto delle view

private:
    void centra_finestra();                     //permette di centrare la finestra al momento della sua creazione
    database* model;
};

#endif // WIDGET_PADRE_H
