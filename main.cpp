#include <QApplication>
#include "MODEL/database.h"



/*#include "MODEL/database.h"
#include <CONTROLLER/c_mainwindow.h>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    database db;
    database_utente dbutenti(&db);
    mainWindow finestra(&db,&dbutenti);
    C_mainWindow controller(&db,&dbutenti,&finestra);

    finestra.show();

    return a.exec();
}

*/







//test di prova per la parte di progettazione:
#include "MODEL/database.h"
#include "MODEL/database_utente.h"
#include "MODEL/database_utente_opere.h"

int main(int argc, char *argv[])
{



     rivista prova("NATIONAL GEOGRAPHIC",2006,true);
     libro prova1("NEMO","CARLO SINDICO",true);

     info_opera t=prova.info_tot();
     info_opera p=prova1.info_tot();

     database biblioteca;

     //aggiungo opere al mio database della biblioteca:
     biblioteca.add_Rivista(t);
     biblioteca.add_Libro(p);


      database_utente_opere db3;

     utente_basic primo(&biblioteca,&db3,0,"carlo","sindico","sndcrl1994rtsd34","prova1");


     info_utente p1=primo.infoutente();


     //aggiungo utenti al database degli utenti:
     database_utente utenti(&biblioteca,&db3);


     utenti.add_utentebasic(p1);
     utenti.add_utentebasic(p1);
     utenti.add_utentebasic(p1);

     primo.ricevi_libro(4);
     primo.ricevi_rivista(3);



    return 0;
}

