#include <QApplication>
#include "MODEL/database.h"


//test di prova per la parte di progettazione:
#include <MODEL/opera.h>
#include <MODEL/libro.h>
#include <MODEL/rivista.h>
#include <MODEL/contenitore.h>




int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);



     rivista prova("ESPRESSO",2006,true);
     libro prova1("NEMO","CARLO SINDICO",true);
     rivista prova2("NATIONAL GEOGRAPHIC",2005,false);
     //libro prova3("IL PICCOLO PRINCIPE","DAVIDE POLONIO",true);
     info_opera p1=prova.info_tot();
    info_opera p2=prova1.info_tot();
     info_opera p3=prova2.info_tot();
    // info_opera p4=prova3.info_tot();

     database db;


    db.add_Rivista(p1);
    db.add_Libro(p2);
    db.add_Rivista(p3);
   // db.add_Rivista(p4);
    db.add_Rivista(p1);


   /* contenitore diprova;
    diprova.add_item(x);
    diprova.add_item(k);
    diprova.add_item(y);
    diprova.add_item(z);

    contenitore::iteratore it;
    for(it=diprova.begin();it!=diprova.end();it++)
    {
        std::cout<<"Titolo dell'opera: "<<(*(it))->GetTitolo().toStdString()<<std::endl;}
   // return a.exec();
   */
}
