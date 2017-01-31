#ifndef INSERISCI_UTENTEBASIC_H
#define INSERISCI_UTENTEBASIC_H


#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QGridLayout>
#include <QDesktopWidget>

#include "../MODEL/database_utente.h"

class inserisci_utentebasic : public QWidget
{
    Q_OBJECT
public:
    explicit inserisci_utentebasic(QWidget *parent = 0);
    void closeEvent(QCloseEvent*);
    ~inserisci_utentebasic();

signals:
    void submitub(const info_utente&);
    void chiudi_aggiungi_utentebasic();

public slots:
    void slot_submit();

private:

    QPushButton* submit;

    QLabel* n;              //nome
    QLabel* co;              //cognome
    QLabel* cf;      //codicefiscale
    QLabel* psw;           //password
    QLabel* Numop;           //numero opere in prestito

    QLineEdit* nome;
    QLineEdit* cognome;
    QLineEdit* codicefiscale;
    QLineEdit* password;
    QLineEdit* Numeropere;


    QVBoxLayout* layout;
    QGridLayout* grid;

    void build_Layout();
    void pulisci_Campi();
    void centra_finestra();

};


#endif // INSERISCI_UTENTEBASIC_H
