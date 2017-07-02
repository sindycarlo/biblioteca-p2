 #ifndef DETTAGLI_OPERA_H
#define DETTAGLI_OPERA_H


#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>
#include <QGridLayout>
#include <QDateTime>
#include <QApplication>

#include"../MODEL/database.h"
#include "widget_padre.h"


class dettagli_opera : public Widget_Padre{
    Q_OBJECT

public:
    void closeEvent(QCloseEvent*);
    virtual ~dettagli_opera();

signals:
    void modifica(QString,QString,int);
    void chiudi_dettagli_opera();

public slots:
    void esci();

protected:
    explicit dettagli_opera(int, database*,database_utente*);

    virtual void set_style();
    virtual void costruisci_contenuto();
    void disabilita_modifica();
    void abilita_modifica();


private:

    int id;
    QLabel* t;                  //titolo
    QLabel* p;                  //prestito
    QLabel* i;                  //id
    QLabel* c;                  //disponibilità

    QPushButton* submit;
    QPushButton* exit;
    QLineEdit* titolo;
    QLineEdit* prestito;
    QLineEdit* identificativo;
    QLineEdit* consultabile;

    QPalette* paletteLine;
    QGridLayout* grid;
    QVBoxLayout*layout;


public:
    QLineEdit* Gettitolo() const;
    virtual void aggiorna_vista();
    int get_ID()const;
    QPalette* get_paletteLine()const;
    QGridLayout* get_grid()const;
    QPushButton* get_submit() const;

};



#endif // DETTAGLI_OPERA_H
