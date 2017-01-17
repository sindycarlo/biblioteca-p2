#ifndef INSERISCI_LIBRO_H
#define INSERISCI_LIBRO_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QGridLayout>
#include <QDesktopWidget>

#include "../MODEL/database.h"

class inserisci_Libro : public QWidget
{
    Q_OBJECT
public:
    explicit inserisci_Libro(QWidget *parent = 0);
    void closeEvent(QCloseEvent*);
    ~inserisci_Libro();

signals:
    void submitL(const info_opera&);
    void chiudi_aggiungi_Libro();

public slots:
    void slot_submit();

private:

    QPushButton* submit;

    QLabel* t;              //titolo
    QLabel* a;              //autore

    QLineEdit* titolo;
    QLineEdit* autore;

    QVBoxLayout* layout;
    QGridLayout* grid;

    void build_Layout();
    void pulisci_Campi();
    void centra_finestra();

};

#endif // INSERISCI_LIBRO_H
