#include "widget_padre.h"

Widget_Padre::Widget_Padre(database* db,QWidget *parent) :model(db), QWidget(parent){}


Widget_Padre::~Widget_Padre(){}

database* Widget_Padre::get_model()const { return model; }

void Widget_Padre::centra_finestra(){
       int width = frameGeometry().width();
       int height = frameGeometry().height();

       QDesktopWidget wid;

       int screenWidth = wid.screen()->width();
       int screenHeight = wid.screen()->height();

       int x=static_cast<int>((screenWidth-width)/2);
       int y=static_cast<int>((screenHeight-height)/2);

       move(x,y);
}

void Widget_Padre::set_style(){ centra_finestra(); }


