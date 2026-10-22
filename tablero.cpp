#include <iostream>
#include "jugadores.h"
#include "tablero.h"
#include "mazoPoker.h"
 using namespace std;
 //  muestra las cartas
void mostrarTablero(int cartas[3][5]) {

    cout << endl;
    cout << "          1      2      3      4      5"
         << "       Cartas   Suma" << endl;

    for (int fila = 0; fila < 3; fila++) {

        int cantidad = 0;
        int suma = 0;

        cout << "Fila " << fila + 1 << ": ";

        for (int columna = 0; columna < 5; columna++) {

            if (cartas[fila][columna] == 0) {
                cout << "[   ] ";
            } else {
                int pos = cartas[fila][columna] - 1;

                mostrarCarta(pos);
                cout << " ";

                cantidad++;
                suma += valorCarta(pos);
            }
        }

        cout << "   " << cantidad << "/5";
        cout << "      " << suma << endl;
    }
}
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
// partida
float tablero(string nombres[2]) {

    mazoPoker();

    int puntos[2] = {0, 0};
    int cartas[3][5] = {0};

    cout << "==================== CRISIS DE LOS 40 ====================" << endl;
    cout << "Objetivo: 50 puntos || Cartas en el mazo: "
         << cartasRestantes() << endl;
    cout << endl;

    cout << "  " << nombres[0] << ": " << puntos[0] << " puntos" << endl;
    cout << "  " << nombres[1] << ": " << puntos[1] << " puntos" << endl;
    cout << endl;

    cout << "          1      2      3      4      5"<< "       Cartas   Suma" << endl;

    for (int fila = 0; fila < 3; fila++) {

        cout << "Fila " << fila + 1 << ": ";

        int cantidad = 0;
        int suma = 0;

        for (int columna = 0; columna < 5; columna++) {

            if (cartas[fila][columna] == 0) {
                cout << "[   ] ";
            } else {
                mostrarCarta(cartas[fila][columna] - 1);
                cout << " ";
                cantidad++;
                // La suma se calculará cuando implementemos las jugadas y el valor de cada carta.
            }
        }

        cout << "    " << cantidad << "/5";
        cout << "       " << suma << endl;
    }

    cout << "===========================================================" << endl;

    cout << endl;
    cout << "Cartas robadas:" << endl;

    int carta1 = robarUna();
    int carta2 = robarUna();

    cout << "1) ";
    mostrarCarta(carta1);
    if (valorCarta(carta1) != 0) {
        cout << " vale " << valorCarta(carta1);
    }
    cout << endl;

    cout << "2) ";
    mostrarCarta(carta2);
    if (valorCarta(carta2) != 0) {
        cout << " vale " << valorCarta(carta2);
    }
    cout << endl;

  int eleccion;

    do {
        cout << "Carta a jugar (1 o 2): ";
        cin >> eleccion;
    } while (eleccion != 1 && eleccion != 2);

    int elegida;
    int sobrante;

    if (eleccion == 1) {
        elegida = carta1;
        sobrante = carta2;
    } else {
        elegida = carta2;
        sobrante = carta1;
    }

    // Por ahora, las cartas especiales no se pueden jugar.
    if (valorCarta(elegida) == 0) {
        cout << "El comodin se implementara en el siguiente paso."
             << endl;
        devolverCarta(carta1);
        devolverCarta(carta2);
        return 0;
    }

    if (paloCarta(elegida) == 'D') {
        cout << "Las jugadas de diamantes se implementaran despues."
             << endl;
        devolverCarta(carta1);
        devolverCarta(carta2);
        return 0;
    }

    int fila, columna;

    do {
        cout << "Fila (1-3): ";
        cin >> fila;
    } while (fila < 1 || fila > 3);

    do {
        cout << "Casillero (1-5): ";
        cin >> columna;
    } while (columna < 1 || columna > 5 ||
             cartas[fila - 1][columna - 1] != 0);

    cartas[fila - 1][columna - 1] = elegida + 1;
    int filaActual = fila - 1;
int cantidad = 0;

for (int c = 0; c < 5; c++) {
    if (cartas[filaActual][c] != 0) {
        cantidad++;
    }
}

if (cantidad == 5) {
    puntuacionFila(cartas, filaActual, puntos, 0);
}

    // La carta no elegida vuelve al mazo.
    devolverCarta(sobrante);

    cout << endl;
    cout << "Carta colocada correctamente." << endl;
    cout << "Cartas en el mazo: " << cartasRestantes() << endl;

    cout << endl;
    cout << "Tablero actualizado:" << endl;

   mostrarTablero(cartas) ;

    return 0;
}
