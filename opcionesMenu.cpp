#include "rlutil.h"
#include <iostream>
using namespace std;
#include "mostrarmenu.h"
#include "Reglasdeljuego.h"
#include "jugadores.h"
#include "mostrarestadisticas.h"
#include <string>
#include "guardarGanadores.h"
int opcionesDelMenu() ;
int opcionesDelMenu() {
    srand(time(NULL));

    int opcion;
     string ganadores[MAX_PARTIDAS];
    int puntajes[MAX_PARTIDAS];
    int cantidadGanadores = 0;

    do {
        mostrarMenu();

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch(opcion) {
        case 1:
             rlutil::cls();
            jugar(ganadores, puntajes, cantidadGanadores);
            break;

        case 2:
            rlutil::cls();
            Estadisticas(ganadores, puntajes, cantidadGanadores);
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
    return 0;
}
