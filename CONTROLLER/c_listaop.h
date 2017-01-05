#ifndef C_LISTAOP_H
#define C_LISTAOP_H

#include <QObject>

#include "../MODEL/database.h"
#include "../VIEW/listaop.h"


class C_listaop : public QObject
{
    Q_OBJECT
public:
    explicit C_listaop(database*, listaOp*, QObject *parent = 0);

public slots:
    void visualizza_info(int);

private:
    database* model;
    listaOp* view;

};

#endif // C_LISTAOP_H
