#ifndef C_UTENTEWINDOW_H
#define C_UTENTEWINDOW_H

#include <QObject>
#include <QApplication>

#include "../VIEW/utentewindow.h"
#include "../VIEW/mainwindow.h"

class c_utentewindow : public QObject
{
    Q_OBJECT
public:
    explicit c_utentewindow(unsigned int,database* ,database_utente*,database_utente_opere*, utenteWindow* , QObject *parent=0);
    unsigned int Getidutente() const;
private slots:
void ricevilibroDB(unsigned int);
void ricevirivistaDB(unsigned int);
void restituiscilibroDB(unsigned int);
void restituiscirivistaDB(unsigned int);
void chiudi_utentewindow();


private:
    unsigned int idutente;
    database* model;
    database_utente* modelutenti;
    database_utente_opere* modelutenteopere;
    utenteWindow* view;
};




#endif // C_UTENTEWINDOW_H
