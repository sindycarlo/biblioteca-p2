#ifndef C_LISTAUTENTI_H
#define C_LISTAUTENTI_H

#include <QObject>

#include "../MODEL/database_utente.h"
#include "../VIEW/listautenti.h"


class C_listautenti : public QObject
{
    Q_OBJECT
public:
    explicit C_listautenti(database_utente*, listautenti*, QObject *parent = 0);

public slots:
    void visualizza_info_utenti(int);

private:
    database_utente* model;
    listautenti* view;

};


#endif // C_LISTAUTENTI_H
