#include"libro.h"
#include<iostream>
#include<string>


//costruttore di libro
libro::libro(string ti,string aut,bool p=1) :opera(ti,p), autore(aut) {}

bool libro::GetAutore() const {return autore;}


//restituisce il tipo di opera
string libro::Get_tipo() const {return "libro";}


