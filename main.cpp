#include <QApplication>
#include "MODEL/database.h"

#include <CONTROLLER/c_mainwindow.h>
#include <CONTROLLER/c_homewindow.h>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    database db;
    database_utente dbutenti(&db);

    amministratore ab("admin","admin",&db,&dbutenti);
    homewindow finestra(&db,&dbutenti,&ab);
    c_homewindow home(&db,&dbutenti,&finestra,&ab);

    finestra.show();

    return a.exec();
}
