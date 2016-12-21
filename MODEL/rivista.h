#ifndef RIVISTA_H
#define RIVISTA_H
#include"opera.h"
#include"info_opera.h"
#include <QXmlStreamWriter>
#include<QString>
#include<iostream>


class rivista : public opera {
private:
    unsigned int annouscita;
    static unsigned int MaxAnni;

public:
    rivista(QString, unsigned int, bool);
    unsigned int GetAnnouscita() const;
    unsigned int getMaxAnni() const;
    virtual bool disponibile() const;
    virtual void Write_opera(QXmlStreamWriter& xmlWriter) const;
    virtual QString Get_tipo() const;
    virtual bool ricerca_campi(const QString&) const;
    virtual info_opera info_tot()const;
    virtual void Presta_opera();
};

#endif // RIVISTA_H

