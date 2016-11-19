//test prova ithub windows
#ifndef LIBRO_H
#define LIBRO_H
#include"opera.h"


#include<string>
#include<iostream>


class libro : public opera {
private:
    string autore;
public:
    libro(string, string, bool =1) {}
    string GetAutore() const {}
    virtual bool disponibile() const {}
    //virtual void Scrivi_opera(/*manca*/) const {}
    virtual string Get_tipo() const {}


};



#endif // LIBRO_H

