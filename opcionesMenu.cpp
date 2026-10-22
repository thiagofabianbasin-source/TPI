#include <iostream>
#include "rlutil.h"
#include "mostrarmenu.h"
#include "Reglasdeljuego.h"
#include "jugadores.h"
#include "mostrarestadisticas.h"
using namespace std;
int opcionesDelMenu() ;
int opcionesDelMenu() {
    srand(time(NULL));

    int opcion;

    do {
        mostrarMenu();

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch(opcion) {
        case 1:
             rlutil::cls();
            jugar();
            break;

        case 2:
            rlutil::cls();
            Estadisticas();
            break;

        case 3:
              rlutil::cls();
            reglasdelJuego();
            break;

        case 0:
             rlutil::cls();
            cout << "\nPrograma finalizado.\n";
            break;

        default:
            cout << "\nOpcion invalida.\n";
        }

     rlutil :: anykey();
     rlutil :: cls();



    } while(opcion != 0);
}
