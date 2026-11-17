#include <iostream>
#include "rlutil.h"
 using namespace std;
 // color en las opciones del menu
void showItem(const char* text, int posx, int posy, bool selected) {

    if (selected) {
        rlutil::setBackgroundColor(rlutil::BLUE);
    }
    else {
        rlutil::setBackgroundColor(rlutil::BLACK);
    }

    rlutil::locate(posx, posy);
    cout << text;
}

