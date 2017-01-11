#ifndef C_LISTARIVISTE_H
#define C_LISTARIVISTE_H
#include <QObject>

#include "../MODEL/database.h"
#include "../VIEW/listariviste.h"


class C_listariviste : public QObject
{
    Q_OBJECT
public:
    explicit C_listariviste(database*, listariviste*, QObject *parent = 0);

public slots:
    void visualizza_info_riviste(int);

private:
    database* model;
    listariviste* view;

};

#endif // C_LISTARIVISTE_H
