#ifndef INSERISCI_RIVISTA_H
#define INSERISCI_RIVISTA_H

#include <QWidget>
 #include <QPushButton>
#include <QLabel>
#include <QDate>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QGridLayout>
#include <QDesktopWidget>

#include "../MODEL/database.h"

class inserisci_Rivista : public QWidget
{
    Q_OBJECT
public:
    explicit inserisci_Rivista(QWidget *parent = 0);
    void closeEvent(QCloseEvent*);
    ~inserisci_Rivista();

signals:
    void submitR(const info_opera&);
    void chiudi_aggiungi_rivista();

public slots:
    void slot_submit();
private:

    QPushButton* submit;

    QLabel* t;     //titolo
    QLabel* a;     //anno

    QLineEdit* titolo;
    QLineEdit* anno;

    QVBoxLayout* layout;
    QGridLayout* grid;

    void build_Layout();
    void pulisci_Campi();
    void centra_finestra();
};

#endif // INSERISCI_RIVISTA_H
