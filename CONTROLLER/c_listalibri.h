#ifndef C_LISTALIBRI_H
#define C_LISTALIBRI_H
#include <QObject>

#include "../MODEL/database.h"
#include "../VIEW/listalibri.h"


class C_listalibri : public QObject
{
    Q_OBJECT
public:
    explicit C_listalibri(database*, listalibri*, QObject *parent = 0);

public slots:
    void visualizza_info_libri(int);

private:
    database* model;
    listalibri* view;

};

#endif // C_LISTALIBRI_H
