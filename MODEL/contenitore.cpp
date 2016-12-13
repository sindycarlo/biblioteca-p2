#include"contenitore.h"

//costruttore di contenitore
contenitore::contenitore() : first(0) {}

//costruttore di copia di contenitore
contenitore::contenitore(const contenitore & x) : first(x.first) {}

//operatore di assegnazione
contenitore& contenitore::operator =(const contenitore& x) {
    if(this==&x) return *this;
    first=x.first;
    return *this;
}


//controllo se il contenitore è vuoto
bool contenitore::empty() const {
    if(first==0)return true;
    else return false;
}

//aggiunge opera nel contenitore
void contenitore::add_item(opera *o) {
    first=new nodo(o,first);
}

//rimuove un opera dalla lista
void contenitore::remove_item(opera* o)
{
    smartp p=first, prec, q;
    smartp original=first;
    first=0;
    while(p!=0 && !(p->op==o))
    {
        q=new nodo(p->op,p->next);
        if(prec==0) first=q;
        else prec->next=q;
        prec=q;
        p=p->next;
    }
    if(p==0) first=original;
    else if(prec==0) first=p->next;
         else prec->next=p->next;
}

//metodi di contenitore che usano iteratori

contenitore::iteratore contenitore::begin() const
{
    iteratore prov;
    prov.punt=first;
    return prov;
}

contenitore::iteratore contenitore::end() const{
    iteratore prov;
    prov.punt=0;
    return prov;
}


//operatore di dereferenziazione per ottenere opera
opera* contenitore::operator[](const contenitore::iteratore& i) const{
    return i.punt->op;
}




contenitore::nodo::nodo(opera* o, const smartp& n): op(o), next(n), riferimenti(0){}


contenitore::smartp::smartp(nodo* n): punt(n)
{
    if(punt) punt->riferimenti++;
}

contenitore::smartp::~smartp()
{
    if(punt)
    {
        (punt->riferimenti)--;
        if((punt->riferimenti)==0) delete punt;
    }
}

contenitore::smartp::smartp(const smartp& sp): punt(sp.punt) { if(punt) punt->riferimenti++; }

contenitore::smartp& contenitore::smartp::operator=(const smartp& sp)
{
    if(this == &sp) return *this;
    nodo* t=punt;
    punt=sp.punt;
    if(punt) (punt->riferimenti)++;
    if(t)
    {
        (t->riferimenti)--;
        if((t->riferimenti)==0) delete t;
    }
    return *this;
}

bool contenitore::smartp::operator==(const smartp& sm)const {
    return (punt==sm.punt);
}

bool contenitore::smartp::operator!=(const smartp& sm)const { return (sm.punt!=punt); }

contenitore::nodo* contenitore::smartp::operator->()const { return punt; }

contenitore::nodo& contenitore::smartp::operator*()const { return *punt; }

//**************************** ITERATORE ****************************//

bool contenitore::iteratore::operator==(const iteratore& i) const{
    return i.punt==punt;
}

bool contenitore::iteratore::operator!=(const iteratore& i) const{
    return i.punt!=punt;
}

contenitore::iteratore&  contenitore::iteratore::operator++(){          //operatore prefisso
    if(punt!=0) punt=punt->next;
    return *this;

}

contenitore::iteratore&  contenitore::iteratore::operator++(int){        //operatore postfisso
    iteratore prov= *this;
    if(punt!=0) punt=punt->next;
    return prov;
}

opera* contenitore::iteratore::operator*()const{ return punt->op; }


