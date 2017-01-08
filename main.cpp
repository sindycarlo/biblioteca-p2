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
     biblioteca.add_Libro(p);
     biblioteca.add_Rivista(t);
     biblioteca.add_Libro(p);
     biblioteca.add_Libro(p);
     biblioteca.add_Rivista(t);
     biblioteca.add_Libro(p);
     biblioteca.add_Libro(p);



     utente_basic primo(&biblioteca,0,"carlo","sindico","sndcrl1994rtsd34","prova1");
     utente_pro primo2(&biblioteca,0,"luca","dalmaso","ldalmas35461997rty","prova2");
     utente_basic primo3(&biblioteca,0,"giulio","castagnara","sndcrl1994rtsd34","prova3");
     utente_pro primo4(&biblioteca,0,"mattia","dipauli","sndcrl1994rtsd34","prova4");
     utente_basic primo5(&biblioteca,0,"rana","daros","sndcrl1994rtsd34","prova5");

     info_utente p1=primo.infoutente();
     info_utente p2=primo2.infoutente();
     info_utente p3=primo3.infoutente();
     info_utente p4=primo4.infoutente();
     info_utente p5=primo5.infoutente();

     //aggiungo utenti al database degli utenti:
     database_utente utenti(&biblioteca);


     utenti.add_utentebasic(p1);
     utenti.add_utentepro(p2);
     utenti.add_utentebasic(p3);
     utenti.add_utentepro(p4);
     utenti.add_utentebasic(p5);

    database_utente_opere db3(&utenti);
    //primo5.ricevi_libro(11);


    return 0;
}

