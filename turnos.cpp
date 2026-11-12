#include "rlutil.h"
#include <iostream>
using namespace std;
#include <string>
#include "turnos.h"
#include "tablero.h"
#include "mazoPoker.h"
#include "guardarGanadores.h"


void turno(int &jugador) {
    jugador = 1 - jugador;
}

void turnos(string nombres[2], int jugador, string ganadores[], int puntajes[], int &cantidadGanadores) {
    bool usadas[54];
    mazoPoker(usadas);

    int puntos[2] = {0, 0};
    int cartas[3][5] = {0};

    while (puntos[0] < 50 &&puntos[1] < 50 && cartasRestantes(usadas) >= 2) {

        cout << endl;
        cout << "Turno de " << nombres[jugador] << endl;

        tablero(nombres, jugador, cartas, puntos, usadas);

        if (puntos[0] < 50 && puntos[1] < 50 &&cartasRestantes(usadas) >= 2) {
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
    }
    registrarResultado(nombres, puntos, ganadores, puntajes, cantidadGanadores);
}

