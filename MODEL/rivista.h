#ifndef RIVISTA_H
#define RIVISTA_H
#include"opera.h"


#include<string>
#include<iostream>


class rivista : public opera {
private:
    unsigned int annouscita;

public:
    rivista(string, unsigned int, bool =1) {}
    unsigned int GetAnno() const {}
    virtual bool disponibile() const {}
    //virtual void Scrivi_opera(/*manca*/) const {}
    virtual string Get_tipo() const {}

};

#endif // RIVISTA_H

