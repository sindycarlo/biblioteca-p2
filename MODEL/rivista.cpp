#include"info_opera.h"
#include"rivista.h"
#include <QXmlStreamWriter>
#include<QString>
#include<iostream>

unsigned int rivista::MaxAnni=20;

rivista::rivista(QString t, unsigned int au, bool d) : opera(t,d), annouscita(au) {
    if(annouscita>1000)
    {std::cout<<"Errore: anno di uscita dela rivista troppo grande";}
    annouscita=1000;
}


