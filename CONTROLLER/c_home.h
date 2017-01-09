#ifndef C_HOME_H
#define C_HOME_H

#include "VIEW/homewindow.h"

class C_home : public QObject
{
    Q_OBJECT
public:
    explicit C_home(homewindow*, QObject *parent=0);

private slots:
    void accedicomeamministratore();
    void accedicomeutente();

private:

    homewindow* viewhome;
};


#endif // C_HOME_H
