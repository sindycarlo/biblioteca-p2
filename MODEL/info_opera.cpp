#include"info_opera.h"
#include <QXmlStreamWriter>
#include<QString>
#include<iostream>



info_opera::info_opera(QString t ="Sconosciuto", QString d ="Sconosciuto", QString  id ="Sconosciuto", QString det ="Sconosciuto", QString pr ="Sconosciuto") : titolo(t), disponibile(d), ID(id), dettaglio(det), presente(pr) {}

QString info_opera::get_titolo() const  {return titolo;}
QString info_opera::get_stato() const {return disponibile;}
QString info_opera::get_ID() const {return ID;}
QString info_opera::get_dettaglio() const {return dettaglio;}
QString info_opera::is_consultabile() const {return presente;}
