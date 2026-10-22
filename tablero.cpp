#include <iostream>
#include "jugadores.h"
#include "tablero.h"
#include "mazoPoker.h"
 using namespace std;
 float tablero(string nombres[2]);
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
                // La suma se calcular  cuando implementemos las jugadas y el valor de cada carta.
            }
        }

        cout << "    " << cantidad << "/5";
        cout << "       " << suma << endl;
    }

    cout << "===========================================================" << endl;

    return 0;
}
