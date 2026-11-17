
#include "rlutil.h"
#include <iostream>
#include <string>
using namespace std;

#include "turnos.h"
#include "tablero.h"
#include "mazoPoker.h"
#include "guardarGanadores.h"
#include "marco.h"

void turno(int &jugador) {
    jugador = 1 - jugador;
}

void turnos(string nombres[2], int jugador, string ganadores[],
            int puntajes[], int &cantidadGanadores) {

    bool usadas[54];
    mazoPoker(usadas);

    int puntos[2] = {0, 0};
    int cartas[3][5] = {0};

  while (puntos[0] < 50 && puntos[1] < 50 &&
           cartasRestantes(usadas) >= 2) {

        rlutil::locate(63, 19);
        cout << "Turno de " << nombres[jugador] << endl;

        tablero(nombres, jugador, cartas, puntos, usadas);

        if (puntos[0] < 50 && puntos[1] < 50 &&
            cartasRestantes(usadas) >= 2) {

            turno(jugador);
        }

    }
    rlutil::cls();

    marco();
    rlutil::locate(57,9);
    cout << "FIN DE LA PARTIDA" << endl;
    rlutil::locate(55,14);
    cout << nombres[0] << ": " << puntos[0] << " puntos" << endl;
    rlutil::locate(55,15);
    cout << nombres[1] << ": " << puntos[1] << " puntos" << endl;

    if (puntos[0] >= 63) {
        rlutil::locate(59,18);
        cout << "Gano " << nombres[0] << "!" << endl;
    }
    else if (puntos[1] >= 50) {
        rlutil::locate(59,18);
        cout << "Gano " << nombres[1] << "!" << endl;
    }


    registrarResultado(nombres, puntos, ganadores,
                       puntajes, cantidadGanadores);
     rlutil::anykey();
     rlutil::cls();
}
