#include <iostream>
#include "rlutil.h"
#include "jugadores.h"
#include "tablero.h"
#include "mazoPoker.h"
#include "puntuacionFila.h"
using namespace std;
//CALCULA LA PUNTUACION DE CADA FILA
void puntuacionFila(int cartas[3][5], int fila,int puntos[2], int jugador) {

    int suma = 0;

    for (int columna = 0; columna < 5; columna++) {
        int pos = cartas[fila][columna] - 1;
        suma += valorCarta(pos);
    }

    int rival = 1 - jugador;

    cout << endl;
    cout << "Se completo la fila " << fila + 1 << "." << endl;
    cout << "Suma de la fila: " << suma << endl;

    if (suma < 30) {
        cout << "Nadie suma puntos." << endl;
    }
    else if (suma == 30) {
        puntos[jugador] += 30;

        puntos[rival] -= 15;
        if (puntos[rival] < 0) {
            puntos[rival] = 0;
        }

        cout << "El jugador que completo la fila suma 30 puntos."
             << endl;
        cout << "El rival pierde 15 puntos, como minimo queda en 0."
             << endl;
    }
    else if (suma < 40) {
        puntos[jugador] += suma;
        cout << "El jugador que completo la fila suma "
             << suma << " puntos." << endl;
    }
    else {
        puntos[rival] += suma;
        cout << "CRISIS DE LOS 40: el rival suma "
             << suma << " puntos." << endl;
    }

    // Devolver las cinco cartas al mazo y vaciar la fila.
    for (int columna = 0; columna < 5; columna++) {
        devolverCarta(cartas[fila][columna] - 1);
        cartas[fila][columna] = 0;
    }
}
