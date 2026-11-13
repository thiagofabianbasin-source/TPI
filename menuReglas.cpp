
#include <iostream>
using namespace std;

#include "rlutil.h"
#include "Reglasdeljuego.h"
#include "marco.h"
#include "colorSeleccion.h"


// Menu de reglas
int menuReglas() {

    rlutil::hidecursor();

    int y = 0;
    bool menuActivo = true;

    while (menuActivo) {

        //rlutil::cls();

        // Marco
        marco2();

        // Separadores
        for (int x = 31; x < 100; x++) {
            rlutil::locate(x, 11);
            cout << (char)196;
        }

        // Titulo
        rlutil::locate(57, 10);
        cout << "REGLAS DEL JUEGO";

        // Opciones del menu con color en la seleccion
        showItem("General", 53, 14, y == 0);
        showItem("Valor de las cartas", 53, 15, y == 1);
        showItem("Desarrollo de los turnos", 53, 16, y == 2);
        showItem("Jugadas segun las cartas", 53, 17, y == 3);
        showItem("Completar fila", 53, 18, y == 4);
        showItem("Condiciones de victoria y derrota", 53, 19, y == 5);
        showItem("Situaciones especiales", 53, 20, y == 6);
        showItem("Estrategia", 53, 21, y == 7);
        showItem("Menu principal", 53, 22, y == 8);
        showItem("Volver", 53, 23, y == 9);

        // Flecha de seleccion
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::locate(51, 14 + y);
        cout << (char)175;

        int key = rlutil::getkey();

        switch (key) {

        case 14: // FLECHA ARRIBA

            rlutil::locate(51, 14 + y);
            cout << " ";

            y--;

            if (y < 0) {
                y = 0;
            }

            break;

        case 15: // FLECHA ABAJO

            rlutil::locate(51, 14 + y);
            cout << " ";

            y++;

            if (y > 9) {
                y = 9;
            }

            break;

        case 1: // ENTER

            switch (y) {

            case 0:
                rlutil::cls();
                general();
                break;

            case 1:
                rlutil::cls();
                valorDeLasCartas();
                break;

            case 2:
                rlutil::cls();
                desarrolloDeUnTurno();
                break;

            case 3:
                rlutil::cls();
                jugadasSegunLaCarta();
                break;

            case 4:
                rlutil::cls();
                completasUnaFila();
                break;

            case 5:
                rlutil::cls();
                condicionesDeVictoriaYDerrota();
                break;

            case 6:
                rlutil::cls();
                situacionesEspeciales();
                break;

            case 7:
                rlutil::cls();
                estrategia();
                break;

            case 8:
                rlutil::cls();
                menuPrincipal();
                break;

            case 9:
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
