#include "MODEL/database.h"

//faccio l'include del file xml:
QString database::filename="../biblioteca-p2/database.xml";



contenitore::iteratore database::db_begin() {return db.begin();}

contenitore::iteratore database::db_end() {return db.end();}



//creare un database significa caricare il file database.xml:
database::database() {database::Load();}


//"distruggere" un database significa fare la chiusura del file database.xml:
database::~database() {database::Close();}


//rimuovere un opera dal database significa:
/*1) cercare l'opera nel database con quel id;
 * 2) rimuoverla dal mio contenitore di opere;
 * 3) aggiornare il database;
 * */

void remove_opera(const int id) {

}


bool database::vuoto() const {return db.empty();}





//aggiunge un libro al mio contenitore quindi al database:
void database::add_Libro(const info_opera& c) {
libro*p=new libro(c.get_titolo(),c.get_dettaglio(),1);
db.add_item(p);
}

//aggiunge una rivista al mio contenitore quindi al database:
void database::add_Rivista(const info_opera & c1) {
    unsigned int x=c1.get_dettaglio().toInt();
    rivista*p=new rivista(c1.get_titolo(),x,1);
    db.add_item(p);
}




