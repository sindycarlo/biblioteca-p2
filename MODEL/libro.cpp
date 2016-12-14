#include"info_opera.h"
#include"libro.h"
#include <QXmlStreamWriter>
#include<QString>
#include<iostream>



libro::libro(QString t ="Sconosciuto", QString a ="sconosciuto", bool d) : opera(t,d), autore(a) {}


QString libro::Getautore() const {return autore;}


bool libro::ricerca_campi(const QString & x) const {
   if(opera::ricerca_campi(x)) return true;
   else if((QString::compare(x,autore,Qt::CaseInsensitive))) return true;
   else return false;
}

 QString libro::Get_tipo() const {
    return "libro";
}

 info_opera libro::info_tot() const {
QString disp="disponibile", id, pres="si";
if(!disponibile()) disp="non disponibile";
if(!presente()) pres="non presente";
id.setNum(GetId());
return  info_opera(GetTitolo(),disp,id,Getautore(),pres);
}


 void libro::Write_opera(QXmlStreamWriter &XmlWriter) const {
    XmlWriter.writeStartElement("opera");
    //da capire!!
}

