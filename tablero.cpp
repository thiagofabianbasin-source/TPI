#include "rlutil.h"
#include <iostream>
using namespace std;
#include "jugadores.h"
#include "tablero.h"
#include "mazoPoker.h"
#include "puntuacionFila.h"
#include "turnos.h"
#include "comodin.h"
#include "tableroGrafico.h"

// devuelve la primera columna libre (0 a 4) de una fila, o -1 si esta llena
int primerCasilleroLibre(int cartas[3][5], int fila) {
    for (int c = 0; c < 5; c++) {
        if (cartas[fila][c] == 0) {
            return c;
        }
    }
    return -1;
}

// partida
void tablero(string nombres[2], int jugador, int cartas[3][5], int puntos[2], bool usadas[54]){

    int carta1 = robarUna(usadas);
    int carta2 = robarUna(usadas);

    // dibuja toda la pantalla; devuelve la columna donde empieza el tablero
    int x0 = dibujarTablero(nombres, jugador, cartas, puntos,
                            cartasRestantes(usadas), carta1, carta2);

    int eleccion = pedirOpcion(x0, 24, "Carta a jugar (1 o 2): ", 1, 2);

    int elegida;
    int sobrante;

    if (eleccion == 1) {
        elegida = carta1;
        sobrante = carta2;
    } else {
        elegida = carta2;
        sobrante = carta1;
    }

    // funcionalidad del comodin
    if (valorCarta(elegida) == 0) {

        if (tableroVacio(cartas)) {
            mostrarMensaje(x0, 28, "El comodin no se puede jugar con el tablero vacio.");

            if (valorCarta(sobrante) == 0) {
                // las dos son comodines: no se puede jugar nada
                mostrarMensaje(x0, 29, "Ambas cartas son comodines. Se pierde el turno.");
                devolverCarta(usadas, carta1);
                devolverCarta(usadas, carta2);
                rlutil::anykey();
                return;
            }

            // se juega la otra carta
            int aux = elegida;
            elegida = sobrante;
            sobrante = aux;

        } else {
            prepararZonaInferior(x0);
            jugarComodin(cartas, puntos, jugador, usadas);

            // el comodin y la carta no elegida vuelven al mazo
            devolverCarta(usadas, elegida);
            devolverCarta(usadas, sobrante);
            return;
        }
    }

    bool esDiamante = (paloCarta(elegida) == 'D');

    int fila = pedirOpcion(x0, 25, "Fila (1-3): ", 1, 3);
    int columna;

    if (esDiamante) {
        // el diamante puede reemplazar: el jugador elige el casillero exacto
        columna = pedirOpcion(x0, 26, "Casillero (1-5): ", 1, 5);
    } else {
        // las demas cartas van al primer casillero libre de la fila.
        // Siempre hay uno: una fila completa se vacia al puntuar,
        // asi que nunca queda con 5 cartas al terminar un turno.
        columna = primerCasilleroLibre(cartas, fila - 1) + 1;
    }

    int filaActual = fila - 1;
    int columnaActual = columna - 1;

    bool casilleroVacio = (cartas[filaActual][columnaActual] == 0);

    if (!casilleroVacio) {
        // el diamante reemplaza: la carta anterior vuelve al mazo
        devolverCarta(usadas, cartas[filaActual][columnaActual] - 1);
    }

    cartas[filaActual][columnaActual] = elegida + 1;

    // solo se puede completar una fila agregando una carta (casillero vacio)
    if (casilleroVacio) {
        int cantidad = 0;

        for (int c = 0; c < 5; c++) {
            if (cartas[filaActual][c] != 0) {
                cantidad++;
            }
        }

        if (cantidad == 5) {
            // se muestra la fila completa y debajo el resultado
            dibujarFila(filaActual, x0, cartas);
            prepararZonaInferior(x0);

            puntuacionFila(cartas, filaActual, puntos, jugador, usadas);

            rlutil::locate(x0, 24);
            cout << "Presione una tecla para seguir...";
            rlutil::anykey();
        }
    }

    // la carta no elegida vuelve al mazo
    devolverCarta(usadas, sobrante);
}

    // la carta no elegida vuelve al mazo
    devolverCarta(usadas, sobrante);
}
