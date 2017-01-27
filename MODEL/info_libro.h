#ifndef INFO_LIBRO_H
#define INFO_LIBRO_H
#include "info_opera.h"
class info_libro : public info_opera
{

public:
    info_libro(QString, QString, QString, QString, QString); //costruttore 0~4 parametri.
    virtual QString get_dettaglio() const;
};



#endif // INFO_LIBRO_H
