#ifndef C_MAINWINDOW_H
#define C_MAINWINDOW_H

#include <QObject>
#include <QApplication>

#include "../VIEW/mainwindow.h"
#include "../CONTROLLER/c_add_rivista.h"
#include "../CONTROLLER/c_add_libro.h"

class C_mainWindow : public QObject
{
    Q_OBJECT
public:
    explicit C_mainWindow(database* , mainWindow* , QObject *parent=0);

private slots:
    void rimuovi_operaDB(int);
    void aggiorna_prestitoDB(int);
    void inserisci_rivistaDB();
    void inserisci_libroDB();
    void inserisci_utentebasicDB();
    void inserisci_utenteproDB();
    void cerca_operaDB(const QString&);

private:
    database* model;
    mainWindow* view;
};

#endif // C_MAINWINDOW_H
