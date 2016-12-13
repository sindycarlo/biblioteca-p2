#ifndef LIBRO_H
#define LIBRO_H
#include"opera.h"
#include"info_opera.h"

#include <QXmlStreamWriter>
#include<QString>
#include<iostream>


class libro : public opera {
private:
    string autore;
public:
    libro(string, string, bool =1) {}
    string GetAutore() const;
    virtual void Write_opera(QXmlStreamWriter& XmlWriter) const;
    virtual string Get_tipo() const;
    virtual bool ricerca_campi(const string &) const;
    virtual info_opera info_tot() const;
};



#endif // LIBRO_H

