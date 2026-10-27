#include <iostream>
#include <string>
#include "turnos.h"
#include "tablero.h"
#include "mazoPoker.h"
#include "rlutil.h"

using namespace std;

void turno(int &jugador) {
    jugador = 1 - jugador;
}

void turnos(string nombres[2], int jugador) {

    mazoPoker();

    int puntos[2] = {0, 0};
    int cartas[3][5] = {0};

    while (puntos[0] < 50 &&puntos[1] < 50 && cartasRestantes() >= 2) {

        cout << endl;
        cout << "Turno de " << nombres[jugador] << endl;

        tablero(nombres, jugador, cartas, puntos);

        if (puntos[0] < 50 && puntos[1] < 50 &&cartasRestantes() >= 2) {
            turno(jugador);

        }

    }

    cout << endl;
    cout << "========== FIN DE LA PARTIDA ==========" << endl;
    cout << nombres[0] << ": " << puntos[0] << " puntos" << endl;
    cout << nombres[1] << ": " << puntos[1] << " puntos" << endl;

    if (puntos[0] >= 50 && puntos[1] >= 50) {
        cout << "Ambos jugadores llegaron a 50 puntos." << endl;
    } else if (puntos[0] >= 50) {
        cout << "Gano " << nombres[0] << "!" << endl;
    } else if (puntos[1] >= 50) {
        cout << "Gano " << nombres[1] << "!" << endl;
    } else {
        cout << "Se terminaron las cartas del mazo." << endl;
    }
}
