#include "c_listalibri.h"

C_listalibri::C_listalibri(database* db, listalibri* v,QObject *parent) : model(db), view(v), QObject(parent) {
    //connect(view,SIGNAL(richiesta_info(int)),this,SLOT(visualizza_info_libri(int)));

}

void C_listalibri::visualizza_info_libri(int id){




}
