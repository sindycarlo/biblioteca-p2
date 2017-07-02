#ifndef INSERISCI_UTENTEPRO_H
#define INSERISCI_UTENTEPRO_H
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QComboBox>
#include <QMessageBox>
#include <QGridLayout>
#include <QDesktopWidget>

#include "../MODEL/database_utente.h"

class inserisci_utente : public QWidget
{
    Q_OBJECT
public:
    explicit inserisci_utente(QWidget *parent = 0);
    void closeEvent(QCloseEvent*);
    ~inserisci_utente();

signals:
    void submitu(const info_utente&);
    void chiudi_aggiungi_utente();

public slots:
    void slot_submit();
    void chiudi();

private:

    QPushButton* submit;
    QPushButton* exit;

    QLabel* n;              //nome
    QLabel* co;              //cognome
    QLabel* cf;      //codicefiscale
    QLabel* psw;           //password
    QLabel* tipoutente;

    QLineEdit* nome;
    QLineEdit* cognome;
    QLineEdit* codicefiscale;
    QLineEdit* password;


    QComboBox* tipu;


    QVBoxLayout* layout;
    QGridLayout* grid;

    void build_Layout();
    void pulisci_Campi();

};

#endif // INSERISCI_UTENTEPRO_H
