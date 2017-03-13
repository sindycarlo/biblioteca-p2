#include <QApplication>
#include "MODEL/database.h"

#include <CONTROLLER/c_mainwindow.h>
#include <CONTROLLER/c_homewindow.h>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    database db;
    database_utente_opere udb;
    database_utente dbutenti(&db,&udb);

    amministratore ab("admin","admin",&db,&dbutenti);
    homewindow finestra(&db,&dbutenti,&udb,&ab);
    c_homewindow home(&db,&dbutenti,&udb,&finestra,&ab);

    finestra.show();

    return a.exec();
}
