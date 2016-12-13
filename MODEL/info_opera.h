#ifndef INFO_OPERA_H
#define INFO_OPERA_H

#include <iostream>
#include <QString>


class info_opera
{
private:
    QString titolo;
    QString stato;
    QString ID;
    QString dettaglio;
    QString consultabile;
public:
    info(QString ="Sconosciuto", QString ="Sconosciuto", QString ="Sconosciuto", QString ="Sconosciuto", QString ="Sconosciuto"); //costruttore 0~4 parametri.
    QString get_titolo() const;
    QString get_stato() const;
    QString get_ID() const;
    QString get_dettaglio() const;
    QString is_consultabile() const;
};

#endif // INFO_OPERA_H
