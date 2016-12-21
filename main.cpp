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



     rivista prova("NATIONAL GEOGRAPHIC",2006,true);
     libro prova1("NEMO","CARLO SINDICO",true);
     info_opera t=prova.info_tot();
     info_opera p=prova1.info_tot();

     database biblioteca;

     biblioteca.add_Rivista(t);
     biblioteca.add_Libro(p);
     biblioteca.add_Libro(p);




   utente_basic primoutente(0,"carlo","sindico","SNDCRLO1994002768","sonofigo",biblioteca.getcontainer());
    utente_pro secondoutente(0,"GIUSEPPE","MUSOTTO","GSP1996700267","sonobello",biblioteca.getcontainer());
     utente_basic terzoutente(1,"SILVIO","MENEGUZZO","GSP1996700267","fenoch",biblioteca.getcontainer());

    info_utente primo=primoutente.infoutente();
    info_utente secondo=secondoutente.infoutente();
     info_utente terzo=terzoutente.infoutente();

    database_utente utenti;


    utenti.add_utentebasic(primo);
       utenti.add_utentebasic(secondo);
    utenti.add_utentebasic(terzo);

    primoutente.ricevi_opera(3);
    primoutente.ricevi_opera(4);
    contenitore<opera>::iteratore it;
    std::cout<<"OPERE CHE: "<<primoutente.GetNome().toStdString()<<"  HA CHIESTO IN PRESTITO E HA RICEVUTO"<<std::endl;
    for(it=primoutente.Getcontainer()->begin();it!=primoutente.Getcontainer()->end();it++)
    {
        std::cout<<"Titolo dell'opera: "<<(*(it))->GetTitolo().toStdString()<<"  "<<"Dettaglio: "<<(*(it))->Get_tipo().toStdString()<<std::endl;
    }


    primoutente.restituisci_opera(3);

    std::cout<<"OPERE CHE:  "<<primoutente.GetNome().toStdString()<<"  HA RESTITUITO ALLA BIBLIOTECA"<<std::endl;
    for(it=primoutente.Getcontainer()->begin();it!=primoutente.Getcontainer()->end();it++)
    {
        std::cout<<"Titolo dell'opera: "<<(*(it))->GetTitolo().toStdString()<<"  "<<"Dettaglio: "<<(*(it))->Get_tipo().toStdString()<<std::endl;
    }


}
