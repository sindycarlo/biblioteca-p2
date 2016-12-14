#include"info_opera.h"
#include"rivista.h"
#include <QXmlStreamWriter>
#include<QString>
#include<iostream>

unsigned int rivista::MaxAnni=20;

rivista::rivista(QString t, unsigned int au, bool d) : opera(t,d), annouscita(au) {
    if(annouscita<1700)
    {std::cout<<"Errore: anno di uscita dela rivista troppo grande";}
    annouscita=1700;
}

unsigned int rivista::GetAnnouscita() const {return annouscita;}

unsigned int rivista::getMaxAnni() const {return MaxAnni;}


bool rivista::disponibile() const {
    if(presente())
    {
        if(annouscita<=MaxAnni)
        {return true;}
    }
    return false;
}

void rivista::Presta_opera() {
if(disponibile())
{opera::Presta_opera();}
else{/*solleva eccezione*/}
}

QString rivista::Get_tipo() const {return "rivista";}
