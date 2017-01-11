#include "c_listariviste.h"

C_listariviste::C_listariviste(database* db, listariviste* v,QObject *parent) : model(db), view(v), QObject(parent) {
    //connect(view,SIGNAL(richiesta_info_rivista(int)),this,SLOT(visualizza_info_riviste(int)));

}

void C_listariviste::visualizza_info_riviste(int id){




}
