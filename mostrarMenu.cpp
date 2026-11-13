
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
#include "Reglasdeljuego.h"
#include "jugadores.h"
#include "mostrarestadisticas.h"
#include "guardarGanadores.h"
#include "marco.h"
#include "menuReglas.h"
#include "colorSeleccion.h"
using namespace std;


// menu principal
int mostrarMenu() {

    int y = 0;
    bool menuActivo = true;

    string ganadores[MAX_PARTIDAS];
    int puntajes[MAX_PARTIDAS];
    int cantidadGanadores = 0;

    rlutil::hidecursor();

    while (menuActivo) {

       // rlutil::cls();

        // Marco
        marco();

        // Separadores
        for (int x = 31; x < 100; x++) {
            rlutil::locate(x, 12);
            cout << (char)196;
        }

        // titulo
        rlutil::locate(57, 10);
        cout << "CRISIS DE LOS 40";

        // Opciones del menu
        showItem("Jugar", 57, 14, y == 0);
        showItem("Estadisticas", 57, 15, y == 1);
        showItem("Reglas del juego", 57, 16, y == 2);
        showItem("Salir", 57, 17, y == 3);

        // Flecha de seleccion
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::locate(55, 14 + y);
        cout << (char)175;

        int key = rlutil::getkey();

        switch (key) {

        case 14: // down
            rlutil::locate(55, 14 + y);
            cout << " ";
            y--;

            if (y < 0) {
                y = 0;
            }

            break;

        case 15: // up
            rlutil::locate(55, 14 + y);
            cout << " ";

            y++;

            if (y > 3) {
                y = 3;
            }

            break;

        case 1: // ENTER

            switch (y) {

            case 0: // JUGAR

                rlutil::cls();
                jugar(ganadores, puntajes, cantidadGanadores);

                break;

            case 1: // ESTADISTICAS

                rlutil::cls();
                Estadisticas(ganadores, puntajes, cantidadGanadores);

                break;

            case 2: // REGLAS DEL JUEGO

                rlutil::cls();
                menuReglas();

                break;

            case 3: // SALIR

                rlutil::cls();
                menuActivo = false;

                break;

            }

            break;

        default:
            break;
        }
    }

    return 0;
}
