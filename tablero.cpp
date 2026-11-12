#include "rlutil.h"
#include <iostream>
 using namespace std;
#include "jugadores.h"
#include "tablero.h"
#include "mazoPoker.h"
#include "puntuacionFila.h"
#include "turnos.h"
#include "guardarGanadores.h"
#include "comodin.h"

 //  muestra las cartas

// partida
void tablero(string nombres[2], int jugador, int cartas[3][5], int puntos[2], bool usadas[54]){

    cout << "==================== CRISIS DE LOS 40 ====================" << endl;
    cout << "Objetivo: 50 puntos || Cartas en el mazo: "<< cartasRestantes(usadas) << endl;
    cout << endl;

    cout << "  " << nombres[0] << ": " << puntos[0] << " puntos" << endl;
    cout << "  " << nombres[1] << ": " << puntos[1] << " puntos" << endl;
    cout << endl;

    cout << "          1     2     3     4     5"<< "      Cartas   Suma" << endl;

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
                suma+= valorCarta(cartas[fila][columna]-1);

            }
        }

        cout << "    " << cantidad << "/5";
        cout << "       " << suma << endl;
    }

    cout << "===========================================================" << endl;

    cout << endl;
    cout << "Cartas robadas:" << endl;

    int carta1 = robarUna(usadas);
    int carta2 = robarUna(usadas);

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

    // funcionalidad del comodin
    if (valorCarta(elegida) == 0) {
       if (tableroVacio(cartas)) {
        cout<<"el comodin no se puede jugar con el tablero vacio."<<endl;

        if (valorCarta(sobrante) == 0){
        //las dos son comodines no se juega ni aca
         cout<< "ambas cartas son comodines. Se pierde el turno." <<endl;
         devolverCarta(usadas, carta1);
         devolverCarta(usadas, carta2);
         return;
        }
        //jugamos con la otra cartita
        int aux = elegida;
        elegida = sobrante;
        sobrante = aux;
       } else{
        jugarComodin(cartas, puntos, jugador, usadas);
        //el comodiny la carta no elegida vuelven al mazo
        devolverCarta(usadas, elegida);
        devolverCarta(usadas, sobrante);
        rlutil::cls();
        cout<<"comodin jugado correctamente."<<endl;
        return;
       }
    }

   int fila, columna;

bool esDiamante = (paloCarta(elegida) == 'D');

do {
    cout << "Fila (1-3): ";
    cin >> fila;
} while (fila < 1 || fila > 3);

do {
    cout << "Casillero (1-5): ";
    cin >> columna;

    if (columna < 1 || columna > 5) {
        cout << "Casillero invalido." << endl;
    } else if (!esDiamante &&
               cartas[fila - 1][columna - 1] != 0) {
        cout << "Ese casillero esta ocupado." << endl;
    }

} while (columna < 1 || columna > 5 ||
         (!esDiamante && cartas[fila - 1][columna - 1] != 0));

int filaActual = fila - 1;
int columnaActual = columna - 1;

bool casilleroVacio = (cartas[filaActual][columnaActual] == 0);

if (!casilleroVacio) {
    int cartaReemplazada =
cartas[filaActual][columnaActual] - 1;

    devolverCarta(usadas, cartaReemplazada);

    cout << "Carta reemplazada: ";
    mostrarCarta(cartaReemplazada);
    cout << endl;
}

cartas[filaActual][columnaActual] = elegida + 1;

// Solo comprobamos si se completo la fila cuando colocamos una carta en un casillero vacio.

    int cantidad = 0;

    for (int c = 0; c < 5; c++) {
        if (cartas[filaActual][c] != 0) {
            cantidad++;
        }
    }

    if (cantidad == 5) {
        puntuacionFila(cartas, filaActual, puntos, jugador,usadas);
    cout << endl<<"presione una tecla para seguir..."<<endl;
    rlutil::anykey();
    }
    // La carta no elegida vuelve al mazo.
    devolverCarta(usadas, sobrante);

    rlutil::cls();
    cout << "Carta colocada correctamente." << endl;


    cout << endl;
    cout << "Tablero actualizado:" << endl;
   turno(jugador);

    return ;
}
