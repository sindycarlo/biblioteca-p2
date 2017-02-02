#include "opera.h"
#include<QString>

//inizializzo il massimo id di opera:
int opera::maxid=0;


//costruttore di opera (verrà utilizzato per costruire i sottoggetti di libro e rivista)
opera::opera(QString t ="sconosciuto",bool sp =1) : Titolo(t), statoPresenza(sp) {
    maxid++;
    id=maxid;
    appartenenza=-1;
}

//distruttore di opera:
opera::~opera() {}



QString opera::GetTitolo() const {return Titolo;}

unsigned int opera::GetId() const {return id;}

int opera::GetMaxId() const {return maxid;}

void opera::Set_id(const int x) {id=x;}

void opera::Set_maxid(const int x) {maxid=x;}

void opera::Riscatta() {statoPresenza=1;}

unsigned int opera::Getappartenenza() const {return appartenenza;}

void opera::Setappartenenza(const int x) {appartenenza=x;}
void  opera::Presta_opera() {statoPresenza=0;}

void opera::SetTitolo(QString t) {Titolo=t;}

bool opera::presente() const {

    if(statoPresenza==1) return true;
    else return false;
}

bool opera::disponibile() const {
    if(presente()) return true;
    else return true;
}

