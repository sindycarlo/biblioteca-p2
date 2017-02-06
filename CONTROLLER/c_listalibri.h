#ifndef C_LISTALIBRI_H
#define C_LISTALIBRI_H
#include <QObject>

#include "../MODEL/database.h"
#include "../VIEW/dettagli_libro.h"
#include "../VIEW/listalibri.h"

class mainWindow;

class C_listalibri : public QObject
{
    Q_OBJECT
public:
    explicit C_listalibri(database*,database_utente*,database_utente_opere*, listalibri*,mainWindow*, QObject *parent = 0);

public slots:
    void visualizza_info_libro(int);
    void modificaL(QString,QString,int);
    void chiudi_dettagli_libro();

private:
    database* model;
    database_utente* modelutenti;
    database_utente_opere* modelutenteopere;
    dettagli_Libro* dettagliolibro;
    listalibri* view;
    mainWindow* mainview;

};
#endif // C_LISTALIBRI_H

