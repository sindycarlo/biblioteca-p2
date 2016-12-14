#include"info_opera.h"
#include"rivista.h"
#include <QXmlStreamWriter>
#include<QString>
#include<iostream>

unsigned int rivista::MaxAnni=20;

rivista::rivista(QString t ="Sconosciuto", unsigned int au = 1700, bool d =1) : opera(t,d), annouscita(au) {
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

bool rivista::ricerca_campi(const QString & text) const {
if(opera::ricerca_campi(text))return true;
else{
  int anniu=text.toInt();
  if(anniu==annouscita) return true;
  }
return false;
}

info_opera rivista::info_tot() const {
QString disp="disponibile", id, anno="1700", pres="si";
if(!disponibile()) disp="non disponibile";
if(!presente()) pres="non presente";
id.setNum(GetId());
anno.setNum(GetAnnouscita());
return  info_opera(GetTitolo(),disp,id,anno,pres);
}


void rivista::Write_opera(QXmlStreamWriter &XmlWriter) const {
   XmlWriter.writeStartElement("opera");
   //da capire!!
}

QString rivista::Get_tipo() const {return "rivista";}
