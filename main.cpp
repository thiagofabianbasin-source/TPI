#include <iostream>
#include "rlutil.h"
#include "mostrarmenu.h"
#include "Reglasdeljuego.h"
#include "jugadores.h"
#include "mostrarestadisticas.h"
#include "opcionesMenu.h"
#include "mazoPoker.h"
#include "mostrarEspaciorestante.h"
#include "tablero.h"
#include "marco.h"
using namespace std;
int main() {

    rlutil::hidecursor();
    // marco
   marco();

    // separadores
    for (int x=31; x<100; x++) {
        rlutil::locate(x,13);
        cout << (char)196;
    }

    // texto de titulo
    rlutil::locate(57,10);
   cout <<"CRISIS DE LOS 40";


    // texto de inicar (inicia con cualquier tecla)
    while (!kbhit()){
    rlutil::locate(51,18);
    rlutil::setColor(rlutil::YELLOW);
   cout <<"PRESIONE ENTER PARA COMENZAR";

   rlutil::msleep(300); //tiempo que aparece

   //ocultar
   rlutil::locate(51,18);
   cout << "                                      "; //un espacio sin nada para remplazar x el texto
   rlutil::msleep(300); //tiempo para que aparece el espacio
    }

     rlutil::anykey();
     rlutil::setColor(rlutil::WHITE);
     rlutil::cls();

     mostrarMenu();



    return 0;
}
