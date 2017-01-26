#ifndef INSERISCI_UTENTEPRO_H
#define INSERISCI_UTENTEPRO_H
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QGridLayout>
#include <QDesktopWidget>

#include "../MODEL/database_utente.h"

class inserisci_utentepro : public QWidget
{
    Q_OBJECT
public:
    explicit inserisci_utentepro(QWidget *parent = 0);
    void closeEvent();
    ~inserisci_utentepro();

signals:
    void submitup(const info_utente&);
    void chiudi_aggiungi_utentepro();

public slots:
    void slot_submit();

private:

    QPushButton* submit;

    QLabel* n;              //nome
    QLabel* co;              //cognome
    QLabel* cf;      //codicefiscale
    QLabel* psw;           //password
    QLabel* Numriv;           //numero di riviste

    QLineEdit* nome;
    QLineEdit* cognome;
    QLineEdit* codicefiscale;
    QLineEdit* password;
    QLineEdit* Numeroriviste;


    QVBoxLayout* layout;
    QGridLayout* grid;

    void build_Layout();
    void pulisci_Campi();
    void centra_finestra();

};

#endif // INSERISCI_UTENTEPRO_H
