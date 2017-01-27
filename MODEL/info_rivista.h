#ifndef INFO_RIVISTA_H
#define INFO_RIVISTA_H
#include "info_opera.h"
class info_rivista : public info_opera
{

public:
    info_rivsta(QString, QString, QString, QString, QString); //costruttore 0~4 parametri.
    virtual QString get_dettaglio() const;
};

#endif // INFO_RIVISTA_H
