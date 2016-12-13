#ifndef INFO_OPERA_H
#define INFO_OPERA_H

#include <iostream>
#include <String>


class info_opera
{
private:
    String titolo;
    String stato;
    String ID;
    String dettaglio;
    String consultabile;
public:
    info(String ="Sconosciuto", String ="Sconosciuto", String ="Sconosciuto", String ="Sconosciuto", String ="Sconosciuto"); //costruttore 0~4 parametri.
    String get_titolo() const;
    String get_stato() const;
    String get_ID() const;
    String get_dettaglio() const;
    String is_consultabile() const;
};

#endif // INFO_OPERA_H
