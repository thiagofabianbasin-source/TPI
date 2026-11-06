#include <iostream>
#include "comodin.h"
#include "mazopoker.h"
#include "puntuacionFila.h"
using namespace std;

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

// hay algún casillero vacío en una fila distinta de "fila"?
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

void comodinPedirCasillero(const char* texto, int &fila, int &col) {
    cout << texto << endl;
    do {
        cout << " Fila (1-3): ";
        cin >> fila;
    } while (fila < 1 || fila > 3);
    
    do {
        cout << " Casillero (1-5): ";
        cin >> col;
    } while (col < 1 || col > 5);
    
    fila--;
    col--;
}

void comodinIntercambiar(int cartas[3][5]) {
    int f1, c1, f2, c2;

    do {
        comodinPedirCasillero("Primera carta a intercambiar:", f1, c1);
        if (cartas[f1][c1] == 0) cout << "ese casillero esta vacio." << endl;
    } while (cartas[f1][c1] == 0);
    bool valida;
    do {
        comodinPedirCasillero("Segunda carta a intercambiar:", f2, c2);
        valida = true;
        if (cartas[f2][c2] == 0) {
            cout << "Ese casillero esta vacio." << endl;
            valida = false;
        } else if (f1 == f2 && c1 == c2) {
            cout << "Tenes que elegir una carta distinta." << endl;
            valida = false;
        }
    } while (!valida);

    int aux = cartas[f1][c1];
    cartas[f1][c1] = cartas[f2][c2];
    cartas[f2][c2] = aux;
}

void comodinMover(int cartas[3][5], int puntos[2], int jugador) {
    int f1, c1, f2, c2;
    bool valida;

    do {
        comodinPedirCasillero("Carta a mover:", f1, c1);
        valida = true;
        if (cartas[f1][c1] == 0) {
            cout << "Ese casillero esta vacio." << endl;
            valida = false;
        } else if (!comodinHayVacioEnOtraFila(cartas, f1)) {
            cout << "No hay lugar libre en otras filas para esa carta." << endl;
            valida = false;
        }
    } while (!valida);

    do {
        comodinPedirCasillero("Casillero destino (en otra fila):", f2, c2);
        valida = true;
        if (f2 == f1) {
            cout << "El destino tiene que estar en otra fila." << endl;
            valida = false;
        } else if (cartas[f2][c2] != 0) {
            cout << "Ese casillero esta ocupado." << endl;
            valida = false;
        }
    } while (!valida);

    cartas[f2][c2] = cartas[f1][c1];
    cartas[f1][c1] = 0;

    // Si se formó la quinta carta de la nueva fila, puntúa quien jugó el comodín
    if (comodinCartasEnFila(cartas, f2) == 5) {
        puntuacionFila(cartas, f2, puntos, jugador);
    }
}

void comodinRetirar(int cartas[3][5]) {
    int f, c;

    do {
        comodinPedirCasillero("Carta a retirar:", f, c);
        if (cartas[f][c] == 0) cout << "Ese casillero esta vacio." << endl;
    } while (cartas[f][c] == 0);

    cout << "Carta retirada: ";
    mostrarCarta(cartas[f][c] - 1);
    cout << endl;

    devolverCarta(cartas[f][c] - 1);
    cartas[f][c] = 0;
}


void jugarComodin(int cartas[3][5], int puntos[2], int jugador) {
    bool puedeIntercambiar = (comodinContarCartas(cartas) >= 2);
    bool puedeMov = comodinPuedeMover(cartas);
    int opcion;
    bool valida;

    cout << "COMODIN: que queres hacer?" << endl;
    cout << " 1) Intercambiar dos cartas del tablero" << endl;
    cout << " 2) Mover una carta a un casillero vacio de otra fila" << endl;
    cout << " 3) Retirar una carta del tablero" << endl;

    do {
        cout << "Opcion: ";
        cin >> opcion;
        valida = true;

        if (opcion < 1 || opcion > 3) {
            cout << "Opcion invalida." << endl;
            valida = false;
        } else if (opcion == 1 && !puedeIntercambiar) {
            cout << "Hacen falta al menos 2 cartas en el tablero." << endl;
            valida = false;
        } else if (opcion == 2 && !puedeMov) {
            cout << "No hay ninguna carta que se pueda mover a otra fila." << endl;
            valida = false;
        }
    } while (!valida);

    if (opcion == 1){
        comodinIntercambiar(cartas);
     }
    else if (opcion == 2){
        comodinMover(cartas, puntos, jugador);
    }
    else {comodinRetirar(cartas);}
}
