#include "opera.h"
#include<QString>

//inizializzo il massimo id di opera:
static int maxid=0;


//costruttore di opera (verrà utilizzato per costruire i sottoggetti di libro e rivista)
opera::opera(QString t,bool sp) : Titolo(t), statoPresenza(sp) {
    maxid++;
    id=maxid;
}

//distruttore di opera:
opera::~opera() {}



QString opera::GetTitolo() const {return Titolo;}

int opera::GetId() const {return id;}

int opera::GetMaxId() const {return maxid;}

void opera::Set_id(const int x) {id=x;}

void opera::Set_maxid(const int x) {maxid=x;}

void opera::Riscatta() {statoPresenza=1;}

virtual void  opera::Presta_opera() {statoPresenza=0;}

virtual bool opera::presente() const {

    if(statoPresenza==1) return true;
    else return false;
}










