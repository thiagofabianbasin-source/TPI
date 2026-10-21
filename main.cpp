#include <iostream>
#include "rlutil.h"
#include "mostrarmenu.h"
#include "Reglasdeljuego.h"
#include "jugadores.h"
#include "mostrarestadisticas.h"
#include "opcionesMenu.h"
using namespace std;
int main() {

    cout << "========================================\n";
    cout << "        CRISIS DE LOS 40\n";
    cout << "========================================\n";
    cout << "\n";
    cout << "        Presione ENTER\n";
    cout << "\n";
    cout << "========================================\n";

    ;

     rlutil :: anykey();
     rlutil :: cls();

    opcionesDelMenu();


    return 0;
}

    } while(opcion != 0);

    return 0;
}
