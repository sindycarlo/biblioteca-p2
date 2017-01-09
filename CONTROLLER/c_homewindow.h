#ifndef C_HOMEWINDOW_H
#define C_HOMEWINDOW_H

#include <QObject>
#include <QApplication>

#include "../VIEW/homewindow.h"
#include "../CONTROLLER/c_mainwindow.h"
class c_homewindow : public QObject
{
    Q_OBJECT
public:
    explicit c_homewindow(database*,database_utente*,homewindow* , QObject *parent=0);
    database* Getmodel() const;
    database_utente* Getmodelutenti() const;
private slots:
    void accedi_admin();
    void accedi_utente();

private:
    database* model;
    database_utente* modelutenti;
    homewindow* view;
};




#endif // C_HOMEWINDOW_H
