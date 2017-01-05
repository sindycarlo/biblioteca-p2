#ifndef C_ADD_LIBRO_H
#define C_ADD_LIBRO_H

#include <QObject>
#include<QApplication>
#include "../VIEW/inserisci_libro.h"
#include "../VIEW/mainwindow.h"
#include "../MODEL/database.h"

class c_add_libro : public QObject
{
    Q_OBJECT
public:
    explicit c_add_libro(database* , inserisci_Libro* ,mainWindow* , QObject *parent = 0);

public slots:
    void add(const info_opera&);
    void chiudi_add_libro();

private:
    database* model;
    inserisci_Libro* view;
    mainWindow* mainW;
};


#endif // C_ADD_LIBRO_H
