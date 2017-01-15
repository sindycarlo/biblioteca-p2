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

    //essendo un libro il tipo è "1";
    XmlWriter.writeTextElement("Tipo","1");
    //scrivo il titolo del libro:
    XmlWriter.writeTextElement("Titolo",GetTitolo());
    //scrivo ID del libro:
    int id=GetId();
    QString x;
    x.setNum(id);
    XmlWriter.writeTextElement("Id",x);
    int appartiene=Getappartenenza();
    QString a;
    a.setNum(appartiene);
    XmlWriter.writeTextElement("Appartenenza",a);
    //scrivo stato presenza libro nella biblioteca:
    bool b=presente();
    QString y;
    y.setNum(b);
    XmlWriter.writeTextElement("Stato",y);
    //scrivo il dettaglio di libro che è l'autore:
    XmlWriter.writeTextElement("Autore",Getautore());
    XmlWriter.writeEndElement();
}


