#include "rlutil.h"
#include <iostream>
using namespace std;
#include "comodin.h"
#include "mazoPoker.h"
#include "puntuacionFila.h"
#include "tableroGrafico.h"

int comodinCartasEnFila(int cartas[3][5], int fila) {
    int n = 0;
    for (int c = 0; c < 5; c++) {
        if (cartas[fila][c] != 0) n++;
    }
    return n;
}

int comodinContarCartas(int cartas[3][5]) {
    int n = 0;
    for (int f = 0; f < 3; f++) n += comodinCartasEnFila(cartas, f);
    return n;
}

bool tableroVacio(int cartas[3][5]) {
    return comodinContarCartas(cartas) == 0;
}

// hay algun casillero vacio en una fila distinta de "fila"?
bool comodinHayVacioEnOtraFila(int cartas[3][5], int fila) {
    for (int f = 0; f < 3; f++) {
        if (f == fila) continue;
        if (comodinCartasEnFila(cartas, f) < 5) return true;
    }
    return false;
}

bool comodinPuedeMover(int cartas[3][5]) {
    for (int f = 0; f < 3; f++) {
        for (int c = 0; c < 5; c++) {
            if (cartas[f][c] != 0 && comodinHayVacioEnOtraFila(cartas, f)) return true;
        }
    }
    return false;
}

// escribe el titulo en la fila y de la pantalla y pide fila y casillero
// debajo (y + 1 e y + 2). Devuelve la fila y la columna desde 0.
void comodinPedirCasillero(const char* texto, int &fila, int &col, int y) {
    int x0 = calcularX0();

    rlutil::locate(x0, y);
    cout << texto;
    fila = pedirOpcion(x0, y + 1, " Fila (1-3): ", 1, 3) - 1;
    col = pedirOpcion(x0, y + 2, " Casillero (1-5): ", 1, 5) - 1;
}

void comodinIntercambiar(int cartas[3][5]) {
    int x0 = calcularX0();
    int f1, c1, f2, c2;

    do {
        comodinPedirCasillero("Primera carta a intercambiar:", f1, c1, 19);
        if (cartas[f1][c1] == 0) {
            mostrarMensaje(x0, 28, "Ese casillero esta vacio.");
        }
    } while (cartas[f1][c1] == 0);

    bool valida;
    do {
        comodinPedirCasillero("Segunda carta a intercambiar:", f2, c2, 23);
        valida = true;
        if (cartas[f2][c2] == 0) {
            mostrarMensaje(x0, 28, "Ese casillero esta vacio.");
            valida = false;
        } else if (f1 == f2 && c1 == c2) {
            mostrarMensaje(x0, 28, "Tenes que elegir una carta distinta.");
            valida = false;
        }
    } while (!valida);

    int aux = cartas[f1][c1];
    cartas[f1][c1] = cartas[f2][c2];
    cartas[f2][c2] = aux;
}

void comodinMover(int cartas[3][5], int puntos[2], int jugador, bool usadas[54]) {
    int x0 = calcularX0();
    int f1, c1, f2, c2;
    bool valida;

    do {
        comodinPedirCasillero("Carta a mover:", f1, c1, 19);
        valida = true;
        if (cartas[f1][c1] == 0) {
            mostrarMensaje(x0, 28, "Ese casillero esta vacio.");
            valida = false;
        } else if (!comodinHayVacioEnOtraFila(cartas, f1)) {
            mostrarMensaje(x0, 28, "No hay lugar libre en otras filas para esa carta.");
            valida = false;
        }
    } while (!valida);

    do {
        comodinPedirCasillero("Casillero destino (en otra fila):", f2, c2, 23);
        valida = true;
        if (f2 == f1) {
            mostrarMensaje(x0, 28, "El destino tiene que estar en otra fila.");
            valida = false;
        } else if (cartas[f2][c2] != 0) {
            mostrarMensaje(x0, 28, "Ese casillero esta ocupado.");
            valida = false;
        }
    } while (!valida);

    cartas[f2][c2] = cartas[f1][c1];
    cartas[f1][c1] = 0;

    // Si se formo la quinta carta de la nueva fila, puntua quien jugo el comodin
    if (comodinCartasEnFila(cartas, f2) == 5) {
        dibujarFila(f2, x0, cartas);     // se ve la fila completa
        prepararZonaInferior(x0);

        puntuacionFila(cartas, f2, puntos, jugador, usadas);

        rlutil::locate(x0, 24);
        cout << "Presione una tecla para seguir...";
        rlutil::anykey();
    }
}

void comodinRetirar(int cartas[3][5], bool usadas[54]) {
    int x0 = calcularX0();
    int f, c;

    do {
        comodinPedirCasillero("Carta a retirar:", f, c, 19);
        if (cartas[f][c] == 0) {
            mostrarMensaje(x0, 28, "Ese casillero esta vacio.");
        }
    } while (cartas[f][c] == 0);

    rlutil::locate(x0, 23);
    cout << "Carta retirada: ";
    mostrarCarta(cartas[f][c] - 1);

    devolverCarta(usadas, cartas[f][c] - 1);
    cartas[f][c] = 0;

    rlutil::locate(x0, 25);
    cout << "Presione una tecla para seguir...";
    rlutil::anykey();
}


void jugarComodin(int cartas[3][5], int puntos[2], int jugador, bool usadas[54]) {
    int x0 = calcularX0();
    bool puedeIntercambiar = (comodinContarCartas(cartas) >= 2);
    bool puedeMov = comodinPuedeMover(cartas);
    int opcion;
    bool valida;

    rlutil::locate(x0, 19);
    cout << "COMODIN: que queres hacer?";
    rlutil::locate(x0, 20);
    cout << " 1) Intercambiar dos cartas del tablero";
    rlutil::locate(x0, 21);
    cout << " 2) Mover una carta a un casillero vacio de otra fila";
    rlutil::locate(x0, 22);
    cout << " 3) Retirar una carta del tablero";

    do {
        opcion = pedirOpcion(x0, 24, "Opcion (1-3): ", 1, 3);
        valida = true;

        if (opcion == 1 && !puedeIntercambiar) {
            mostrarMensaje(x0, 28, "Hacen falta al menos 2 cartas en el tablero.");
            valida = false;
        } else if (opcion == 2 && !puedeMov) {
            mostrarMensaje(x0, 28, "No hay ninguna carta que se pueda mover a otra fila.");
            valida = false;
        }
    } while (!valida);

    prepararZonaInferior(x0);   // se borra el menu para los pasos que siguen

    if (opcion == 1){
        comodinIntercambiar(cartas);
    }
    else if (opcion == 2){
        comodinMover(cartas, puntos, jugador, usadas);
    }
    else {
        comodinRetirar(cartas, usadas);
    }
}
