#include "rlutil.h"
#include <iostream>
using namespace std;
#include "jugadores.h"
#include "tablero.h"
#include "mazoPoker.h"
#include "puntuacionFila.h"
#include "tableroGrafico.h"
//CALCULA LA PUNTUACION DE CADA FILA
void puntuacionFila(int cartas[3][5], int fila,int puntos[2], int jugador, bool usadas [54]) {

    int suma = 0;

    for (int columna = 0; columna < 5; columna++) {
        int pos = cartas[fila][columna] - 1;
        suma += valorCarta(pos);
    }

    int rival = 1 - jugador;
    int x0 = calcularX0();   // los mensajes van alineados con el tablero

    rlutil::locate(x0, 19);
    cout << "Se completo la fila " << fila + 1 << ".";
    rlutil::locate(x0, 20);
    cout << "Suma de la fila: " << suma;

    if (suma < 30) {
        rlutil::locate(x0, 21);
        cout << "Nadie suma puntos.";
    }
    else if (suma == 30) {
        puntos[jugador] += 30;

        puntos[rival] -= 15;
        if (puntos[rival] < 0) {
                puntos[rival] = 0;
        }

        rlutil::locate(x0, 21);
        cout << "El jugador que completo la fila suma 30 puntos.";
        rlutil::locate(x0, 22);
        cout << "El rival pierde 15 puntos, como minimo queda en 0.";
    }
    else if (suma < 40) {
        puntos[jugador] += suma;
        rlutil::locate(x0, 21);
        cout << "El jugador que completo la fila suma "
             << suma << " puntos.";
    }
    else {
        puntos[rival] += suma;
        rlutil::locate(x0, 21);
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "CRISIS DE LOS 40: el rival suma "
             << suma << " puntos.";
        rlutil::setColor(rlutil::WHITE);
    }

    // Devolver las cinco cartas al mazo y vaciar la fila.
    for (int columna = 0; columna < 5; columna++) {
        devolverCarta(usadas, cartas[fila][columna] - 1);
        cartas[fila][columna] = 0;
    }
}

