#ifndef INFO_OPERA_H
#define INFO_OPERA_H

#include <iostream>
#include <QString>


//Un oggetto di tipo info_opera mi restituisce tutte le informazioni di quell'opera d'invocazione
class info_opera
{
private:
    QString titolo;
    QString disponibile;
    QString ID;
    QString dettaglio;
    QString presente;
public:
    info_opera(QString ="Sconosciuto", QString ="Sconosciuto", QString ="Sconosciuto", QString ="Sconosciuto", QString ="Sconosciuto"); //costruttore 0~4 parametri.
    QString get_titolo() const;
    QString get_stato() const;
    QString get_ID() const;
    QString get_dettaglio() const;
    QString is_consultabile() const;
};

#endif // INFO_OPERA_H
