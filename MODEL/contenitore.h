// contenitore base che gestisce la memoria con gli smartp

#ifndef CONTENITORE_H
#define CONTENITORE_H

#include<iostream>

template <class T>
class contenitore{
    friend class iteratore;
private:
    class nodo;

    class smartp{
    public:
        smartp(nodo* n =0): punt(n)       //costruttore 0~1 parametro + convertitore implicito nodo*->smartp
        {
            if(punt) punt->riferimenti++;
        }
            ~smartp(){
            if(punt)                //distruttore

            {
                (punt->riferimenti)--;
                if((punt->riferimenti)==0) delete punt;
            }
            }
            smartp(const smartp& sp): punt(sp.punt) { if(punt) punt->riferimenti++; }      //costruttore di copia

            smartp& operator=(const smartp& sp)            //operatore di assegnazione
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
            bool operator==(const smartp& sm)const         //operatore di uguaglianza
            {
                return (punt==sm.punt);
            }
            bool operator!=(const smartp& sm)const
             {return (sm.punt!=punt);}            //operatore di disuguaglianza
            nodo* operator->()const { return punt; }//operatore di accesso a membro
            nodo& operator*()const { return *punt; }

            nodo* punt;
        };

    class nodo{
    public:
        nodo(T* o, const smartp& n): op(o), next(n), riferimenti(0){}
        T* op;
        smartp next;
        int riferimenti;
    };
    //campo dati
    smartp first;

public:
    class iteratore{
        friend class contenitore;
    private:
        contenitore::smartp punt;
    public:
        bool operator==(const iteratore& i) const{
            return i.punt==punt;
        }       //operatore di uguaglianza
        bool operator!=(const iteratore& i) const{
            return i.punt!=punt;
        }       //operatore di disuguaglianza
        iteratore& operator++(){
            if(punt!=0) punt=punt->next;
            return *this;

        }      //operatore di incremento prefisso
        iteratore& operator++(int){
            iteratore prov=*this;
            if(punt!=0) punt=punt->next;
            return prov;
        }     //operatore di incremento postfisso

        T* operator*()const { return punt->op; }          //operatore di accesso a membro

    };

    contenitore(): first(0) {}                                        //costruttore contenitore vuoto

    contenitore& operator =(const contenitore& x) {
        if(this==&x) return *this;
        first=x.first;
        return *this;
    }
                 //assegnazione con smartp

    contenitore(const contenitore & x) : first(x.first) {}        //costruzione di copia

    //metodi pubblici contenitore
    bool empty() const {
        if(first==0)return true;        // 1 <=> contenitore vuoto
        else return false;
    }

    void add_item(T *o) {                       //aggiunta opera in coda alla lista
        first=new nodo(o,first);
    }


    void remove_item(T* o)
    {
        smartp p=first, prec, q;
        smartp original=first;
        first=0;
        while(p!=0 && !(p->op==o))
        {
            q=new nodo(p->op,p->next);          //rimuovi una opera dalla lista
            if(prec==0) first=q;
            else prec->next=q;
            prec=q;
            p=p->next;
        }
        if(p==0) first=original;
        else if(prec==0) first=p->next;
             else prec->next=p->next;
    }


    iteratore begin() const
    {
        iteratore prov;
        prov.punt=first;
        return prov;
    }
    iteratore end() const{
        iteratore prov;
        prov.punt=0;
        return prov;
    }

    T* operator[](const iteratore& i) const{
        return i.punt->op;
    }

};
#endif


