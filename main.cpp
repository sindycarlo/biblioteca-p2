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
    rivista* x=new rivista("alice nel paese delle cacche",2004,true);
    rivista* y=new rivista("alice nel paese delle cacche",2004,true);
    rivista* z=new rivista("alice nel paese delle cacche",2004,true);

    contenitore diprova;
    diprova.add_item(x);
    diprova.add_item(x);
    diprova.add_item(y);
    diprova.add_item(z);


   // return a.exec();
}
