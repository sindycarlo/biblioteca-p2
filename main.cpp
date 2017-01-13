#include <QApplication>
#include "MODEL/database.h"



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

    homewindow finestra2(&db,&dbutenti,&udb);
    c_homewindow home(&db,&dbutenti,&udb,&finestra2);

    finestra2.show();

    return a.exec();
}
