#ifndef RIVISTA_H
#define RIVISTA_H
#include"opera.h"
#include"info_opera.h"
#include<string>
#include<QXmlStreamWriter>
#include<iostream>


class rivista : public opera {
private:
    unsigned int annouscita;

public:
    rivista(string, unsigned int, bool =1) {}
    unsigned int GetAnno() const {}
    virtual bool disponibile() const {}
    virtual void Write_opera(QXmlStreamWriter&) const {}
    virtual string Get_tipo() const {}

};

#endif // RIVISTA_H

