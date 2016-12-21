#include <QApplication>
#include "MODEL/database.h"


//test di prova per la parte di progettazione:
#include <MODEL/opera.h>
#include <MODEL/libro.h>
#include <MODEL/rivista.h>
#include <MODEL/contenitore.h>
#include "MODEL/utente.h"
#include "MODEL/database_utente.h"


int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);



     rivista prova("ESPRESSO",2006,true);
     //libro prova1("NEMO","CARLO SINDICO",true);
     rivista prova2("NATIONAL GEOGRAPHIC",2005,true);
     libro prova3("IL PICCOLO PRINCIPE","DAVIDE POLONIO",true);
     info_opera p1=prova.info_tot();
     //info_opera p2=prova1.info_tot();
     info_opera p3=prova2.info_tot();
     info_opera p4=prova3.info_tot();

     database db;
     database*x=&db;

  /*  db.add_Rivista(p1);
    //db.add_Libro(p2);
    db.add_Rivista(p3);
   */   db.add_Libro(p4);
    db.add_Rivista(p1);
    db.add_Rivista(p1);
    db.add_Rivista(p1);
    db.add_Rivista(p1);

    //db.remove_opera(6);
    //db.remove_opera(7);
    std::cout<<"       ";
    //test prova stampa dal database:
    contenitore<opera>::iteratore it;
   /* for(it=db.db_begin();it!=db.db_end();it++)
    {
        std::cout<<"Titolo dell'opera: "<<(*(it))->GetTitolo().toStdString()<<"  "<<"Dettaglio: "<<(*(it))->Get_tipo().toStdString()<<std::endl;
    }
   // return a.exec();
*/
    utente_basic primoutente(0,"carlo","sindico","SNDCRLO1994002768","sonofigo",x);
    utente_basic secondoutente(0,"carlo","sindico","SNDCRLO1994002768","sonofigo",x);
    utente_basic terzoutente(0,"carlo","sindico","SNDCRLO1994002768","sonofigo",x);
    utente_basic quartoutente(0,"carlo","sindico","SNDCRLO1994002768","sonofigo",x);

    info_utente primo=primoutente.infoutente();
    info_utente secondo=secondoutente.infoutente();

    database_utente utenti;


    utenti.add_utentebasic(primo);
    utenti.add_utentebasic(secondo);

    primoutente.ricevi_opera(7);
     primoutente.ricevi_opera(8);

     for(it=primoutente.Getcontainer()->begin();it!=primoutente.Getcontainer()->end();it++)
     {
         std::cout<<"Titolo dell'opera: "<<(*(it))->GetTitolo().toStdString()<<"  "<<"Dettaglio: "<<(*(it))->Get_tipo().toStdString()<<std::endl;
     }
}
