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
    rivista* x=new rivista("ESPRESSO",2004,true);
    rivista* y=new rivista("AIRONE",2004,true);
    rivista* z=new rivista("NATIONAL GEOGRAPHIC",2004,true);
    rivista* k=new rivista("FOCUS",2004,true);

     rivista prova("ESPRESSO",2004,true);
     info_opera prova2=prova.info_tot();
     database db;


    db.add_Rivista(prova2);


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
