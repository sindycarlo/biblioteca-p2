#ifndef LIBRO_H
#define LIBRO_H
#include"opera.h"
#include "info_opera.h"
#include <QXmlStreamWriter>
#include<QString>
#include<iostream>


class libro : public opera {
private:
    QString autore;
public:
    libro(QString, QString, bool =1);
    QString Getautore()const;
    void SetAutore(QString);
    virtual void Write_opera(QXmlStreamWriter& XmlWriter) const;
    virtual QString Get_tipo() const;
    virtual info_opera info_tot() const;

};



#endif // LIBRO_H

