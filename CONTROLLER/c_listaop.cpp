#include "c_listaop.h"

C_listaop::C_listaop(database* db, listaOp* v,QObject *parent) : model(db), view(v), QObject(parent) {
    connect(view,SIGNAL(richiesta_info(int)),this,SLOT(visualizza_info(int)));


}

void C_listaop::visualizza_info(int id){

}


